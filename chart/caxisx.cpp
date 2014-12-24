/**
* @file caxisx.cpp
* @brief CAxisX class implementation.
*/

#include "caxisx.h"
#include <QPainter>

namespace chart {

CAxisX::CAxisX()
    : CAxis()
{
}

void CAxisX::draw(QPaintDevice &pd, const QRectF &r)
{
    QPainter* p = new QPainter(&pd);
    QPen* pen = new QPen(Qt::black);
    p->setPen(*pen);
    p->translate(r.x(), r.y() + r.height());
    const int xm = getXMargin();
    const int ym = getYMargin();
    p->drawLine(QPoint(xm, -ym), QPoint(-ym + r.width(), -ym));
    delete p;
}

} // namespace chart
