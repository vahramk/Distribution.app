#ifndef CSERIES_H
#define CSERIES_H

/**
* @file cseries.h
* @brief CSeries class interface.
*/

class QPainter;

namespace chart {

class CDataArea;
class IDataRange;

class CSeries
{
protected:
    /// Protected constructor
    CSeries();

public:
    /// Destructor
    ~CSeries();

public:
    /**
     * @brief sets X data range
     * @param[in] xr data range
     */
    void setX(IDataRange* xr);

public:
    /**
     * @brief sets Y data range
     * @param[in] yr data range
     */
    void setY(IDataRange *yr);

public:
    /**
     * @brief drawes chart
     * @param[in] p ponter to painter
     * @param[in] d pointer to data area
     */
    virtual void draw(QPainter* p, CDataArea* d) = 0;

protected:
    const IDataRange* getX();

protected:
    const IDataRange* getY();

private:
    IDataRange* m_oxRange;
    IDataRange* m_oyRange;
};

} // namespace chart

#endif // CSERIES_H
