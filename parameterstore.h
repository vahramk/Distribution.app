//# Store of analyzed results of parameters - implemnents IDataTable interface
//#include "data/idatatable.h"

#ifndef CPARAMETER_H
#define CPARAMETER_H

#include "data/idatatable.h"
#include <QList>
#include <QPair>

struct SParamInfo
{
	typedef QPair<QString, double> t_parNameValue;
	typedef QVector<t_parNameValue> t_aStatistics;
};

class CParameterStore: public data::IDataTable
{
public:
		void addData(QList<SParamInfo>& );
		QList<SParamInfo> getData();
		size_t getRowCount();
		size_t getColumnCount();
		QString getColumnName();


		
		
};
#endif // CCPARAMETER_H