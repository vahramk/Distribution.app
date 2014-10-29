/* 
* @file cdatacolumn.h
* @brief Data column class - implements IDataColumn interface
*
**/

#ifndef CDATACOLUMN_H
#define CDATACOLUMN_H

#include "idatacolumn.h"
#include <string>
#include <deque>

namespace data
{
	//forward declaration.
	class DataInterface;

	/* 
	* @brief The class CDataColumn implements the
	*		IDataColumn interface.
	**/
	class CDataColumn:public IDataColumn
	{
	public:
		/* 
		* @brief This is the constructor.
		* @param[in] name is the name of column. 
		* @param[in] type is the type of column. 
		**/
		CDataColumn(const std::string& name, EDataType type);

		/* 
		* @brief This function returns the count of rows in column. 
		**/
		virtual size_t getSize() const;

		/* 
		* @brief This function returns the name of the column.
		**/
		virtual const std::string& getName() const;

		/* 
		* @brief This function returns the type of the column.
		**/
		virtual const EDataType getType() const;

		/* 
		* @brief This function returns value of current cell, 
		*		 corresponding to passed arguments (for std::string type).
		* @param[in] row is the row (cell) number in current column. 
		* @param[out] val is the value of cell which will be returned. 
		* @exception throws std::out_of_range exception.
		**/
		virtual void getData(size_t row, std::string& val) const;

		/* 
		* @brief This function returns value of current cell, 
		*		 corresponding to passed arguments (for time_t type).
		* @param[in] row is the row (cell) number in current column. 
		* @param[out] val is the value of cell which will be returned. 
		* @exception throws std::out_of_range exception.
		**/
		virtual void getData(size_t row, time_t& val) const;

		/* 
		* @brief This function returns value of current cell, 
		*		 corresponding to passed arguments (for int type).
		* @param[in] row is the row (cell) number in current column. 
		* @param[out] val is the value of cell which will be returned. 
		* @exception throws std::out_of_range exception.
		**/
		virtual void getData(size_t row, int& val) const;

		/* 
		* @brief This function returns value of current cell, 
		*		 corresponding to passed arguments (for double type).
		* @param[in] row is the row (cell) number in current column. 
		* @param[out] val is the value of cell which will be returned. 
		* @exception throws std::out_of_range exception.
		**/
		virtual void getData(size_t row, double& val) const;

		/* 
		* @brief This function returns chunk of data buffer from column, 
		*		 corresponding to passed arguments.
		* @param[in] size is the size of chunk. 
		* @param[out] buff is the container which will be returned. 
		* @exception throws std::out_of_range exception.
		**/
		virtual const DataInterface* getDataBuffer() const; //To be changed. Mast take parameters.

		/* 
		* @brief This is the desconstructor.
		**/
		virtual ~CDataColumn();

	private:
		EDataType m_type;
		std::string m_name;
		DataInterface * m_data;
	};

} // namespace data

#endif //CDATACOLUMN_H