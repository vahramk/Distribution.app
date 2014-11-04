/** 
* @file ccsvdataparser.h
* @brief CSV Data parser interface for the Data Parser.
*
*/

#ifndef CCSVDATAPARSER_H
#define CCSVDATAPARSER_H

#include "idataparsermodule.h"

#include <string>
#include <vector>

namespace data
{
	//forward declarations.
	enum EDataType;
	class IDataTable;
	class CDataColumn;
	class CDataTable;

	/** 
	* @brief The class CCSVParser implements
	*		CSV parser functionality of Data Parser.
	*/
	class CCSVParser: public IDataParserModule
	{
	public:
		/** 
		* @brief This is the constructor.
		* @param[in] file_name is the path which shell parsed. 
		*/
		CCSVParser(const std::string& file_name);
		
		/** 
		* @brief This is the main parser function.
		*/
		virtual IDataTable* parse();
		
		/** 
		* @brief This is the deconstructor.
		*/
		virtual ~CCSVParser()
		{
			delete m_table;
		}

	private:
		/** 
		* @brief This function returns the type of the passed arguments.
		* @param[in] value is the data. 
		*/
		EDataType get_type(const std::string& value) const;
		
		/** 
		* @brief This function tokenizes the passed string argument.
		* @param[in] line is the string to be tokenized. 
		* @param[out] vec is the container which will be returned.
		*/
		void tokenize_line(const std::string& line, std::vector<std::string>& vec) const;
		
		/** 
		* @brief This function adds value to column corresponding to passed arguments.
		* @param[in] c is the column. 
		* @param[in] type is the value.
		*/
		void addValueToColumn(CDataColumn* c, const std::string& value);
		
		/** 
		* @brief This function adds value to column of current table corresponding to passed arguments.
		* @param[in] t is the table. 
		* @param[in] i is the index of the column.
		* @param[in] value is the value.
		*/
		void addValueToTable(CDataTable* t, size_t i,const std::string& value);

	private:
		const std::string m_path;
		CDataTable* m_table;
	};

} //namespace data

#endif //CCSVDATAPARSER_H