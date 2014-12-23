/**
* @file cfunction.cpp
* @brief Implementation of the CFunction cless.
*
*/

#include "cfunction.hpp"
#include <data/idatalayer.h>
//create folder
//#include <../parameterstore.h>

namespace core
{

    void CFunction::configur(const QList<CFunction::EType> ql)
    {
        for (int i = 0; i < ql.size(); ++i)
        {
            m_qtype.push_back(ql.at(i));
        }
    }

    double calculate_minimum(const QVector<double>& v)
    {
        Q_ASSERT(!v.empty());
        return v.at(0);
    }

    double calculate_maximum(const QVector<double>& v)
    {
        Q_ASSERT(!v.empty());
        return v.at(v.size()-1);
    }

    double calculate_average(const QVector<double>& v)
    {
        double sum = 0;
        for(int i=0; i<v.size(); ++i)
        {
            sum+=v.at(i);
        }
        return sum/v.size();
    }

    //double calculate_stddev(const QVector<double>& v);
    //double calculate_q1(const QVector<double>& v);
    //double calculate_q2(const QVector<double>& v);

    double calculate_q3(const QVector<double>& v) //median
    {
        return v.at(v.size()/2);
    }

    void CFunction::copy_sort_data(const data::IDataColumn* c, QVector<double>& qv)
    {
        for (int i=0; i < c->getSize(); ++i)
        {
            double val=0;
            c->getData(i,val);
            qv.push_back(val);
        }
        std::sort(qv.begin(), qv.end());
    }

    /*
    SParamInfo CFunction::compute(const IDataColumn* c)
    {
        QVector<double> v;
        copy_sort_data<int>(c, v);

        //need interface.
        SParamInfo sp;
        for(int i=0; i<m_qtype.size(); ++i)
        {
            switch case m_qtype EType
            sp.add(type, c);
        }

    }
    */

} //namespace core
