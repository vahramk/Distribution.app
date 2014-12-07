/**
* @file cchart.h
* @brief CChart class interface.
* @note this class is for external usage of charts
*/

#ifndef CCHART_H
#define CCHART_H

#include <QExplicitlySharedDataPointer>

#include "ichart.h"

class QPixmap;
class QImage;
class QPaintDevice;

namespace data {
class IDataColumn;
}

namespace chart {

class CChart
{
public:
    /**
     * @brief constructs an empty CChart object;
     */
    CChart();

public:
    /**
     * @brief copy constructer
     */
    CChart(const CChart&);

public:
    /**
     * @brief operator =
     */
    CChart& operator=(const CChart&);

public:
    /**
     * @brief interface for checkin if cchart object
     * is build for chart or not
     * @return build state
     */
    bool isBuild() const;

public:
    /**
     * @brief build CChart for box chart type
     * @param[in] c pointer to column
     */
    void makeForBoxChart(data::IDataColumn* c);

public:
    /**
     * @brief build CChart for probability chart type
     * @param[in] c pointer to column
     */
    void makeForProbabilityChart(data::IDataColumn* c);

public:
    /**
     * @brief build CChart for histogram chart type
     * @param[in] c pointer to column
     */
    void makeForHistogramChart(data::IDataColumn* c);

public:
    /**
     * @brief draw chart on given paint device
     * @param[out] d reference to paint device
     */
    void draw(QPaintDevice& d);

private:
    QExplicitlySharedDataPointer<IChart> m_data;
};

} // namespace chart

#endif // CCHART_H