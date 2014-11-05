/** 
* @file cdatatable.h
* @brief Data table class - implements CDataTable interface
*
*/

#ifndef CDATATABLE_H
#define CDATATABLE_H

#include "idatatable.h"

#include <vector>

namespace data
{	
	//forward declarations.
	class CDataColumn;
	
	//unnamed namespace
	namespace {
		/** 
		* @brief This is a generic deleter for 
		*		unique_ptr.
		*/
		template<typename T> 
		struct GenericDeleter 
		{
			void operator()(T *p)
			{
				delete p;
			}
		};

		//This is the type of a unique pointer.
		typedef unique_ptr<CDataColumn, GenericDeleter<CDataColumn> > unique_ptr_type;

		//Defines container of unique pointer.
		typedef std::vector< unique_ptr_type > unique_ptr_vector_t;

	} //unnamed namespace

	/** 
	* @brief The class CDataTable implements the
	*		IDataTable interface.
	*/
	class CDataTable:public IDataTable
	{
	public:
		/** 
		* @brief This is the constructor.
		*/
		CDataTable();

		/** 
		* @brief This function returns the name of the column, 
		*		 corresponding to passed arguments.
		* @param[in] index is the column index in table. 
		* @exception throws std::out_of_range exception.
		*/
		virtual const std::string& getColumnName(size_t index) const;

		/** 
		* @brief This function returns the count of columns in table.
		*/
		virtual size_t getColumnCount() const;

		/** 
		* @brief This function returns the count of rows in table.
		*/
		virtual size_t getRowCount() const;

		/** 
		* @brief This function returns the column pointer, 
		*		 corresponding to passed arguments.
		* @param[in] index is the column index in table. 
		* @exception throws std::out_of_range exception.
		*/
		virtual const IDataColumn* getColumn(size_t index) const;

		/** 
		* @brief This is the desconstructor.
		*/
		virtual ~CDataTable();
		
		/** 
		* @brief This function adds new column into current table, 
		*		 corresponding to passed arguments.
		* @param[in] column is pointer to column. 
		* @exception throws std::out_of_range exception.
		*/		
		void addDataColumn(CDataColumn* column);

		/** 
		* @brief This function adds new cell into the selected column, 
		*		 corresponding to passed arguments.
		* @param[in] column_index this is the index of column. 
		* @param[in] value this is the value which should be inserted. 
		*/
		template<typename T>
		void addCell(size_t column_index, const T& value)
		{
			m_data[column_index]->addValue(value);
		}

	private:
		unique_ptr_vector_t m_data;
	};

} //namespace data

#endif //CDATATABLE_H
