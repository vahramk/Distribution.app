/* 
* @file idatatable.h
* @brief IDataTable interface
*
**/

#ifndef IDATATABLE_H
#define IDATATABLE_H

#include "idatacolumn.h"

#include <string>

namespace data_layer 
{

	class IDataTable 
	{
	public:
		virtual const std::string& getColumnName(size_t index) const = 0;
		virtual size_t getColumnCount() const = 0;
		virtual size_t getRowCount() const = 0;
		virtual const IDataColumn* getColumn(size_t index)const = 0 ;
		virtual ~IDataTable(){};
	};

} //namespace data_layer

#endif //IDATATATABLE_H
