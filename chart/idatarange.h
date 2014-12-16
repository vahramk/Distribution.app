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

    // THIS IS TEMPRIARY WORKROUND
private:
    virtual data::EDataType getType() const
    {
        return data::Double;
    }

    virtual const std::string& getName() const
    {
        return m_strName;
    }

    virtual void getData(size_t, struct tm&) const
    {}

    virtual void getData(size_t, int&) const
    {}

    virtual void getData(size_t, std::string&) const
    {}

    virtual const data::DataInterface* getDataBuffer() const
    {
        return 0;
    }

private:
    std::string m_strName;
};

} // namespace chart

#endif // IDATARANGE_H
