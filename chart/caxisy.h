#ifndef CAXISY_H
#define CAXISY_H

/**
* @file caxisy.h
* @brief CAxisY class interface.
*/

#include "caxis.h"

namespace chart {

class CAxisY : public CAxis
{
public:
    CAxisY();

public:
    /// Reimplemented interface
    virtual void draw(QPaintDevice &pd, const QRectF &r);
};

} // namespace chart

#endif // CAXISY_H
