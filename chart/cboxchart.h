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
     * @brief gets chart name
     * @return name
     */
    virtual QString getName() const;

public:
    /**
     * @brief draw chart on given paint device
     * @param[in] pd reference to paint device
     * @param[in] r reference to rect
     */
    virtual void draw(QPaintDevice& pd, const QRectF& r);

public:
    /**
     * @brief destructor
     */
    virtual ~CBoxChart();
};

} // namespace chart

#endif // CBOXCHART_H
