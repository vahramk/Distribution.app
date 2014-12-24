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
#include <QRectF>

namespace chart {

CHistogramChart::CHistogramChart(const data::IDataColumn *oc)
    : IChart(oc)
{}

QString CHistogramChart::getName() const
{
    return "Histogram";
}

void CHistogramChart::draw(QPaintDevice& pd, const QRectF& r)
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
//    pen->setBrush(QBrush(Qt::green, Qt::SolidPattern));
    p->setPen(*pen);
    p->drawRect(r);
    p->translate(r.x(), r.y());
    s->draw(p, da);
//    p->drawLine(da->translate(QPointF(0.5, 0.5)), da->translate(QPointF(1, 1)));
}

CHistogramChart::~CHistogramChart()
{}

} // namespace chart
