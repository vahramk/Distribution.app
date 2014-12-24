#ifndef IDRAWABLE_H
#define IDRAWABLE_H

/**
 * @file idrawable.h
 * @brief interface for drawable classes
 */

class QPaintDevice;
class QRectF;

namespace chart {

class IDrawable
{
protected:
    IDrawable()
    {
        m_xMargin = 10;
        m_yMargin = 10;
    }

public:
    /**
     * @brief drawing interface
     * @param[in] pd paint device on which to draw
     * @param[in] r rect on which to draw
     */
    virtual void draw(QPaintDevice& pd, const QRectF &r) = 0;

protected:
    void setXMargin(int m)
    {
        m_xMargin = m;
    }

protected:
    int getXMargin() const
    {
        return m_xMargin;
    }

protected:
    void setYMargin(int m)
    {
        m_yMargin = m;
    }

protected:
    int getYMargin() const
    {
        return m_yMargin;
    }

private:
    int m_xMargin;
    int m_yMargin;

};

} // namespace chart

#endif // IDRAWABLE_H
