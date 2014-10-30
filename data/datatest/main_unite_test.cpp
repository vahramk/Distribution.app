/*
* This is the main unit test file of the data project.
**/

#include "../idatalayer.h"

int main()
{
	using namespace data;
	//TO DO: make full unite test.

	//testing IDataColumn
	IDataColumn* p = 0;
	CDataColumn c("val", EDataType::Int);
	p = &c;
	//p->getData
	std::string s = p->getName();
	size_t i = p->getSize();
	EDataType a = p->getType();
	
	//testing IDataTable
	IDataTable* tp = 0;
	CDataTable tc;
	tp = &tc;
	//tp->getColumn
	//tp->getColumnName
	i = tp->getColumnCount();
	i = tp->getRowCount();

	//testing IDataParser
	//CDataParser
	//CCSVParser
	return 0;
}