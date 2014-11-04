/**
* @file main_unite_test.cpp
* @brief This is the main unit test file of the data project.
*/

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

	std::cout<<"Testing Parsers"<<std::endl;
	std::cout<<"\n1. CCSVParser"<<std::endl;
	std::string ff = "pivot.csv";
	CCSVParser csv(ff);
	IDataTable* t = csv.parse();
	std::cout<<"r: "<<t->getRowCount()<<" c: "<<t->getColumnCount()<<std::endl;
	std::cout<<" n: "<<t->getColumn(13)->getName()<<std::endl;
	std::string str;
	double d;
	boost::local_time::local_date_time tk(boost::local_time::not_a_date_time);
	t->getColumn(0)->getData(927,str);
	t->getColumn(3)->getData(927,tk);
	t->getColumn(13)->getData(927,d);
	std::cout<<"last element: "<<str<<" c: "<<d<<" tk: "<<tk<<std::endl;
	
	std::cout<<"\n2. CDataParser interface"<<std::endl;
	CDataParser cdp(ff, CDataParser::csvType);
	IDataTable* t1 = cdp.parse();
	std::cout<<"r: "<<t1->getRowCount()<<" c: "<<t1->getColumnCount()<<std::endl;
	std::cout<<" n: "<<t1->getColumn(13)->getName()<<std::endl;
	std::string str1;
	double d1;
	boost::local_time::local_date_time tk1(boost::local_time::not_a_date_time);
	t1->getColumn(0)->getData(927,str1);
	t1->getColumn(3)->getData(927,tk1);
	t1->getColumn(13)->getData(927,d1);
	std::cout<<"last element: "<<str1<<" c: "<<d1<<" tk: "<<tk1<<std::endl;

	std::cout<<"\nStatus: Success"<<std::endl;
	return 0;
}