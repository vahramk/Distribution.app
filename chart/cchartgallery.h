/**
* @file cchartgallery.h
* @brief CChartGallery class interface.
**/

#ifndef CCHARTGALLERY_H
#define CCHARTGALLERY_H

#include <QList>
#include <QPixmap>

namespace chart {

class IChart;

class CChartGallery
{
public:
    /**
     * @brief public typedefs
     */
    typedef unsigned t_index;
public:
    /**
     * @brief Interface for adding Charts to
     * the gallery
     * @param[in] oc chart which should be added
     * @note oc != 0
     */
    void addChart(IChart* oc);

public:
    /**
     * @brief Return painted pixmap using
     * given chart
     * @param[in] ui chart index
     * @param[in] os size for pixmap
     * @return QPixmap which containes painted chart
     */
    QPixmap getPixmap(t_index ui, QSize os);

private:
    typedef QList<IChart*> t_listcharts;
    t_listcharts m_charts;
};

} // namespace chart

#endif // CCHARTGALLERY_H
