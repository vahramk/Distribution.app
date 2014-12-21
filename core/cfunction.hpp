/**
* @file cfunction.hpp
* @brief CFunction class interface.
*
*/

#ifndef CFUNCTION_H
#define CFUNCTION_H

#include <QList>

namespace core
{
    class IDataColumn; //forward declaration
    //struct SParamInfo; //frome the project Analyser

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
            eQ2,
            eQ3      //equal to eMedian
        };

    public:
        /**
        * @brief This function configures the CFunction correspondingly to passed argument.
        * @note This function must be called before using any functionality of CFunction.
        * @param[in] ql is the column data.
        */
        void configur(QList<EType> ql);

        /**
        * @brief This function computes the data passed by argument.
        * @pre The function configure must be called before.
        * @param[in] c is the column data.
        * @return Returns the results in ParamInfo container.
        */
        //ParamInfo compute(IDataColumn* c);
    };

} //namespace core

#endif //CFUNCTION_H
