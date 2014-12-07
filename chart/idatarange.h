#ifndef IDATARANGE_H
#define IDATARANGE_H

/**
* @file idatarange.h
* @brief IDataRange class interface.
*/

#include "../data/idatacolumn.h"

#include <QPair>

namespace chart {

class IDataRange : public data::IDataColumn
{
public:
    /**
     * @brief interface for geting range
     * @return range
     */
    virtual QPair<double, double> getRange() const = 0;
};

} // namespace chart

#endif // IDATARANGE_H
