/**
* @file chistoyrange.cpp
* @brief CHistoYRange class implementation.
*/

#include "chistoyrange.h"
#include <iostream>
namespace chart {

void CHistoYRange::init(const data::IDataColumn *c, int bc)
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
    QVector<int> h(bc);
    for(int m = 0; m < bc; ++m) {
        h[m] = 0;
    }
    double avmin = min;
    double avmax = min + av;
    std::cout<<"av= "<<av<<std::endl;
    for(int i = 0; i < bc; ++i) {
        for (int j = 0; j < c->getSize(); ++j) {
            double k = 0;
            c->getData(j, k);
            if (avmin >= k && k < avmax) {
                ++h[i];
            }
        }
        avmin += av;
        avmax += av;
    }
    m_vecBins = h;
}

void CHistoYRange::getData(int row, double &val) const
{
    Q_ASSERT(row < m_vecBins.size());
    val = m_vecBins[row];
}

QPair<double, double> CHistoYRange::getRange() const
{
    double m = m_vecBins[0];
    double mi = m_vecBins[0];
    for(int i = 1 ; i < m_vecBins.size(); ++i) {
        if (m < m_vecBins[i]) {
            m = m_vecBins[i];
        } else if (mi > m_vecBins[i]) {
            mi = m_vecBins[i];
        }
    }
    return QPair<double, double>(mi, m);
}

int CHistoYRange::getSize() const
{
    return m_nBinCount;
}

}
