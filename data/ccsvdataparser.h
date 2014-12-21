/** 
* @file ccsvdataparser.h
* @brief CSV Data parser interface for the Data Parser.
*
*/

#ifndef CCSVDATAPARSER_H
#define CCSVDATAPARSER_H

#include "datautility.h"
#include "idataparsermodule.h"

#include <vector>

#include <QString>
#include <QVector>

namespace data
{
	//forward declarations.
	class IDataTable;
	class CDataColumn;
	class CDataTable;
	class Tockenizer;

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
        CCSVParser(const QString& file_name);
		
		/** 
		* @brief This is the main parser function.
		*/
		virtual IDataTable* parse();
		
		/** 
		* @brief This is the deconstructor.
		*/
        virtual ~CCSVParser();

	private:
		/** 
		* @brief This function returns the type of the passed arguments.
		* @param[in] value is the data. 
		*/
        EDataType get_type(const QString& value) const;
		
		/** 
		* @brief This function tokenizes the passed string argument.
		* @param[in] line is the string to be tokenized. 
		* @param[out] vec is the container which will be returned.
		*/
        void tokenize_line(const Tockenizer& line, QVector<QString>& vec) const;
		
		/** 
		* @brief This function adds value to column corresponding to passed arguments.
		* @param[in] c is the column. 
		* @param[in] type is the value.
		*/
        void addValueToColumn(CDataColumn* c, const QString& value);
		
		/** 
		* @brief This function adds value to column of current table corresponding to passed arguments.
		* @param[in] t is the table. 
		* @param[in] i is the index of the column.
		* @param[in] value is the value.
		*/
        void addValueToTable(CDataTable* t, int i,const QString& value);

	private:
        const QString m_path;
		CDataTable* m_table;
	};

} //namespace data

#endif //CCSVDATAPARSER_H
