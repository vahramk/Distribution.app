/**
* @file cprobseries.cpp
* @brief CProbSeries class implementation.
*/

#include "cprobseries.h"
#include "idatarange.h"

#include <QPainter>

namespace chart {

CProbSeries::CProbSeries()
    : CSeries()
{
}

CProbSeries::~CProbSeries()
{
}

void CProbSeries::draw(QPainter *p, CDataArea *d)
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
    for (size_t i = 0; i < xsize; ++i) {
        double xv = 0, yv = 0;
        x->getData(i, xv);
        y->getData(i, yv);
        p->drawPoint(QPointF(xv, yv));
    }
}

} // namespace chart
