/**
* @file capplication.cpp
* @brief CApplication class implementation.
*/

#include <data/cdataparser.h>
#include <data/idatatable.h>
#include "capplication.h"
#include "cmodule.h"

#include <QStringList>

namespace core {

CApplication::CApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    m_pModule = new CModule(this);
}

bool CApplication::openFile(QString const& sPath)
{
    data::CCSVParser oParser( sPath );
    data::IDataTable* pTable = oParser.parse();
    if (pTable != NULL) {
        Q_ASSERT(0 != m_pModule);
        m_pModule->setData(pTable);
    } else {
        return false;
    }
    return true;
}

QStringList CApplication::getAvailableParameters() const
{
    QStringList aNames;
    if (m_pModule != NULL) {
//        aNames = m_pModule->getAvailableParameters();
    }
    return aNames;
}

bool CApplication::run(QStringList const& aSelectedParameters, QString& pErrorMsg)
{
    try
    {
        if (m_pModule != NULL) {
//            m_pModule->run(aSelectedParameters);
        } else {
            throw QString("Unexpected error: module pointer should not be NULL");
        }
    }
    catch (QString const& sErrMsg)
    {
        pErrorMsg = sErrMsg;
//		throw AppException ...
    }
    return true; // need to be changed
}

} // namespace core
