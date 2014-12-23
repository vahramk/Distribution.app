/** 
* @file ccsvdataparser.cpp
* @brief Implementation of CSV Data parser for the Data Parser.
*
*/

#include "ccsvdataparser.h"
#include "cdatacolumn.h"
#include "cdatatable.h"

#include <QString>
#include <fstream>
#include <cassert>
#include <iostream>

namespace data
{
CCSVParser::CCSVParser(const QString& file_name)
        :m_path(file_name), m_table(new CDataTable)
{}

IDataTable* CCSVParser::parse()
{
    std::ifstream in(m_path.toStdString().c_str());
    if (!in.is_open()) return 0;

    QVector<QString> vheader;
    QVector<QString> vdata;
    Tockenizer line;

    int i = 2;//read first 2 lines
    while (i-- && getline(in, line))
    {
        if(i == 1) {
            tokenize_line(line, vheader);
            continue;
        }
        tokenize_line(line, vdata);
    }

    assert(vheader.size() == vdata.size());

    CDataColumn* c;
    for(int i=0; i<vdata.size(); ++i)
    {
        const QString& name = vheader[i];
        EDataType type = get_type(vdata[i]);//get type of the column
        c = new CDataColumn(name, type);
        addValueToColumn(c, vdata[i]);
        m_table->addDataColumn(c);
    }
    while (getline(in, line))
    {
        tokenize_line(line, vdata);
        int c = m_table->getColumnCount();
        for(int i=0; i<c; ++i)
        {
            addValueToTable(m_table, i, vdata[i]);
        }
    }
    return m_table;
}

EDataType CCSVParser::get_type(const QString& value) const
{
    EDataType t;
    int dc = 0;
    for(int i=0; i<value.size(); ++i)
    {
        if(value[i] == '.')
        {
            ++dc;
        }
        if(value[i] == ':')
        {
            t = DateTime;
            return t;
        }
        if((65<=value[i] && value[i]<=90)||(97<=value[i] && value[i]<=122))
        {
            t = String;
            return t;
        }
    }
    if(dc == 1)
    {
        t = Double;
    } else {
        t = Int;
    }
    return t;
}

void CCSVParser::tokenize_line(const Tockenizer& line, QVector<QString>& vdata) const
{
    vdata.clear();
    while(line.operator ++())
    {
        vdata.push_back(QString(std::string(line, line.start(), line.end() - line.start()).c_str()));
    }
    line.reset_parser();
}

void CCSVParser::addValueToColumn(CDataColumn* c, const QString& value)
{
    switch(c->getType()) {
    case String:
        c->addValue(value);
        break;
    case DateTime:
    {
        struct tm dt;
        fromStringToTime(value.toStdString(), dt);
        c->addValue(dt);
        break;
    }
    case Int:
    {
        c->addValue(fromString<int>(value.toStdString()));
        break;
    }
    case Double:
    {
        c->addValue(fromString<double>(value.toStdString()));
        break;
    }
    default:
        assert(false);
        break;
    }
}

void CCSVParser::addValueToTable(CDataTable* t, int i, const QString& value)
{
    switch(t->getColumn(i)->getType()) {
    case String:
        t->addCell(i, value);
        break;
    case DateTime:
    {
        struct tm dt;
        fromStringToTime(value.toStdString(), dt);
        t->addCell(i, dt);
        break;
    }
    case Int:
    {
        t->addCell(i, fromString<int>(value.toStdString()));
        break;
    }
    case Double:
    {
        t->addCell(i, fromString<double>(value.toStdString()));
        break;
    }
    default:
        assert(false);
        break;
    }
}

CCSVParser::~CCSVParser()
{
    delete m_table;
}

} //namespace data
