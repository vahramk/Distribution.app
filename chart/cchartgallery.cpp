/**
* @file cchartgallery.cpp
* @brief CChartGallery class implementation.
*/

#include <data/idatacolumn.h>
#include "cchartgallery.h"
#include "cchart.h"

namespace chart {

void CChartGallery::addChart(CChart* oc)
{
    Q_ASSERT(oc != 0);
    m_charts.push_back(oc);
}

CChart* CChartGallery::getChart(t_index i)
{
    Q_ASSERT(i < static_cast<t_index>(m_charts.size()));
    return m_charts.at(i);
}

QPixmap CChartGallery::getPixmap(t_index ui, QSize os)
{
    Q_ASSERT(ui < static_cast<t_index>(m_charts.size()));
    Q_ASSERT(!os.isNull());
    CChart* ptrc = m_charts.at(ui);
    Q_ASSERT(ptrc != 0);
    if (m_chash[ptrc].size() == os) {
        return m_chash[ptrc];
    }
    QPixmap op(os);
    ptrc->draw(op, QRect(QPoint(0, 0), os));
    m_chash[ptrc] = op;
    return op;
}

CChartGallery::~CChartGallery()
{
    m_charts.clear();
    m_chash.clear();
}

} // namespace chart
