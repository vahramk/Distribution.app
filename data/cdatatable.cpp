/** 
* @file cdatatable.h
* @brief Data table class implementation.
*
*/

#include "datautility.h"
#include "cdatacolumn.h"
#include "cdatatable.h"	

#include <QString>

namespace data
{	
	CDataTable::CDataTable()
	{}

    const QString& CDataTable::getColumnName(int index) const
	{
		return m_data.at(index)->getName();
	}

    int CDataTable::getColumnCount() const
	{
		return m_data.size();
	}

    int CDataTable::getRowCount() const
	{
		if(m_data.empty()) {
			return 0;
		}
		return m_data.at(0)->getSize();
	}

    const IDataColumn* CDataTable::getColumn(int index) const
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
