#ifndef CHISTOSERIES_H
#define CHISTOSERIES_H

/**
* @file chistoseries.h
* @brief CHistoSeries class interface.
*/

#include "cseries.h"

namespace chart {

class CHistoSeries : public CSeries
{
public:
    /// Constructer for CHistoSeries
    CHistoSeries();

public:
    /// Destructer
    virtual ~CHistoSeries();

public:
    /// Reimplemented interface (see CSeries class)
    virtual void draw(QPainter *p, CDataArea *d);
};

} // namespace chart

#endif // CHISTOSERIES_H
