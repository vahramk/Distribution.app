/**
* @file cprobabilitychart.h
* @brief CProbabilityChart class interface.
*/

#ifndef CPROBABILITYCHART_H
#define CPROBABILITYCHART_H

#include "ichart.h"

namespace chart {

class CProbabilityChart : public IChart
{
public:
    /**
     * @brief Constructer for probability chart
     * @param[in] oc column for which chart
     * will be created
     * @note oc != 0
     */
    CProbabilityChart(const data::IDataColumn * oc);

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
    virtual void draw(QPaintDevice& pd, const QRectF &r);

public:
    /**
     * @brief destructor
     */
    virtual ~CProbabilityChart();
};

} // namespace chart

#endif // CPROBABILITYCHART_H
