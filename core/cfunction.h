/**
* @file cfunction.hpp
* @brief CFunction class interface.
*
*/

#ifndef CFUNCTION_H
#define CFUNCTION_H

#include <QList>

//forward declaration
namespace data
{
    class IDataColumn;
} //namespace data

//forward declaration
namespace core
{
    //struct SParamInfo;
}

namespace core
{
    class CFunction
    {
    public:
        enum EType
        {
            eMinimum,
            eMaximum,
            eAverage,
            eMedian, //equal to Q2
            eStdDev, //standard deviation
            eQ1,
            eQ2,     //equal to eMedian
            eQ3
        };

    public:
        /**
        * @brief The constructor.
        **/
        CFunction()
        {}

        /**
        * @brief This function configures the CFunction correspondingly to passed argument.
        * @note This function must be called before using any functionality of CFunction.
        * @param[in] ql is the column data.
        */
        void configur(const QList<EType> ql);

        /**
        * @brief This function computes the data passed by argument.
        * @pre The function configure must be called before.
        * @param[in] c is the column data.
        * @return Returns the results in ParamInfo container.
        */
        //core::SParamInfo compute(const data::IDataColumn* c);

    private:
        /**
        * @brief This function calculates the minimum.
        * @param[in] v is the sorted array of values.
        */
        double calculate_minimum(const QVector<double>& v);

        /**
        * @brief This function calculates the median.
        * @param[in] v is the sorted array of values.
        */
        double calculate_median(const QVector<double>& v);

        /**
        * @brief This function calculates the maximum.
        * @param[in] v is the sorted array of values.
        */
        double calculate_maximum(const QVector<double>& v);

        /**
        * @brief This function calculates the average.
        * @param[in] v is the sorted array of values.
        */
        double calculate_average(const QVector<double>& v);

        /**
        * @brief This function calculates the standart deviation.
        * @param[in] v is the sorted array of values.
        */
        double calculate_stddev(const QVector<double>& v);

        /**
        * @brief This function calculates the Q1.
        * @param[in] v is the sorted array of values.
        */
        double calculate_q1(const QVector<double>& v);

        /**
        * @brief This function calculates the Q2.
        * @param[in] v is the sorted array of values.
        */
        double calculate_q2(const QVector<double>& v);

        /**
        * @brief This function calculates the Q3 which equals to median.
        * @param[in] v is the sorted array of values.
        */
        double calculate_q3(const QVector<double>& v);

    private:
        /**
        * @brief This function sorts and stores the IDataColumn data into vector.
        * @param[in] c is the container which must be sorted.
        * @param[out] v is the sorted array of values.
        */
        void copy_sort_data(const data::IDataColumn* c, QVector<double>& qv);

    private:
        QList<EType> m_qtype;

    };

} //namespace core

#endif //CFUNCTION_H
