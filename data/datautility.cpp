/** 
* @file datautility.cpp
* @brief Utilities implementation.
*
*/

#include "datautility.h"

#include <boost/date_time/local_time/local_time.hpp>

namespace data
{
	 void fromStringToTime(const std::string& value, boost::local_time::local_date_time& ldt) 
	{
		namespace BT = boost::local_time;
		typedef BT::local_time_input_facet lt;
		// Set up the input datetime format.
		lt* input_facet = new lt("%Y-%m-%d %H:%M:%S %ZP");
		// Read time into ldt
		std::stringstream ss;
		ss.imbue(std::locale(ss.getloc(), input_facet));
		ss.str(value);
		ss >> ldt;
	}

} //namespace data