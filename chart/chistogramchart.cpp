/**
* @file chistogramchart.cpp
* @brief CHistogramChart class implementation.
*/

#include <data/idatacolumn.h>
#include "cdataarea.h"
#include "chistogramchart.h"
#include "chistoseries.h"
#include "chistoxrange.h"
#include "chistoyrange.h"

#include <QPainter>
#include <QPen>
#include <QRect>

namespace chart {

CHistogramChart::CHistogramChart(const data::IDataColumn *oc)
    : IChart(oc)
{}

void CHistogramChart::draw(QPaintDevice& pd, const QRect& r)
{
    CHistoSeries* s = new CHistoSeries();
    CHistoXRange* x = new CHistoXRange();
    CHistoYRange* y = new CHistoYRange();
    x->init(getColumn(), 5);
    y->init(getColumn(), 5);
    s->setX(x);
    s->setY(y);
    CDataArea* da = new CDataArea(r);
    QPainter* p = new QPainter(&pd);
    QPen* pen = new QPen(Qt::red);
    pen->setBrush(Qt::Dense5Pattern);
    p->setPen(Qt::red);
    s->draw(p, da);
}

CHistogramChart::~CHistogramChart()
{}

} // namespace chart
