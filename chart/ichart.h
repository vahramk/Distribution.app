/**
* @file ichart.h
* @brief IChart class interface.
*/

#ifndef ICHART_H
#define ICHART_H

#include <QtGlobal>
#include <QSharedData>

class QPaintDevice;
namespace data {
class IDataColumn;
}

namespace chart
{

class IChart : public QSharedData
{
public:
    /**
     * @brief IChart constructer
     * @param[in] oc pointer to column for which chart
     * will be drowen
     * @note oc != 0
     */
    IChart(const data::IDataColumn* oc)
        : QSharedData()
        , m_cocolumn(oc)
    {
        Q_ASSERT(oc != 0);
    }

public:
    /**
     * @brief draw chart on given paint device
     * @param[out] pd reference to paint device
     */
    virtual void draw(QPaintDevice& pd) = 0;

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
