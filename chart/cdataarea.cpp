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
    Q_ASSERT(m_oscreenrect.width() > 0);
    Q_ASSERT(m_oscreenrect.height() > 0);
    Q_ASSERT(m_odatarect.width() > 0);
    Q_ASSERT(m_odatarect.height() > 0);
    double x = m_oscreenrect.width() * p.x() / m_odatarect.width();
    double y = m_oscreenrect.height() * p.y() / m_odatarect.height();
    return QPointF(x, y);
}

void CDataArea::rescale(const QRectF &sc)
{
    m_oscreenrect = sc;
}

} // namespace chart
