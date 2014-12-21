/**
* @file chistoyrange.cpp
* @brief CHistoYRange class implementation.
*/

#include "chistoyrange.h"

namespace chart {

void CHistoYRange::init(const data::IDataColumn *c, int bc)
{
    Q_ASSERT(c != 0);
    m_nBinCount = bc;
    double min = 50;
    double max = 1500;
    double av = (max - min)/bc;
    QVector<int> h(bc);
    for(int m = 0; m < bc; ++m) {
        h[m] = 0;
    }
    double avmin = 0;
    double avmax = av;
    for(int i = 0; i < bc; ++i) {
        for (int j = 0; j < c->getSize(); ++j) {
            double k ;
            c->getData(j, k);
            if (avmin > k && k < avmax) {
                ++h[i];
            }
        }
        avmin = avmax;
        avmax += av;
    }
    m_vecBins = h;
}

void CHistoYRange::getData(int row, double &val) const
{
    val = m_vecBins[row];
}

QPair<double, double> CHistoYRange::getRange() const
{
    double m = m_vecBins[0];
    for(int i = 1 ; i < m_vecBins.size(); ++i) {
        if (m < m_vecBins[i]) {
            m = m_vecBins[i];
        }
    }
    return QPair<double, double>(0, m);
}

int CHistoYRange::getSize() const
{
    return m_nBinCount;
}

}
