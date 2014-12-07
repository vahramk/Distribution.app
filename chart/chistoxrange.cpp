#include "chistoxrange.h"

namespace chart {

void CHistoXRange::init(const data::IDataColumn *c, int bc)
{
    m_fBinSize = bc;
}

size_t CHistoXRange::getSize() const
{
    return 0;
}

QPair<double, double> CHistoXRange::getRange() const
{
    return QPair<double, double>(0, 0);
}

void CHistoXRange::getData(size_t row, double &val) const
{

}

} // namespace chart
