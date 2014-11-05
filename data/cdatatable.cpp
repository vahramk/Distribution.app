/** 
* @file cdatatable.h
* @brief Data table class implementation.
*
*/

#include "datautility.h"
#include "cdatacolumn.h"
#include "cdatatable.h"	

#include <string>

namespace data
{	
	CDataTable::CDataTable()
	{}

	const std::string& CDataTable::getColumnName(size_t index) const
	{
		return m_data.at(index)->getName();
	}

	size_t CDataTable::getColumnCount() const
	{
		return m_data.size();
	}

	size_t CDataTable::getRowCount() const
	{
		if(m_data.empty()) {
			return 0;
		}
		return m_data.at(0)->getSize();
	}

	const IDataColumn* CDataTable::getColumn(size_t index) const
	{
		return m_data.at(index).get();
	}

	void CDataTable::addDataColumn(CDataColumn * column)
	{
		m_data.push_back(column);
		column = 0;
	}

	CDataTable::~CDataTable() 
	{}

} //namespace data
