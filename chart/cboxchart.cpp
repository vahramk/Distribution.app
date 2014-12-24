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

void CBoxChart::draw(QPaintDevice& pd, const QRectF& r)
{

}

QString CBoxChart::getName() const
{
    return "Box";
}

CBoxChart::~CBoxChart()
{}

} // namespace chart
