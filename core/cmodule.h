# main module responsible for distribution analysis management
#ifndef CMODULE_H
#define CMODULE_H

/**
* @file cmodule.h
* @brief CModule class interface.
*/

#include <QObject>

//forward declaration
namespace data
{
    class IDataTable;
} //namespace data

namespace core
{

class CModule : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor.
     * @param[in] parent is the parent object.
     */
    explicit CModule(QObject *parent = 0);

    /**
     * @brief This function sets data.
     * @param[in] pTdata pointer to data table.
     * @pre pTdata != 0
     */
    void setData(data::IDataTable *pTdata);

private:
    data::IDataTable* m_pInputData;

};

} //namespace core
#endif // CMODULE_H
