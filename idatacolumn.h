/* 
* @file idatacolumn.h
* @brief Data column class - implements IDataColumn interface
*
**/

#ifndef IDATACOLUMN_H
#define IDATACOLUMN_H

#include <string>

namespace data_layer 
{

enum EDataType { 
		Int = 0,
		Double,
		String,
		DateTime,
		TypeCount 
};

class IDataColumn 
{
public:
	virtual size_t getSize() const = 0;
	virtual const std::string& getName() const = 0;
	virtual const EDataType getType() const = 0;
	virtual void getData(size_t row, std::string& val) const = 0;
	virtual void getData(size_t row, time_t& val) const = 0;
	virtual void getData(size_t row, int& val) const = 0;
	virtual void getData(size_t row, double& val) const = 0;
	virtual ~IDataColumn() = 0{};
};

} //namespace data_layer

#endif //IDATACOLUMN_H
