#ifndef CPROBYRANGE_H
#define CPROBYRANGE_H

/**
* @file cprobyrange.h
* @brief CProbYRange class interface.
*/

#include "idatarange.h"

namespace data {
class IDataColumn;
}

namespace chart {

class CProbYRange : public IDataRange
{
public:
    /**
     * @brief initialize CProbYRange for given data column
     * @param[in] dc pointer to data column
     */
    void init(const IDataColumn *dc);

    /// @name Reimplemented interface
    /// @{
public:
    virtual QPair<double, double> getRange() const;

public:
    virtual int getSize() const;

public:
    virtual void getData(int row, double &val) const;
    /// @}

private:
    size_t m_uSize;
};

} // namespace chart

#endif // CPROBYRANGE_H
