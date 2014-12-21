#ifndef CHISTOYRANGE_H
#define CHISTOYRANGE_H

/**
* @file chistoyrange.h
* @brief CHistoYRange class interface.
*/

#include "idatarange.h"

#include <QVector>

namespace chart {

class CHistoYRange : public IDataRange
{
public:
    /**
     * @brief initialise class
     * @param[in] c column for which to create range
     * @param[in] bc bins count
     */
    void init(const data::IDataColumn* c, int bc);

    /// @name Reimplemented interfaces
    /// @{
public:
    virtual QPair<double, double> getRange() const;

public:
    virtual int getSize() const;

public:
    virtual void getData(int row, double &val) const;
    /// @}

private:
    int m_nBinCount;
    QVector<int> m_vecBins;
};

} // namespace chart

#endif // CHISTOYRANGE_H
