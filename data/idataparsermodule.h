/**
* @file idataparsermodule.h
* @brief Interface for Parser Modules
*
*/

#ifndef IDATAPARSERMODEL_H
#define IDATAPARSERMODEL_H

namespace data
{
	//forward declaration.
	class IDataTable;

	class IDataParserModule
	{
	public:
		/** 
		* @brief This is the main parser function.
		*/
		virtual IDataTable* parse() = 0;

		/** 
		* @brief This is the desconstructor.
		*/		
		virtual ~IDataParserModule() = 0 {};
	};
}

#endif //DATAIPARSERMODEL_H