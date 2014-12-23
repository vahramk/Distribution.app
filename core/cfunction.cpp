/**
* @file cfunction.cpp
* @brief Implementation of the CFunction cless.
*
*/

#include "cfunction.h"

//#include <core/parameterstore.h>
#include <data/idatalayer.h>

#include <cmath>

namespace core
{
    void CFunction::configur(const QList<CFunction::EType> ql)
    {
        for (int i = 0; i < ql.size(); ++i)
        {
            m_qtype.push_back(ql.at(i));
        }
    }

    double CFunction::calculate_minimum(const QVector<double>& v)
    {
        Q_ASSERT(!v.empty());
        return v.at(0);
    }

    double CFunction::calculate_median(const QVector<double>& v)
    {
        Q_ASSERT(!v.empty());
        return calculate_q2(v);
    }

    double CFunction::calculate_maximum(const QVector<double>& v)
    {
        Q_ASSERT(!v.empty());
        return v.at(v.size()-1);
    }

    double CFunction::calculate_average(const QVector<double>& v)
    {
        Q_ASSERT(!v.empty());
        double sum = 0;
        for(int i=0; i<v.size(); ++i)
        {
            sum+=v.at(i);
        }
        return sum/v.size();
    }

    double CFunction::calculate_stddev(const QVector<double>& v)
    {
        Q_ASSERT(!v.empty());
        double sdv=0;
        double tmp_sqr=0;
        double sum=0;
        for(int i=0; i<v.size(); ++i)
        {
            sum+=v.at(i);
            tmp_sqr+=pow(v.at(i),2);
        }
        sdv=sqrt(tmp_sqr - sum);
        return sdv;
    }

    double CFunction::calculate_q1(const QVector<double>& v)
    {
        Q_ASSERT(!v.empty());
        return v.at(int(v.size()/4));
    }

    double CFunction::calculate_q2(const QVector<double>& v) //median
    {
        Q_ASSERT(!v.empty());
        return v.at(int(v.size()/2));
    }

    double CFunction::calculate_q3(const QVector<double>& v)
    {
        Q_ASSERT(!v.empty());
        return v.at(int(3*v.size()/4));
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
    core::SParamInfo CFunction::compute(const data::IDataColumn* c)
    {
        typedef core::SParamInfo tS;
        QVector<double> v;
        copy_sort_data<int>(c, v);
        tS::t_aStatistics spi;
        for(int i=0; i<m_qtype.size(); ++i)
        {
            tS::t_parNameValue result;
            switch (m_qtype[i])
            {
                case eMinimum:
                    result.first = "eMinimum";
                    result.second = calculate_minimum(v);
                    break;
                case eMaximum:
                    result.first = "eMaximum";
                    result.second = calculate_maximum(v);
                    break;
                case eAverage:
                    result.first = "eAverage";
                    result.second = calculate_average(v);
                    break;
                case eMedian:
                    result.first = "eMedian";
                    result.second = calculate_median(v);
                    break;
                case eStdDev:
                    result.first = "eStdDev";
                    result.second = calculate_stddev(v);
                    break;
                case eQ1:
                    result.first = "eQ1";
                    result.second = calculate_q1(v);
                    break;
                case eQ2:
                    result.first = "eQ2";
                    result.second = calculate_q2(v);
                    break;
                case eQ3:
                    result.first = "eQ3";
                    result.second = calculate_q3(v);
                    break;
                default:
                    Q_ASSERT(false);
                    break;
            }
            sp.push_back(result); //, c !!
        }
        return spi;
    }
*/

} //namespace core
