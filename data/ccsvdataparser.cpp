/** 
* @file ccsvdataparser.cpp
* @brief Implementation of CSV Data parser for the Data Parser.
*
*/

#include "ccsvdataparser.h"
#include "datautility.h"
#include "cdatacolumn.h"
#include "cdatatable.h"

#include <string>
#include <fstream>

namespace data
{
	CCSVParser::CCSVParser(const std::string& file_name)
		:m_path(file_name), m_table(new CDataTable)
	{}

	IDataTable* CCSVParser::parse()
	{
		std::ifstream in(m_path.c_str());
		if (!in.is_open()) return 0;

		std::vector<std::string> vheader;
		std::vector<std::string> vdata;
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
			const std::string& name = vheader[i];
			EDataType type = get_type(vdata[i]);//get type of the column
			c = new CDataColumn(name, type);
			addValueToColumn(c, vdata[i]);
			m_table->addDataColumn(c);
		}

		while (getline(in, line))
		{
			tokenize_line(line, vdata);
			size_t c = m_table->getColumnCount();
			for(int i=0; i<c; ++i)
			{
				addValueToTable(m_table, i, vdata[i]);
			}
		}
		return m_table;
	}

	EDataType CCSVParser::get_type(const std::string& value) const
	{
		EDataType t;
		int dc = 0;
		int i = 0;
		for(; i<value.size(); ++i)
		{
			if(value[i] == '.')
			{
				++dc;
			}
			if(value[i] == ':') 
			{
				t = EDataType::DateTime;
				return t;
			}
			if((65<=value[i] && value[i]<=90)||(97<=value[i] && value[i]<=122))
			{
				t = EDataType::String;
				return t;
			}
		}
		if(dc == 1)
		{
			t = EDataType::Double;
		} else {
			t = EDataType::Int;	
		}
		return t;
	}

	void CCSVParser::tokenize_line(const Tockenizer& line, std::vector<std::string>& vdata) const
	{
		while(line.operator ++())
		{
			vdata.push_back(std::string(line, line.start(), line.end() - line.start()));
		}
		line.reset_parser();
	}

	void CCSVParser::addValueToColumn(CDataColumn* c, const std::string& value)
	{
		switch(c->getType()) {
		case String:
			c->addValue(value);
			break;
		case DateTime:
			{
				struct tm dt;
				fromStringToTime(value, dt);
				c->addValue(dt);
				break;
			}
		case Int:
			{
				c->addValue(fromString<int>(value));
				break;
			}
		case Double:
			{
				c->addValue(fromString<double>(value));
				break;
			}
		default:
			assert(false);
			break;
		}
	}

	void CCSVParser::addValueToTable(CDataTable* t, size_t i, const std::string& value)
	{
		switch(t->getColumn(i)->getType()) {
		case String:
			t->addCell(i, value);
			break;
		case DateTime:
			{
				struct tm dt;
				fromStringToTime(value, dt);
				t->addCell(i, dt);
				break;
			}
		case Int:
			{
				t->addCell(i, fromString<int>(value));
				break;
			}
		case Double:
			{
				t->addCell(i, fromString<double>(value));
				break;
			}
		default:
			assert(false);
			break;
		}	
	}

} //namespace data