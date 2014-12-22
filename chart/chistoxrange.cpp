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
    double min = 0;
    double max = 7;
    double av = (max - min)/bc;
    m_fBinSize = av;
    m_fBinAnchor = min;
}

int CHistoXRange::getSize() const
{
    return m_nBinCount;
}

QPair<double, double> CHistoXRange::getRange() const
{
    double min =0;
    double max = 7;
    return QPair<double, double>(min, max);
}

void CHistoXRange::getData(int row, double &val) const
{
    val = m_fBinAnchor + (row + 0.5) * m_fBinSize;
}

} // namespace chart
