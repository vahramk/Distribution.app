#ifndef CDATAAREA_H
#define CDATAAREA_H

/**
* @file cdataarea.h
* @brief CDataArea class interface.
*/

#include <QPointF>
#include <QRectF>

namespace chart {

class CDataArea
{
public:
    /**
     * @brief constracter for given screen
     * @param[in] sc rect of given screen
     */
    CDataArea(const QRectF& sc);

public:
    /**
     * @brief initialize data area
     * @param[in] tl top left point of the rect
     * @param[in] br bottom right point of the rect
     */
    void init(const QPointF& tl, const QPointF& br);

public:
    /**
     * @brief translate given point from data area to paint devise
     * @param[in] p point in data area
     * @return translated point
     */
    QPointF translate(const QPointF& p);

public:
    /**
     * @brief rescale to given screen
     * @param[in] sc new screen
     */
    void rescale(const QRectF& sc);

private:
    QRectF m_odatarect;
    QRectF m_oscreenrect;
};

} // namespace chart

#endif // CDATAAREA_H
