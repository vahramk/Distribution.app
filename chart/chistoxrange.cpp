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
    c->getData(0, min);
    double max = 1;
    c->getData(0, max);
    for (int i = 1; i <c->getSize(); ++i) {
        double v = 0;
        c->getData(i, v);
        if (v > max) {
            max = v;
        } else if (v < min) {
            min = v;
        }
    }
    double av = (max - min)/bc;
    m_fBinSize = av;
    m_fBinAnchor = 0;
    m_fMax = max;
    m_fMin = min;
}

int CHistoXRange::getSize() const
{
    return m_nBinCount;
}

QPair<double, double> CHistoXRange::getRange() const
{
    return QPair<double, double>(m_fMin, m_fMax);
}

void CHistoXRange::getData(int row, double &val) const
{
    val = m_fBinAnchor + (row + 0.5) * m_fBinSize;
}

} // namespace chart
