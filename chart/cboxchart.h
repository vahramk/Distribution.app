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
     * @brief Paint chart on given pixmap
     * @param[out] op reference to pixmap
     */
    virtual void paint(QPixmap &op);

public:
    /**
     * @brief destructor
     */
    virtual ~CBoxChart();
};

} // namespace chart

#endif // CBOXCHART_H
