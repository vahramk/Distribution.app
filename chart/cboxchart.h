/**
* @file cboxchart.h
* @brief CBoxChart class interface.
*/

#ifndef CBOXCHART_H
#define CBOXCHART_H

#include "ichart.h"

namespace chart {

class CBoxChart : public IChart
{
public:
    /**
     * @brief Constructer for box chart
     * @param[in] oc column for which chart
     * will be created
     * @note oc != 0
     */
    CBoxChart(const data::IDataColumn * oc);

public:
    /**
     * @brief draw chart on given paint device
     * @param[out] pd reference to paint device
     */
    virtual void draw(QPaintDevice& pd);

public:
    /**
     * @brief destructor
     */
    virtual ~CBoxChart();
};

} // namespace chart

#endif // CBOXCHART_H
