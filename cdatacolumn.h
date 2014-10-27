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

namespace data_layer
{
	class CDataColumn:public IDataColumn
	{
	private:
		class DataBase
		{
		public:
			template<typename T> 
			void push_back(const T& val);

			template <typename T>
			int getSize();

			template<typename T>
			void reserve(int size);

			template<typename T>
			void getData(int row, T& val);
		};

		template<typename T>
		class Data : public DataBase, public std::deque<T>
		{
		public:
			void getData(int row, T& val)
			{
				val = std::deque<T>::at(row);
			}
		};

	public:
		CDataColumn(const std::string& name, EDataType type);
		virtual size_t getSize() const;
		virtual const std::string& getName() const;
		virtual const EDataType getType() const;
		/*throws out of range exception.*/
		virtual void getData(size_t row, std::string& val) const;
		virtual void getData(size_t row, time_t& val) const;
		virtual void getData(size_t row, int& val) const;
		virtual void getData(size_t row, double& val) const;
		virtual ~CDataColumn();

	private:
		EDataType m_type;
		std::string m_name;
		DataBase * m_data;
	};

} // namespace data_layer

#endif //CDATACOLUMN_H
