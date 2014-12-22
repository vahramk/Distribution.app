/**
* @file cprobyrange.cpp
* @brief CProbYRange class implementation.
*/

#include <data/idatacolumn.h>
#include "cprobyrange.h"

namespace chart {

void CProbYRange::init(const data::IDataColumn *dc)
{
    Q_ASSERT(dc != 0);
    m_uSize = dc->getSize();
}

int CProbYRange::getSize() const
{
    return m_uSize;
}

QPair<double, double> CProbYRange::getRange() const
{
    return QPair<double, double>(0, 1);
}

void CProbYRange::getData(int row, double &val) const
{
    val = (row + 1) / m_uSize;
}

} // namespace chart
