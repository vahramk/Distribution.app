/// CApplication - main class
#ifndef APPLICATION_H
#define APPLICATION_H

/**
* @file application.h
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

#endif // APPLICATION_H
