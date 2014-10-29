/* 
* @file datautility.h
* @brief Utilities interface.
*
**/

#ifndef DATAUTILITY_H
#define DATAUTILITY_H

#include <deque>

namespace data
{
	/* 
	* @brief This is the type of data in table. 
	**/
	enum EDataType {
		Int = 0,
		Double,
		String,
		DateTime,
		TypeCount 
	};
	
	/* 
	* @brief This class provides auxiliary interface for Data class. 
	**/
	class DataInterface
	{
	public:
		template<typename T> 
		void pushBack(const T& val);

		template <typename T>
		int getSize();

		template<typename T>
		void reserve(int size);

		template<typename T>
		void getData(int row, T& val);
	};
	
	/* 
	* @brief This is the main data container type. 
	**/
	template<typename T>
	class Data: public DataInterface, public std::deque<T>
	{
	public:
		void getData(int row, T& val)
		{
			val = std::deque<T>::at(row);
		}
	};

	template<typename T> 
	void DataInterface::pushBack(const T& value)
	{
		Data<T> *pData = static_cast<Data<T>* >(this);
		pData->push_back(value);
	}

	template <typename T>
	int DataInterface::getSize()
	{
		Data<T> *pData = static_cast<Data<T>* >(this);
		return pData->size();
	}

	template<typename T>
	void DataInterface::reserve(int size)
	{
		Data<T> *pData = static_cast<Data<T>* >(this);
		return pData->reserve();
	}

	template<typename T>
	void DataInterface::getData(int row, T& val)
	{
		Data<T> *pData = static_cast<Data<T>* >(this);
		return pData->getData(row, val);
	}

} //namespace data

#endif //DATAUTILITY