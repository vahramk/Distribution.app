/** 
* @file datautility.h
* @brief Utilities interface.
*
*/

#ifndef DATAUTILITY_H
#define DATAUTILITY_H

#include <vector>
#include <boost/date_time/local_time/local_time.hpp>

namespace data
{
	/** 
	* @brief This is the type of data in table. 
	*/
	enum EDataType {
		Int = 0,
		Double,
		String,
		DateTime,
		TypeCount 
	};

	/** 
	* @brief This class provides auxiliary interface for Data class. 
	*/
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

	/** 
	* @brief This is the main container type. 
	*/
	template<typename T>
	class Data: public DataInterface, public std::vector<T>
	{
	public:
		void getData(int row, T& val)
		{
			val = std::vector<T>::at(row);
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

	template<typename T>
	T fromString(const std::string& value) 
	{
		std::istringstream stream(value);
		T t;
		stream >> t;
		return t;
	}

	void fromStringToTime(const std::string& value, boost::local_time::local_date_time& ldt);

} //namespace data

#endif //DATAUTILITY