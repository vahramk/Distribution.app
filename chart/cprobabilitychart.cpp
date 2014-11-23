/**
* @file cprobabilitychart.cpp
* @brief CProbabilityChart class implementation.
*/

#include "../data/idatacolumn.h"
#include "cprobabilitychart.h"

namespace chart {

CProbabilityChart::CProbabilityChart(const data::IDataColumn *oc)
    : IChart(oc)
{}

void CProbabilityChart::paint(QPixmap &op)
{

}

CProbabilityChart::~CProbabilityChart()
{}

} // namespace chart
