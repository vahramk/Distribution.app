/** 
* @file idatacolumn.h
* @brief IDataColumn interface
*
*/

#ifndef IDATACOLUMN_H
#define IDATACOLUMN_H

#include <string>

#include "datautility.h"

namespace data 
{
	//forward declarations.
	class DataInterface;

	/** 
	* @brief The is an interface class.
	*/
	class IDataColumn 
	{
	public:
		/** 
		* @brief This function returns the count of rows in column. 
		*/
		virtual size_t getSize() const = 0;
		
		/** 
		* @brief This function returns the name of the column.
		*/
		virtual const std::string& getName() const = 0;
		
		/** 
		* @brief This function returns the type of the column.
		*/
        virtual EDataType getType() const = 0;

		/** 
		* @brief This function returns value of current cell, 
		*		 corresponding to passed arguments (for struct tm).
		* @param[in] row is the row (cell) number in current column. 
		* @param[out] val is the value of cell which will be returned. 
		* @exception throws std::out_of_range exception.
		*/		
		virtual void getData(size_t row, struct tm& val) const = 0;		
		
		/** 
		* @brief This function returns value of current cell, 
		*		 corresponding to passed arguments (for std::string type).
		* @param[in] row is the row (cell) number in current column. 
		* @param[out] val is the value of cell which will be returned. 
		* @exception throws std::out_of_range exception.
		*/
		virtual void getData(size_t row, std::string& val) const = 0;
		
		/** 
		* @brief This function returns value of current cell, 
		*		 corresponding to passed arguments (for int type).
		* @param[in] row is the row (cell) number in current column. 
		* @param[out] val is the value of cell which will be returned. 
		* @exception throws std::out_of_range exception.
		*/
		virtual void getData(size_t row, int& val) const = 0;
		
		/** 
		* @brief This function returns value of current cell, 
		*		 corresponding to passed arguments (for double type).
		* @param[in] row is the row (cell) number in current column. 
		* @param[out] val is the value of cell which will be returned. 
		* @exception throws std::out_of_range exception.
		*/
		virtual void getData(size_t row, double& val) const = 0;
		
		/** 
		* @brief This function returns chunk of data buffer from column, 
		*		 corresponding to passed arguments.
		* @param[in] size is the size of chunk. 
		* @param[out] buff is the container which will be returned. 
		* @exception throws std::out_of_range exception.
		*/
		virtual const DataInterface* getDataBuffer() const = 0;
		
		/** 
		* @brief This is the desconstructor.
		*/
        virtual ~IDataColumn() {};
	};

} //namespace data

#endif //IDATACOLUMN_H
