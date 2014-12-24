/**
* @file cprobabilitychart.cpp
* @brief CProbabilityChart class implementation.
*/

#include <data/idatacolumn.h>
#include "cdataarea.h"
#include "cprobabilitychart.h"
#include "cprobseries.h"
#include "cprobxrange.h"
#include "cprobyrange.h"

#include <QPainter>
#include <QRectF>

namespace chart {

CProbabilityChart::CProbabilityChart(const data::IDataColumn *oc)
    : IChart(oc)
{}

QString CProbabilityChart::getName() const
{
    return "Probability";
}

void CProbabilityChart::draw(QPaintDevice &pd, const QRectF& r)
{
    CProbSeries* s = new CProbSeries();
    CProbXRange* x = new CProbXRange();
    CProbYRange* y = new CProbYRange();
    x->init(getColumn());
    y->init(getColumn());
    s->setX(x);
    s->setY(y);
    CDataArea* da = new CDataArea(r);
    QPair<double, double> xrange, yrange;
    xrange = x->getRange();
    yrange = y->getRange();
    da->init(QPointF(xrange.first, yrange.first), QPointF(xrange.second, yrange.second));
    QPainter* p = new QPainter(&pd);
    p->setPen(Qt::black);
    s->draw(p, da);
}

CProbabilityChart::~CProbabilityChart()
{}

} // namespace chart
