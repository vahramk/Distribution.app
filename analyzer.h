//# Distribution analyzer class
//# Analyzes selected parameters and keeps results

#ifndef CANALYZER_H
#define CANALYZER_H

#include "data/idatatable.h"
#include "parameterstore.h"

class CAnalalyzer: public data::IDataTable
{
public:
	
	CAnalalyzer (const IDataTable*, CParameterStore* );
	void analyze();

private:

	void CountMin();
	void ConutMAx();
	
	const IDataTable* m_pIdataTbl;
};
#endif // CANALYZER_H