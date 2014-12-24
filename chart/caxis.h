#ifndef CAXIS_H
#define CAXIS_H

/**
* @file caxis.h
* @brief CAxis class interface.
*/

#include "idrawable.h"
#include <QDebug>

namespace chart {

class IDataRange;

class CAxis : public IDrawable
{
public:
    CAxis();

public:
    /**
     * @brief sets data range
     * @param[in] dr pointer to data range
     */
    void setRange(IDataRange* dr);

protected:
    const IDataRange* getRange() const;

private:
    IDataRange* m_pData;
};

} // namespace chart

#endif // CAXIS_H
