/**
* @file cdataarea.cpp
* @brief CDataArea class implementation.
*/

#include "cdataarea.h"

namespace chart {

CDataArea::CDataArea(const QRectF& sc)
{
    m_oscreenrect = sc;
}

void CDataArea::init(const QPointF &tl, const QPointF &br)
{
    m_odatarect = QRectF(tl, br);
}

QPointF CDataArea::translate(const QPointF &p)
{
    double x = m_oscreenrect.x() * p.x() / m_odatarect.x();
    double y = m_oscreenrect.y() * p.y() / m_odatarect.y();
    return QPointF(x, y);
}

void CDataArea::rescale(const QRectF &sc)
{
    m_oscreenrect = sc;
}

} // namespace chart
