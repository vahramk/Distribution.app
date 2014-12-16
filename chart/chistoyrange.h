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
    void init(const data::IDataColumn* c, size_t bc);

    /// @name Reimplemented interfaces
    /// @{
public:
    virtual QPair<double, double> getRange() const;

public:
    virtual size_t getSize() const;

public:
    virtual void getData(size_t row, double &val) const;
    /// @}

private:
    int m_nBinCount;
    QVector<size_t> m_vecBins;
};

} // namespace chart

#endif // CHISTOYRANGE_H
