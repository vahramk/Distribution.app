/**
* @file chistogramchart.cpp
* @brief CHistogramChart class implementation.
*/

#include "../data/idatacolumn.h"
#include "chistogramchart.h"

namespace chart {

CHistogramChart::CHistogramChart(const data::IDataColumn *oc)
    : IChart(oc)
{}

void CHistogramChart::draw(QPaintDevice &pd)
{

}

CHistogramChart::~CHistogramChart()
{}

} // namespace chart
