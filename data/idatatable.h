/* 
* @file idatatable.h
* @brief IDataTable interface
*
**/

#ifndef IDATATABLE_H
#define IDATATABLE_H

#include "idatacolumn.h"

#include <string>

namespace data 
{
	/* 
	* @brief The is an interface class.
	**/
	class IDataTable 
	{
	public:
		/* 
		* @brief This function returns the name of the column, 
		*		 corresponding to passed arguments.
		* @param[in] index is the column index in table. 
		* @exception throws std::out_of_range exception.
		**/
		virtual const std::string& getColumnName(size_t index) const = 0;
		
		/* 
		* @brief This function returns the count of columns in table.
		**/
		virtual size_t getColumnCount() const = 0;
		
		/* 
		* @brief This function returns the count of rows in table.
		**/		
		virtual size_t getRowCount() const = 0;
		
		/* 
		* @brief This function returns the column pointer, 
		*		 corresponding to passed arguments.
		* @param[in] index is the column index in table. 
		* @exception throws std::out_of_range exception.
		**/		
		virtual const IDataColumn* getColumn(size_t index) const = 0;
		
		/* 
		* @brief This is the desconstructor.
		**/		
		virtual ~IDataTable(){};
	};

} //namespace data

#endif //IDATATATABLE_H