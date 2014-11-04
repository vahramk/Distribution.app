/** 
* @file datautility.cpp
* @brief Utilities implementation.
*
*/

#include "datautility.h"

namespace data
{
	//fixed format of data time!
	void fromStringToTime(const std::string& value, struct tm& dt) 
	{
		char buf[20];
		sscanf(value.c_str(), "%d-%d-%d %d:%d:%d", &dt.tm_year, &dt.tm_mon, &dt.tm_mday, &dt.tm_hour, &dt.tm_min, &dt.tm_sec);
	}

} //namespace data