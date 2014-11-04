/** 
* @file cdataparser.h
* @brief Data parser interface for the DataTable.
*
*/

#ifndef CDATAPARSER_H
#define CDATAPARSER_H

#include "idataparsermodule.h"
#include "ccsvdataparser.h"

#include <string>
#include <cassert>

namespace data
{
	/** 
	* @brief The class CDataParser implements
	*		parser functionality of data layer.
	*/
	class CDataParser
	{
	public:
		typedef enum
		{
			csvType
		} parserType;

	public:
		/** 
		* @brief This is the constructor.
		*/
		CDataParser(const std::string& file, parserType type);

		/** 
		* @brief This is the main parser function.
		*/
		IDataTable* parse()
		{
			return m_parser->parse();
		}

		/** 
		* @brief This is the destructor.
		*/
		~CDataParser()
		{
			delete m_parser;
		}

	private:
		const std::string m_file;
		parserType m_type;
		IDataParserModule* m_parser;
	};

} //namespace data

#endif //CDATAPARSER_H