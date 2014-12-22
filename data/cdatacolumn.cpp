/** 
* @file cdatacolumn.h
* @brief Data column class implementation.
*
*/

#include "datautility.h"
#include "cdatacolumn.h"

#include <vector>
#include <cassert>

namespace data
{
    CDataColumn::CDataColumn(const QString& name, EDataType type)
		:m_name(name), m_type(type)
	{
		switch(m_type) {
		case String:
            m_data = new Data<QString>;
			break;
		case DateTime:
			m_data = new Data<struct tm>;
			break;
		case Int:
			m_data = new Data<int>;
			break;
		case Double:	
			m_data = new Data<double>;
			break;
		default:
			assert(false);
			break;
		}
	}

    int CDataColumn::getSize() const
	{
		switch(m_type) {
		case String:
            return m_data->getSize<QString>();
			break;
		case DateTime:
			return m_data->getSize<struct tm>();
			break;
		case Int:
			return m_data->getSize<int>();
			break;
		case Double:	
			return m_data->getSize<double>();
			break;
		default:
			assert(false);
			return 0;
			break;
		}
	}

    const QString& CDataColumn::getName() const
	{
		return m_name;
	}

    EDataType CDataColumn::getType() const
	{
		return m_type;
	}

    void CDataColumn::getData(int row, QString& val) const
	{
		m_data->getData(row,val);
	}

    void CDataColumn::getData(int row, struct tm& val) const
	{
		m_data->getData(row,val);
	}

    void CDataColumn::getData(int row, int& val) const
	{
		m_data->getData(row,val);
	}

    void CDataColumn::getData(int row, double& val) const
	{
		m_data->getData(row,val);
	}

	const DataInterface* CDataColumn::getDataBuffer() const
	{
		return m_data;
	}

	CDataColumn::~CDataColumn()
	{}

} //namespace data
