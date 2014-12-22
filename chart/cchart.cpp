/**
* @file cchart.cpp
* @brief CChart class implementation
*/

#include "cchart.h"
#include "cboxchart.h"
#include "chistogramchart.h"
#include "cprobabilitychart.h"

namespace chart {

CChart::CChart()
    : m_data(0)
{
}

CChart::CChart(const CChart& c)
{
    m_data = c.m_data;
}

CChart& CChart::operator=(const CChart& c)
{
    if (&c == this) {
        return *this;
    }
    m_data = c.m_data;
    return *this;
}

bool CChart::isBuild() const
{
    return m_data.data() != 0;
}

void CChart::makeForBoxChart(const data::IDataColumn *c)
{
    if (isBuild()) {
        delete m_data.data();
        m_data = 0;
    }
    Q_ASSERT(!isBuild());
    m_data = new CBoxChart(c);
}

void CChart::makeForHistogramChart(const data::IDataColumn *c)
{
    if (isBuild()) {
        delete m_data.data();
        m_data = 0;
    }
    Q_ASSERT(!isBuild());
    m_data = new CHistogramChart(c);
}

void CChart::makeForProbabilityChart(const data::IDataColumn *c)
{
    if (isBuild()) {
        delete m_data.data();
        m_data = 0;
    }
    Q_ASSERT(!isBuild());
    m_data = new CProbabilityChart(c);
}

void CChart::draw(QPaintDevice &d, const QRect& r)
{
    Q_ASSERT(isBuild());
    m_data->draw(d, r);
}

} // namespace chart
