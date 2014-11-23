/**
* @file cboxchart.cpp
* @brief CBoxChart class implementation.
*/

#include "../data/idatacolumn.h"
#include "cboxchart.h"

namespace chart {

CBoxChart::CBoxChart(const data::IDataColumn *oc)
    : IChart(oc)
{}

void CBoxChart::draw(QPaintDevice& pd)
{

}

CBoxChart::~CBoxChart()
{}

} // namespace chart
