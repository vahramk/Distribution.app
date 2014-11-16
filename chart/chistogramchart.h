/**
* @file chistogramchart.h
* @brief CHistogramChart class interface.
*/

#ifndef CHISTOGRAMCHART_H
#define CHISTOGRAMCHART_H

#include "ichart.h"

namespace chart {

class CHistogramChart : public IChart
{
public:
    /**
     * @brief Constructer for histogram chart
     * @param[in] oc column for which chart
     * will be created
     * @note oc != 0
     */
    CHistogramChart(const data::IDataColumn * oc);

public:
    /**
     * @brief Paint chart on given pixmap
     * @param[out] op reference to pixmap
     */
    virtual void paint(QPixmap &op);

public:
    /**
     * @brief destructor
     */
    virtual ~CHistogramChart();
};

} // namespace chart

#endif // CHISTOGRAMCHART_H
