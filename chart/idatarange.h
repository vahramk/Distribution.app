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

    virtual const QString& getName() const
    {
        return m_strName;
    }

    virtual void getData(int, struct tm&) const
    {}

    virtual void getData(int, int&) const
    {}

    virtual void getData(int, QString&) const
    {}

    virtual const data::DataInterface* getDataBuffer() const
    {
        return 0;
    }

private:
    QString m_strName;
};

} // namespace chart

#endif // IDATARANGE_H
