/**
* @file chistoseries.cpp
* @brief CHistoSeries class implementation.
*/

#include "cdataarea.h"
#include "chistoseries.h"
#include "chistoxrange.h"
#include "chistoyrange.h"

namespace chart {

CHistoSeries::CHistoSeries()
    : CSeries()
{
}

CHistoSeries::~CHistoSeries()
{
}

void CHistoSeries::draw(QPainter *p, CDataArea *d)
{
    Q_ASSERT(p != 0);
    Q_ASSERT(d != 0);

    IDataRange* x = getX();
    IDataRange* y = getY();
    Q_ASSERT(x != 0);
    Q_ASSERT(y != 0);

    QPair<double, double> xrange, yrange;
    xrange = x->getRange();
    yrange = y->getRange();
    d->init(QPoint(xrange.first, yrange.first), QPoint(xrange.second, yrange.second));
}

} // namespace chart
