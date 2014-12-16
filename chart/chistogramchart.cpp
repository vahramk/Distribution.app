/**
* @file chistogramchart.cpp
* @brief CHistogramChart class implementation.
*/

#include "../data/idatacolumn.h"
#include "cdataarea.h"
#include "chistogramchart.h"
#include "chistoseries.h"
#include "chistoxrange.h"
#include "chistoyrange.h"

#include <QPainter>

namespace chart {

CHistogramChart::CHistogramChart(const data::IDataColumn *oc)
    : IChart(oc)
{}

void CHistogramChart::draw(QPaintDevice& pd)
{
    CHistoSeries* s = new CHistoSeries();
    CHistoXRange* x = new CHistoXRange();
    CHistoYRange* y = new CHistoYRange();
    x->init(getColumn(), 10);
    x->init(getColumn(), 10);
    s->setX(x);
    s->setY(y);
    CDataArea* da = new CDataArea(QRect());
    QPair<double, double> xrange, yrange;
    xrange = x->getRange();
    yrange = y->getRange();
    da->init(QPointF(xrange.first, yrange.first), QPointF(xrange.second, yrange.second));
    QPainter* p = new QPainter(&pd);
    s->draw(p, da);
}

CHistogramChart::~CHistogramChart()
{}

} // namespace chart
