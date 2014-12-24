/**
* @file caxisy.cpp
* @brief CAxisY class implementation.
*/

#include "caxisy.h"
#include <QPainter>

namespace chart {

CAxisY::CAxisY()
    : CAxis()
{
}

void CAxisY::draw(QPaintDevice &pd, const QRectF &r)
{
    QPainter* p = new QPainter(&pd);
    QPen* pen = new QPen(Qt::black);
    p->setPen(*pen);
    p->translate(r.x(), r.y() + r.height());
    const int ym = getYMargin();
    const int xm = getXMargin();
    p->drawLine(QPoint(xm, -ym), QPoint(xm, ym - r.height()));
    delete p;
}

} // namespace chart
