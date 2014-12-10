/**
* @file cseries.cpp
* @brief CSeries class implementation.
*/

#include "cseries.h"
#include "idatarange.h"

namespace chart {

CSeries::CSeries()
    : m_oxRange(0)
    , m_oyRange(0)
{
}

CSeries::~CSeries()
{
}

void CSeries::setX(IDataRange *xr)
{
    Q_ASSERT(xr != 0);
    m_oxRange = xr;
}

void CSeries::setY(IDataRange *yr)
{
    Q_ASSERT(yr != 0);
    m_oyRange = yr;
}

IDataRange* CSeries::getX()
{
    return m_oxRange;
}

IDataRange* CSeries::getY()
{
    return m_oyRange;
}

} // namespace chart
