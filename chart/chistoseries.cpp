/**
* @file chistoseries.cpp
* @brief CHistoSeries class implementation.
*/

#include "cdataarea.h"
#include "chistoseries.h"
#include "chistoxrange.h"
#include "chistoyrange.h"

#include <QPainter>

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

    const IDataRange* x = getX();
    const IDataRange* y = getY();
    Q_ASSERT(x != 0);
    Q_ASSERT(y != 0);

    size_t xsize = x->getSize();
    size_t ysize = y->getSize();
    Q_ASSERT(xsize == ysize);
    double x1 = 0, x2 = 0;
    x->getData(0, x1);
    x->getData(1, x2);
    double binsize = x2 - x1;

    QPair<double, double> xrange, yrange;
    xrange = x->getRange();
    yrange = y->getRange();
    d->init(QPoint(xrange.first, yrange.second), QPoint(xrange.second, yrange.first));
    for (size_t i = 0; i < xsize; ++i) {
        double yval = 0;
        y->getData(i, yval);
        double xval = 0;
        x->getData(i, xval);
        QPoint topleft(xval - (binsize / 2), yval);
        QPoint bottomright(xval + (binsize / 2), 0);
        p->drawRect(QRectF(d->translate(topleft), d->translate(bottomright)));
    }
}

} // namespace chart
