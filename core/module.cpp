/**
* @file module.cpp
* @brief CModule class implementation.
*/

#include <data/idatatable.h>
#include "module.h"

namespace core
{

CModule::CModule(QObject *parent)
    : QObject(parent)
    , m_pInputData(NULL)
{
}

void CModule::setData(data::IDataTable* pTdata)
{
    Q_ASSERT(0 != pTdata);
    m_pInputData = pTdata;
}

} //namespace core
