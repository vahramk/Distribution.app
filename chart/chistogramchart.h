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
     * @brief draw chart on given paint device
     * @param[in] pd reference to paint device
     * @param[in] r reference to rect
     */
    virtual void draw(QPaintDevice& pd, const QRect& r);

public:
    /**
     * @brief destructor
     */
    virtual ~CHistogramChart();
};

} // namespace chart

#endif // CHISTOGRAMCHART_H
