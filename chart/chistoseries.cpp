/**
* @file chistoseries.cpp
* @brief CHistoSeries class implementation.
*/

#include "cdataarea.h"
#include "chistoseries.h"
#include "chistoxrange.h"
#include "chistoyrange.h"

#include <QPainter>
#include <iostream>

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

    QPen *e = new QPen;
    e->setColor(Qt::green);
    p->setBrush(QBrush(Qt::yellow, Qt::Dense3Pattern));
    p->setPen(*e);

    QPair<double, double> xrange, yrange;
    xrange = x->getRange();
    yrange = y->getRange();
    d->init(QPointF(xrange.first, yrange.first), QPointF(xrange.second, yrange.second));
    std::cout<<"RANGE"<<std::endl;
        std::cout<<xrange.first<<"          "<<yrange.second<<std::endl;
        std::cout<<xrange.second<<"          "<<yrange.first<<std::endl;
    for (size_t i = 0; i < xsize; ++i) {
        double yval = 0;
        y->getData(i, yval);
        Q_ASSERT(yval <= yrange.second);
        Q_ASSERT(yval >= yrange.first);
        double xval = 0;
        x->getData(i, xval);
        Q_ASSERT(xval <= xrange.second);
//        Q_ASSERT(xval >= xrange.first);
        std::cout<<xval<<" "<<yval<<std::endl;
        QPointF topleft(xval - (binsize / 2), yval);
        QPointF bottomright(xval + (binsize / 2), 0);
        std::cout<<topleft.x()<<"          "<<topleft.y()<<std::endl;
        std::cout<<bottomright.x()<<"          "<<bottomright.y()<<std::endl;
        QPointF tr_topleft = d->translate(topleft);
        QPointF tr_bottomright = d->translate(bottomright);
        std::cout<<tr_topleft.x()<<"          "<<tr_topleft.y()<<std::endl;
        std::cout<<tr_bottomright.x()<<"          "<<tr_bottomright.y()<<std::endl;
        p->drawRect(QRectF(tr_topleft, tr_bottomright));
    }
}

} // namespace chart
