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
	CDataColumn::CDataColumn(const std::string& name, EDataType type)
		:m_name(name), m_type(type)
	{
		switch(m_type) {
		case String:
			m_data = new Data<std::string>;
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

	size_t CDataColumn::getSize() const
	{
		switch(m_type) {
		case String:
			return m_data->getSize<std::string>();
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

	const std::string& CDataColumn::getName() const
	{
		return m_name;
	}

    EDataType CDataColumn::getType() const
	{
		return m_type;
	}

	void CDataColumn::getData(size_t row, std::string& val) const
	{
		m_data->getData(row,val);
	}

	void CDataColumn::getData(size_t row, struct tm& val) const
	{
		m_data->getData(row,val);
	}

	void CDataColumn::getData(size_t row, int& val) const
	{
		m_data->getData(row,val);
	}

	void CDataColumn::getData(size_t row, double& val) const
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
