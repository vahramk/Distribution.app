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

void CBoxChart::paint(QPixmap &op)
{

}

CBoxChart::~CBoxChart()
{}

} // namespace chart
