#ifndef CCHARTGALLERY_H
#define CCHARTGALLERY_H

/**
* @file cchartgallery.h
* @brief CChartGallery class interface.
*/

#include <QHash>
#include <QList>
#include <QPixmap>

namespace chart {

class CChart;

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
    void addChart(CChart* oc);

public:
    /**
     * @brief Return painted pixmap using
     * given chart
     * @param[in] ui chart index
     * @param[in] os size for pixmap
     * @return QPixmap which containes painted chart
     */
    QPixmap getPixmap(t_index ui, QSize os);

public:
    /**
     * @brief destructer will delete all charts
     */
    virtual ~CChartGallery();

private:
    typedef QList<CChart*> t_listcharts;
    t_listcharts m_charts;
    typedef QHash<CChart*, QPixmap> t_hashchash;
    t_hashchash m_chash;

};

} // namespace chart

#endif // CCHARTGALLERY_H
