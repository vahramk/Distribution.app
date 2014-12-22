/** 
* @file idatatable.h
* @brief IDataTable interface
*
*/

#ifndef IDATATABLE_H
#define IDATATABLE_H

#include "idatacolumn.h"

#include <QString>

namespace data 
{
	/** 
	* @brief The is an interface class.
	*/
	class IDataTable 
	{
	public:
		/** 
		* @brief This function returns the name of the column, 
		*		 corresponding to passed arguments.
		* @param[in] index is the column index in table. 
		* @exception throws std::out_of_range exception.
		*/
        virtual const QString& getColumnName(int index) const = 0;
		
		/** 
		* @brief This function returns the count of columns in table.
		*/
        virtual int getColumnCount() const = 0;
		
		/** 
		* @brief This function returns the count of rows in table.
		*/		
        virtual int getRowCount() const = 0;
		
		/** 
		* @brief This function returns the column pointer, 
		*		 corresponding to passed arguments.
		* @param[in] index is the column index in table. 
		* @exception throws std::out_of_range exception.
		*/		
        virtual const IDataColumn* getColumn(int index) const = 0;
		
		/** 
		* @brief This is the desconstructor.
		*/		
		virtual ~IDataTable(){};
	};

} //namespace data

#endif //IDATATATABLE_H
