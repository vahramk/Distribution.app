/**
* @file main_unite_test.cpp
* @brief This is the main unit test file of the data project.
*/

#include "../idatalayer.h"
#include <iostream>

int main()
{
	using namespace data;
	//TO DO: make full unite test.

	//testing IDataColumn
	IDataColumn* p = 0;
    CDataColumn c("val", Int);
	p = &c;
	//p->getData
	std::string s = p->getName();
    //size_t i = p->getSize();
    //EDataType a = p->getType();

	//testing IDataTable
    //CDataTable tc;
    //IDataTable* tp = 0;
    //tp = &tc;
	//tp->getColumn
	//tp->getColumnName
    //i = tp->getColumnCount();
    //i = tp->getRowCount();

	std::cout<<"Testing Parsers"<<std::endl;
	std::cout<<"\n1. CCSVParser"<<std::endl;
    std::string ff = "pivot.csv";
	CCSVParser csv(ff);
	IDataTable* t = csv.parse();
	std::cout<<"r: "<<t->getRowCount()<<" c: "<<t->getColumnCount()<<std::endl;
	std::cout<<" n: "<<t->getColumn(13)->getName()<<std::endl;
	std::string str;
	double d;

	struct tm dt;
	t->getColumn(0)->getData(927,str);
	t->getColumn(3)->getData(927,dt);
	t->getColumn(13)->getData(927,d);
	char buf[20];
	sprintf(buf, "%04d/%02d/%02d %02d-%02d-%02d", dt.tm_year, dt.tm_mon, dt.tm_mday, dt.tm_hour, dt.tm_min, dt.tm_sec);
	std::cout<<"last element: "<<str<<" c: "<<d<<" dt: "<<buf<<std::endl;

	std::cout<<"\n2. CDataParser interface"<<std::endl;
	CDataParser cdp(ff, CDataParser::csvType);
	const IDataTable* t1 = cdp.parse();
	std::cout<<"r: "<<t1->getRowCount()<<" c: "<<t1->getColumnCount()<<std::endl;
	std::cout<<" n: "<<t1->getColumn(13)->getName()<<std::endl;
	std::string str1;
	double d1;

	struct tm dt1;
	t1->getColumn(0)->getData(927,str1);
	t1->getColumn(3)->getData(927,dt1);
	t1->getColumn(13)->getData(927,d1);
	char buf1[20];
	sprintf(buf1, "%04d/%02d/%02d %02d-%02d-%02d", dt.tm_year, dt.tm_mon, dt.tm_mday, dt.tm_hour, dt.tm_min, dt.tm_sec);
	std::cout<<"last element: "<<str1<<" c: "<<d1<<" dt: "<<buf1<<std::endl;

	std::cout<<"\nStatus: Success"<<std::endl;
	return 0;
}
