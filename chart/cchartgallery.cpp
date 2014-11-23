/**
* @file cchartgallery.cpp
* @brief CChartGallery class implementation.
*/

#include "../data/idatacolumn.h"
#include "cchartgallery.h"
#include "ichart.h"

namespace chart {

void CChartGallery::addChart(IChart *oc)
{
    Q_ASSERT(oc != 0);
    m_charts.push_back(oc);
}

QPixmap CChartGallery::getPixmap(t_index ui, QSize os)
{
    Q_ASSERT(ui < static_cast<t_index>(m_charts.size()));
    Q_ASSERT(!os.isNull());
    IChart* ptrc = m_charts.at(ui);
    Q_ASSERT(ptrc != 0);
    if (m_chash[ptrc].size() == os) {
        return m_chash[ptrc];
    }
    QPixmap op(os);
    ptrc->draw(op);
    m_chash[ptrc] = op;
    return op;
}

CChartGallery::~CChartGallery()
{
    for (t_listcharts::iterator i = m_charts.begin(); i != m_charts.end(); ++i) {
        Q_ASSERT(*i != 0);
        delete *i;
    }
    m_charts.clear();
    m_chash.clear();
}

} // namespace chart
