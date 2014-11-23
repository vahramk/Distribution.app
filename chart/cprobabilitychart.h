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
     * @brief draw chart on given paint device
     * @param[out] pd reference to paint device
     */
    virtual void draw(QPaintDevice& pd);

public:
    /**
     * @brief destructor
     */
    virtual ~CProbabilityChart();
};

} // namespace chart

#endif // CPROBABILITYCHART_H
