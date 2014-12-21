/**
* @file chistoxrange.cpp
* @brief CHistoXRange class implementation.
*/

#include "chistoxrange.h"

namespace chart {

void CHistoXRange::init(const IDataColumn *c, int bc)
{
    Q_ASSERT(c != 0);
    m_nBinCount = bc;
    double min = 50;
    double max = 1500;
    double av = (max - min)/bc;
    m_fBinSize = av;
}

int CHistoXRange::getSize() const
{
    return m_nBinCount;
}

QPair<double, double> CHistoXRange::getRange() const
{
    double x = m_fBinAnchor + 0.5 * m_fBinSize;
    double y = m_fBinAnchor + (m_nBinCount - 0.5) * m_fBinSize;
    return QPair<double, double>(x, y);
}

void CHistoXRange::getData(int row, double &val) const
{
    val = m_fBinAnchor + (row + 0.5) * m_fBinSize;
}

} // namespace chart
