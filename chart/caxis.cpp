/**
* @file caxis.cpp
* @brief CAxis class implementation.
*/

#include "caxis.h"

namespace chart {

CAxis::CAxis()
    : IDrawable()
    , m_pData(0)
{
}

void CAxis::setRange(IDataRange *dr)
{
    Q_ASSERT(dr != 0);
    m_pData = dr;
}

const IDataRange* CAxis::getRange() const
{
    return m_pData;
}

} // namespace chart
