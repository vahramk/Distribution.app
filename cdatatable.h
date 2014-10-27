/* 
* @file cdatatable.h
* @brief Data table class - implements CDataTable interface
*
**/

#ifndef CDATATABLE_H
#define CDATATABLE_H

#include "idatatable.h"

#include <boost/interprocess/smart_ptr/unique_ptr.hpp>
#include <boost/interprocess/containers/vector.hpp>

namespace data_layer
{	
	class CDataColumn;
	
	//unnamed namespace
	namespace {
		template<typename T> 
		struct GenericDeleter 
		{
			void operator()(T *p)
			{
				delete p;
			}
		};

		//This is the type of a unique pointer.
		typedef boost::interprocess::unique_ptr<CDataColumn, GenericDeleter<CDataColumn> > unique_ptr_type;

		//Defines container of unique pointer.
		typedef boost::interprocess::vector< unique_ptr_type > unique_ptr_vector_t;

	} //unnamed namespace

	class CDataTable:public IDataTable
	{
	public:
		CDataTable();
		virtual const std::string& getColumnName(size_t index) const;
		virtual size_t getColumnCount() const;
		virtual size_t getRowCount() const;
		virtual const IDataColumn* getColumn(size_t index) const;
		virtual ~CDataTable();
		void addDataColumn(CDataColumn * column);
	private:
		unique_ptr_vector_t m_data;
	};

}

#endif //CDATATABLE_H
