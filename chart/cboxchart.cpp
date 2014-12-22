/**
* @file cboxchart.cpp
* @brief CBoxChart class implementation.
*/

#include <data/idatacolumn.h>
#include "cboxchart.h"

#include <QRect>

namespace chart {

CBoxChart::CBoxChart(const data::IDataColumn *oc)
    : IChart(oc)
{}

void CBoxChart::draw(QPaintDevice& pd, const QRect& r)
{

}

CBoxChart::~CBoxChart()
{}

} // namespace chart
