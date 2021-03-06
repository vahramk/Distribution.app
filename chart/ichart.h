/**
* @file ichart.h
* @brief IChart class interface.
*/

#ifndef ICHART_H
#define ICHART_H

#include <QtGlobal>
#include <QSharedData>
#include <QString>

#include "idrawable.h"

class QPaintDevice;
class QRectF;

namespace data {
class IDataColumn;
}

namespace chart
{

class IChart : public QSharedData
             , public IDrawable
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
        , IDrawable()
        , m_cocolumn(oc)
    {
        Q_ASSERT(oc != 0);
    }

public:
    /**
     * @brief return chart name
     */
    virtual QString getName() const = 0;

public:
    /**
     * @brief draw chart on given paint device
     * @param[in] pd reference to paint device
     * @param[in] r reference to rect
     */
    virtual void draw(QPaintDevice& pd, const QRectF& r) = 0;

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
