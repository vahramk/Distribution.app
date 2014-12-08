#ifndef CHISTOXRANGE_H
#define CHISTOXRANGE_H

/**
* @file chistoxrange.h
* @brief CHistoXRange class interface.
*/

#include "idatarange.h"

namespace chart {

class CHistoXRange : public IDataRange
{
public:
    /**
     * @brief initialize histoXRange
     * @param[in] c pointer to IDatacoulmn for wich to create range
     * @param[in] bc bin count for histogram chart
     */
    void init(const data::IDataColumn* c, int bc);

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
    int m_nBinCount;
    double m_fBinSize;
    double m_fBinAnchor;
};

} // namespace chart

#endif // CHISTOXRANGE_H