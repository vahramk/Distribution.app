#ifndef CPROBSERIES_H
#define CPROBSERIES_H

/**
* @file cprobseries.h
* @brief CProbSeries class interface.
*/

#include "cseries.h"

namespace chart {

class CProbSeries : public CSeries
{
public:
    /// Constructor
    CProbSeries();

public:
    /// Destructor
    virtual ~CProbSeries();

public:
    /// Reimplemented interface (see CSeries class)
    virtual void draw(QPainter *p, CDataArea *d);
};

} // namespace chart

#endif // CPROBSERIES_H
