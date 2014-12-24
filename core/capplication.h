# CApplication - main class
#ifndef CAPPLICATION_H
#define CAPPLICATION_H

/**
* @file capplication.h
* @brief CApplication class interface.
*/

#include <QApplication>

namespace core {

class CModule;

class CApplication : public QApplication
{
    Q_OBJECT
public:
    /**
     * @brief CApplication
     * @param parent
     */
    explicit CApplication(int & argc, char ** argv);

public:
    /**
     * @brief openFile
     * @param sPath
     * @return
     */
    bool openFile(QString const& sPath);

public:
    /**
     * @brief getAvailableParameters
     * @return
     */
    QStringList getAvailableParameters() const;

public:
    /**
     * @brief run
     * @param aSelectedParameters
     * @param pErrorMsg
     * @return
     */
    bool run(QStringList const& aSelectedParameters, QString &pErrorMsg);

private:
    CModule*	m_pModule;

};

} // namespace core

#endif // CAPPLICATION_H
