#ifndef CPROBXRANGE_H
#define CPROBXRANGE_H

/**
* @file cprobxrange.h
* @brief CProbXRange class interface.
*/

#include "idatarange.h"

namespace data {
class IDataColumn;
}

namespace chart {

class CProbXRange : public IDataRange
{
public:
    /**
     * @brief initilize CProbXRange for given data column
     * @param[in] dc pointer to data calumn
     */
    void init(const IDataColumn *dc);

    /// @name Reimplemented interface
    /// @{
public:
    virtual QPair<double, double> getRange() const;

public:
    virtual size_t getSize() const;

public:
    virtual void getData(size_t row, double &val) const;
    /// @}

private:
    double m_fMin;
    double m_fMax;
    size_t m_uSize;
    std::vector<double> m_vecData;
};

} // namespace chart

#endif // CPROBXRANGE_H
