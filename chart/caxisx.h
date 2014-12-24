#ifndef CAXISX_H
#define CAXISX_H

/**
* @file caxisx.h
* @brief CAxisX class interface.
*/

#include "caxis.h"

namespace chart {

class CAxisX : public CAxis
{
public:
    CAxisX();

public:
    /// Reimplemented interface
    virtual void draw(QPaintDevice &pd, const QRectF &r);
};

} // namespace chart

#endif // CAXISX_H
