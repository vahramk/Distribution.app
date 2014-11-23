/**
* @file ichart.h
* @brief IChart class interface.
*/

#ifndef ICHART_H
#define ICHART_H

#include <QtGlobal>

class QPixmap;
class data::IDataColumn;

namespace chart
{

class IChart
{
public:
    /**
     * @brief IChart constructer
     * @param[in] oc pointer to column for which chart
     * will be drowen
     * @note oc != 0
     */
    IChart(const data::IDataColumn* oc)
        : m_cocolumn(oc)
    {
        Q_ASSERT(oc != 0);
    }

public:
    /**
     * @brief Paint chart on given pixmap
     * @param[out] op reference to pixmap
     */
    virtual void paint(QPixmap& op) = 0;

public:
    /**
     * @brief destructor
     */
    virtual ~IChart()
    {}

protected:
    /**
     * @brief Return pointer to column
     * @return Return pointer to column
     */
    const data::IDataColumn* getColumn() const
    {
        Q_ASSERT(m_cocolumn != 0);
        return m_cocolumn;
    }

private:
    const data::IDataColumn* m_cocolumn;
};

} // namespace chart

#endif // ICHART_H
