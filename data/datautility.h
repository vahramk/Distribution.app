/** 
* @file datautility.h
* @brief Utilities interface.
*
*/

#ifndef DATAUTILITY_H
#define DATAUTILITY_H

#include <vector>
#include <sstream>

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
	* @brief This class provides boost's style unique_ptr. 
	*/
	template<typename T, typename Deleter>
	class unique_ptr
	{
	public:
		typedef T value_type;
		typedef Deleter deleter_type;

	public:
		unique_ptr()
			:m_p(0)
		{}

		unique_ptr(const unique_ptr& rhs)
		{
			m_p=rhs.take();
		}

		unique_ptr(const value_type* rhs)
		{
			m_p = const_cast<value_type*>(rhs);
			rhs = 0;
		}

		const value_type* operator->() const
		{
			return m_p;
		}

		value_type* operator->()
		{
			return const_cast<unique_ptr*>(this)->m_p;
		}
		
		const value_type& operator*() const
		{
			return *m_p;
		}

		value_type& operator*()
		{
			return *const_cast<unique_ptr*>(this)->m_p;
		}

		value_type* get() const
		{
			return m_p;
		}

		~unique_ptr()
		{
			destroy(); 
		}
		
		value_type* take() const
		{
			value_type* t = m_p;
			reset();
			return t;
		}

		void reset() const
		{
			m_p = 0;
		}

		void destroy()
		{
			if (m_p != 0)
			{
				m_del(m_p);
			}
			m_p = 0;
		}

	private:
		mutable value_type* m_p;
		deleter_type m_del;

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

	void fromStringToTime(const std::string& value, struct tm& dt);

	class Tockenizer:public std::string
	{
	public:
		Tockenizer()
			:m_start(0), m_end(0), m_indx(0)
		{}

		bool operator++() const
		{
			if(m_indx >= size())
			{
				return false;
			}
			m_start = m_indx;
			for(int bcksl_count = 0; m_indx < size(); ++m_indx)
			{
				const char& c = this->operator [](m_indx);
				if(c =='\\')
				{
					if(bcksl_count == 0)
					{
						++bcksl_count;
						continue;
					}
					bcksl_count = 0;
					continue;
				}
				if(c ==',' && bcksl_count==0)
				{
					break;
				}
				bcksl_count = 0;
			}
			m_end = m_indx;
			++m_indx;
			return true;
		}

		int start() const
		{
			return m_start;
		}

		int end() const
		{
			return m_end;
		}

		void reset_parser() const
		{
			m_start=0;
			m_end=0;
			m_indx=0;
		}

	private:
		mutable int m_start;
		mutable int m_end;
		mutable int m_indx;
	};

} //namespace data

#endif //DATAUTILITY