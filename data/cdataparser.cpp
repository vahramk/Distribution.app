/** 
* @file cdataparser.cpp
* @brief Implementation of Data parser for the DataTable.
*
*/

#include "cdataparser.h"

namespace data
{
	CDataParser::CDataParser(const std::string& file, parserType type)
		:m_file(file), m_type(type)
	{
		switch(type) {
			case csvType:
				m_parser = new CCSVParser(file);
				break;
			default:
				assert(false);
				break;
		}
	}
} //namespace data