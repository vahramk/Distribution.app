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
#include "caxisx.h"
#include "caxisy.h"

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
    QRectF pr(r.x() + getXMargin(), r.y() + getYMargin(),
              r.width() - 2 * getXMargin(), r.height() - 2 * getYMargin());
    CDataArea* da = new CDataArea(pr);
    QPainter* p = new QPainter(&pd);
    QPen* pen = new QPen(Qt::black);
    p->setPen(*pen);
    p->drawRect(r);
    p->translate(pr.x(), pr.y() + pr.height());
    s->draw(p, da);
    delete p;
    CAxisX* xa = new CAxisX;
    CAxisY* ya = new CAxisY;
    xa->draw(pd, r);
    ya->draw(pd, r);
    delete x;
    delete y;
    delete s;
}

CHistogramChart::~CHistogramChart()
{}

} // namespace chart
