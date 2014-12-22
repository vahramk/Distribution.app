/**
* @file cprobxrange.cpp
* @brief CProbXRange class implementation.
*/

#include <data/idatacolumn.h>
#include "cprobxrange.h"

namespace chart {

void CProbXRange::init(const data::IDataColumn *dc)
{
    Q_ASSERT(dc != 0);
    m_fMin = 45;
    m_fMax = 800;
    m_uSize = dc->getSize();
    const data::DataInterface* vp = dc->getDataBuffer();
    // waithing for CFunction class
}

size_t CProbXRange::getSize() const
{
    return m_uSize;
}

QPair<double, double> CProbXRange::getRange() const
{
    return QPair<double, double>(m_fMin, m_fMax);
}

void CProbXRange::getData(size_t row, double &val) const
{
    Q_ASSERT(row < m_vecData.size());
    val = m_vecData.at(row);
}

} // namespace chart
