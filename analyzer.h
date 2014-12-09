#ifndef ANALYZER_H
#define ANALYZER_H

#include "data/idatatable.h"
#include "chart/cchart.h"
class CAnalyzer
{
public:
		CAnalyzer();
		void run();
		void set data(IDataTable*);


private:
		IDataTable*		m_pIdataTbl;
		CChart* 		m_pChart;
		CFunction*		m_pFunc;

};
#endif // CCPARAMETER_H