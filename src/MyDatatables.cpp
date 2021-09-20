/************************************************
* @file MyDatatables.cpp
* @brief My SQL Datatables,
* MyDatatables is used to select and implement SQL databases,
* I check variables before setting them to prevent triggers.
* @author Jeffrey Scott Flesher <Jeffrey.Scott.Flesher@>
 ***********************************************/
#include "MyDatatables.h"
#include "MyDatatables.h"

/************************************************
 * @brief My Datatables Constructor.
 * MyDatatables
 ***********************************************/
MyDatatables::MyDatatables(MyLanguageModel *thisLanguageModel, QObject *parent) : QObject(parent), myLanguageModel(thisLanguageModel)
{
    // Create Variable Trackers and Set to Empty
    myProject  = new MyProjectClass("", "", "", "", "", "", "", "", "", "", "");
    myProgress = new MyProgressClass("", "", "");
    // Trigger for Update
    connect(this, &MyDatatables::sendUpdateDatabase, this, &MyDatatables::onUpdateDatabase);
}
/************************************************
 * @brief My Datatables Deconstructor.
 * MyDatatables
 ***********************************************/
MyDatatables::~MyDatatables()
{

}
/************************************************
 * @brief on Update Database.
 * onUpdateDatabase
 ***********************************************/
void MyDatatables::onUpdateDatabase()
{
    // FIXME what to do
}
/************************************************
 * @brief set Debug Message.
 * setDebugMessage
 ***********************************************/
void MyDatatables::setDebugMessage(bool thisState)
{
    myLanguageModel->mySetting->setMessage("setDebugMessage", QString("%1(%2)").arg("setDebugMessage", thisState), myLanguageModel->mySetting->Debug);
    if (isDebugMessage != thisState)
        { isDebugMessage = thisState; }
}
/************************************************
 * @brief get Debug Message.
 * getDebugMessage
 ***********************************************/
bool MyDatatables::getDebugMessage()
{
    myLanguageModel->mySetting->setMessage("getDebugMessage", QString("%1(%2)").arg("getDebugMessage", isDebugMessage), myLanguageModel->mySetting->Debug);
    return isDebugMessage;
}
/************************************************
 * @brief set Date Started.
 * setDateStarted
 ***********************************************/
void MyDatatables::setDateStarted(const QString &thisDateStarted)
{
    myLanguageModel->mySetting->setMessage("setDateStarted", QString("%1(%2)").arg("setDateStarted", thisDateStarted), myLanguageModel->mySetting->Debug);
    if (QString::compare(myDateStarted, thisDateStarted, Qt::CaseInsensitive))
        { myDateStarted = thisDateStarted; }
}
/************************************************
 * @brief get Date Started.
 * getDateStarted
 ***********************************************/
QString MyDatatables::getDateStarted()
{
    myLanguageModel->mySetting->setMessage("getDateStarted", QString("%1(%2)").arg("getDateStarted", myDateStarted), myLanguageModel->mySetting->Debug);
    return myDateStarted;
}
/************************************************
 * @brief set Project Name.
 * setProjectName
 ***********************************************/
void MyDatatables::setProjectName(const QString &thisProjectName)
{
    myLanguageModel->mySetting->setMessage("setProjectName", QString("%1(%2)").arg("setProjectName", thisProjectName), myLanguageModel->mySetting->Debug);
    if (QString::compare(myProjectName, thisProjectName, Qt::CaseInsensitive))
        { myProjectName = thisProjectName; }
}
/************************************************
 * @brief get Project Name.
 * getProjectName
 ***********************************************/
QString MyDatatables::getProjectName()
{
    myLanguageModel->mySetting->setMessage("getProjectName", QString("%1(%2)").arg("getProjectName", myProjectName), myLanguageModel->mySetting->Debug);
    if (myProjectName.isEmpty())
        { setProjectName(myLanguageModel->mySetting->getAppName()); }
    return myProjectName;
}
/************************************************
 * @brief set Project Status.
 * setProjectStatus
 ***********************************************/
void MyDatatables::setProjectStatus(const QString &thisProjecStatus)
{
    myLanguageModel->mySetting->setMessage("setProjectStatus", QString("%1(%2)").arg("setProjectStatus", thisProjecStatus), myLanguageModel->mySetting->Debug);
    if (QString::compare(myStatusName, thisProjecStatus, Qt::CaseInsensitive))
        { myStatusName = thisProjecStatus; }
}
/************************************************
 * @brief get Project Status.
 * getProjectStatus
 ***********************************************/
QString MyDatatables::getProjectStatus()
{
    myLanguageModel->mySetting->setMessage("getProjectStatus", QString("%1(%2)").arg("getProjectStatus", myStatusName), myLanguageModel->mySetting->Debug);
    if (myStatusName.isEmpty())
        { setProjectStatus(getProjectDefaultStatus()); }
    return myStatusName;
}
/************************************************
 * @brief set Project Default Status.
 * setProjectDefaultStatus
 ***********************************************/
void MyDatatables::setProjectDefaultStatus(const QString &thisProjecDefaultStatus)
{
    myLanguageModel->mySetting->setMessage("setProjectDefaultStatus", QString("%1(%2)").arg("setProjectDefaultStatus", thisProjecDefaultStatus), myLanguageModel->mySetting->Debug);
    if (QString::compare(myDefaultStatusName, thisProjecDefaultStatus, Qt::CaseInsensitive))
        { myDefaultStatusName = thisProjecDefaultStatus; }
}
/************************************************
 * @brief get Project Default Status.
 * getProjectDefaultStatus
 ***********************************************/
QString MyDatatables::getProjectDefaultStatus()
{
    myLanguageModel->mySetting->setMessage("getProjectDefaultStatus", QString("%1(%2)").arg("getProjectDefaultStatus", myDefaultStatusName), myLanguageModel->mySetting->Debug);
    if (myDefaultStatusName.isEmpty())
        { setProjectDefaultStatus(MY_DEFAULT_STATUS); }
    return myDefaultStatusName;
}
/************************************************
 * @brief set Project ID.
 * setProjectID
 ***********************************************/
void MyDatatables::setProjectID(const QString &thisProjectID)
{
    myLanguageModel->mySetting->setMessage("setProjectID", QString("%1(%2)").arg("setProjectID", thisProjectID), myLanguageModel->mySetting->Debug);
    if (QString::compare(myProjectID, thisProjectID, Qt::CaseInsensitive))
        { myProjectID = thisProjectID; }
}
/************************************************
 * @brief get Project ID.
 * getProjectID
 ***********************************************/
QString MyDatatables::getProjectID()
{
    myLanguageModel->mySetting->setMessage("getProjectID", QString("%1(%2)").arg("getProjectID", myProjectID), myLanguageModel->mySetting->Debug);
    return myProjectID;
}
/************************************************
 * @brief set ComboBox Sql Value.
 * setComboBoxSqlValue
 ***********************************************/
void MyDatatables::setComboBoxSqlValue(const QString &thisComboBoxSqlValue)
{
    myLanguageModel->mySetting->setMessage("setComboBoxSqlValue", QString("%1(%2)").arg("setComboBoxSqlValue", thisComboBoxSqlValue), myLanguageModel->mySetting->Debug);
    if (QString::compare(mySqlDriver, thisComboBoxSqlValue, Qt::CaseInsensitive))
    {
        setSqlDriver(thisComboBoxSqlValue);
        emit sendUpdateDatabase();
    }
}
/************************************************
 * @brief get ComboBox Sql Value.
 * getComboBoxSqlValue
 ***********************************************/
QString MyDatatables::getComboBoxSqlValue()
{
    myLanguageModel->mySetting->setMessage("getComboBoxSqlValue", QString("%1(%2)").arg("getComboBoxSqlValue", mySqlDriver), myLanguageModel->mySetting->Debug);
    return mySqlDriver;
}
/************************************************
 * @brief is Db Table.
 * isDbTable
 ***********************************************/
bool MyDatatables::isDbTable(const QString &thisTable)
{
    myLanguageModel->mySetting->setMessage("isDbTable", QString("%1(%2)").arg("isDbTable", thisTable), myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    QStringList theTables = myDb.tables();
    if (theTables.contains(thisTable, Qt::CaseInsensitive))  { return true; }
    else                                                     { return false; }
    #else
    return true;
    #endif
}
#ifdef USE_SQL_FLAG
/************************************************
 * @brief set Sql Database.
 * setSqlDatabase
 ***********************************************/
void MyDatatables::setSqlDatabase(QSqlDatabase thisDatabase)
{
    myLanguageModel->mySetting->setMessage("setSqlDatabase", QString("%1(%2)").arg("setSqlDatabase", thisDatabase.databaseName()), myLanguageModel->mySetting->Debug);
    // FIXME compare to databases
    myDb = thisDatabase;
}
/************************************************
 * @brief get Sql Database.
 * getSqlDatabase
 ***********************************************/
QSqlDatabase MyDatatables::getSqlDatabase()
{
    myLanguageModel->mySetting->setMessage("getSqlDatabase", QString("%1(%2)").arg("getSqlDatabase", myDb.databaseName()), myLanguageModel->mySetting->Debug);
    return myDb;
}
#endif
/************************************************
 * @brief get Sql Driver.
 * getSqlDriver
 ***********************************************/
QString MyDatatables::getSqlDriver()
{
    myLanguageModel->mySetting->setMessage("getSqlDriver", QString("%1(%2)").arg("getSqlDriver", mySqlDriver), myLanguageModel->mySetting->Debug);
    return mySqlDriver;
}
/************************************************
 * @brief set Sql Table Name.
 * setSqlTableName
 ***********************************************/
void MyDatatables::setSqlTableName(const QString &thisTableName)
{
    myLanguageModel->mySetting->setMessage("setSqlTableName", QString("%1(%2)").arg("setSqlTableName", thisTableName), myLanguageModel->mySetting->Debug);
    if (QString::compare(myTableName, thisTableName, Qt::CaseInsensitive))
    {
        myTableName = thisTableName;
        emit sendUpdateDatabase();
    }
}
/************************************************
 * @brief get Sql Table Name.
 * getSqlTableName
 ***********************************************/
QString MyDatatables::getSqlTableName()
{
    myLanguageModel->mySetting->setMessage("getSqlTableName", QString("%1(%2)").arg("getSqlTableName", myTableName), myLanguageModel->mySetting->Debug);
    return myTableName;
}
/************************************************
 * @brief set Sql Host Name.
 * setSqlHostName
 ***********************************************/
void MyDatatables::setSqlHostName(const QString &thisHostName)
{
    myLanguageModel->mySetting->setMessage("setSqlHostName", QString("%1(%2)").arg("setSqlHostName", thisHostName), myLanguageModel->mySetting->Debug);
    if (QString::compare(myHostName, thisHostName, Qt::CaseInsensitive))
    {
        myHostName = thisHostName;
        emit sendUpdateDatabase();
    }
}
/************************************************
 * @brief get Sql Host Name.
 * getSqlHostName
 ***********************************************/
QString MyDatatables::getSqlHostName()
{
    myLanguageModel->mySetting->setMessage("getSqlHostName", QString("%1(%2)").arg("getSqlHostName", myHostName), myLanguageModel->mySetting->Debug);
    return myHostName;
}
/************************************************
 * @brief set Sql User Name.
 * setSqlUserName
 ***********************************************/
void MyDatatables::setSqlUserName(const QString &thisUserName)
{
    myLanguageModel->mySetting->setMessage("setSqlUserName", QString("%1(%2)").arg("setSqlUserName", thisUserName), myLanguageModel->mySetting->Debug);
    if (QString::compare(myUserName, thisUserName, Qt::CaseInsensitive))
    {
        myUserName = thisUserName;
        emit sendUpdateDatabase();
    }
}
/************************************************
 * @brief get Sql User Name.
 * getSqlUserName
 ***********************************************/
QString MyDatatables::getSqlUserName()
{
    myLanguageModel->mySetting->setMessage("getSqlUserName", QString("%1(%2)").arg("getSqlUserName", myUserName), myLanguageModel->mySetting->Debug);
    return myUserName;
}
/************************************************
 * @brief set Sql Database Name.
 * setSqlDatabaseName
 ***********************************************/
void MyDatatables::setSqlDatabaseName(const QString &thisDatabaseName)
{
    myLanguageModel->mySetting->setMessage("setSqlDatabaseName", QString("%1(%2)").arg("setSqlDatabaseName", thisDatabaseName), myLanguageModel->mySetting->Debug);
    if (QString::compare(myDatabaseName, thisDatabaseName, Qt::CaseInsensitive))
    {
        myDatabaseName = thisDatabaseName;
        emit sendUpdateDatabase();
    }
}
/************************************************
 * @brief get Sql Database Name.
 * getSqlDatabaseName
 ***********************************************/
QString MyDatatables::getSqlDatabaseName()
{
    myLanguageModel->mySetting->setMessage("getSqlDatabaseName", QString("%1(%2)").arg("getSqlDatabaseName", myDatabaseName), myLanguageModel->mySetting->Debug);
    if (myDatabaseName.isEmpty())
    {
        if (mySqlDriver == myLanguageModel->mySetting->MY_SQL_DEFAULT)
        {
            setSqlDatabaseName(getSqlLiteDbName());
        }
        else
        {
            if (getSqlDriver() == ":memory:")
            {
                setSqlDatabaseName(":memory:");
            }
            else
            {
                setSqlDatabaseName(getSqlHostName()); // localhost
            }
        }
    }
    return myDatabaseName;
}
/************************************************
 * @brief get SqlLite Db Name.
 * getSqlLiteDbName
 ***********************************************/
QString MyDatatables::getSqlLiteDbName()
{
    myLanguageModel->mySetting->setMessage("getSqlLiteDbName", "getSqlLiteDbName", myLanguageModel->mySetting->Debug);
    return QString("%1%2%3.db").arg(myLanguageModel->mySetting->getAppDataLocation(), QDir::separator(), myLanguageModel->mySetting->getAppName());
}
/************************************************
 * @brief set Sql Password.
 * setSqlPassword
 ***********************************************/
void MyDatatables::setSqlPassword(const QString &thisPassword)
{
    myLanguageModel->mySetting->setMessage("setSqlPassword", "setSqlPassword", myLanguageModel->mySetting->Debug);
    if (QString::compare(myPassword, thisPassword, Qt::CaseInsensitive))
    {
        myPassword = thisPassword;
        emit sendUpdateDatabase();
    }
}
/************************************************
 * @brief get Sql Password.
 * getSqlPassword
 ***********************************************/
QString MyDatatables::getSqlPassword()
{
    myLanguageModel->mySetting->setMessage("getSqlPassword", "getSqlPassword", myLanguageModel->mySetting->Debug);
    return myPassword;
}
/************************************************
 * @brief set Connection Name.
 * setConnectionName
 ***********************************************/
void MyDatatables::setConnectionName(const QString &thisConnectionName)
{
    myLanguageModel->mySetting->setMessage("set Connection Name", QString("%1(%2)").arg("setConnectionName", thisConnectionName), myLanguageModel->mySetting->Debug);
    if (QString::compare(myConnectionName, thisConnectionName, Qt::CaseInsensitive))
    {
        myConnectionName = thisConnectionName;
        emit sendUpdateDatabase();
    }
}
/************************************************
 * @brief get Record ID is myInsertID.
 * getRecordID
 ***********************************************/
QString MyDatatables::getRecordID()
{
    myLanguageModel->mySetting->setMessage("get Record ID", QString("%1(%2)").arg("getRecordID", myInsertID), myLanguageModel->mySetting->Debug);
    return myInsertID;
}
/************************************************
 * @brief set Record ID.
 * setRecordID
 ***********************************************/
void MyDatatables::setRecordID(const QString &thisRecordID)
{
    myLanguageModel->mySetting->setMessage("setRecordID", QString("%1(%2)").arg("setRecordID", thisRecordID), myLanguageModel->mySetting->Debug);
    if (QString::compare(myInsertID, thisRecordID, Qt::CaseInsensitive))
        { myInsertID = thisRecordID; }
}
/************************************************
 * @brief get Connection Name.
 * getConnectionName
 ***********************************************/
QString MyDatatables::getConnectionName()
{
    myLanguageModel->mySetting->setMessage("get Connection Name", QString("%1(%2)").arg("getConnectionName", myConnectionName), myLanguageModel->mySetting->Debug);
    return myConnectionName;
}
/************************************************
 * @brief set Database Connection.
 * setDatabaseConnection
 ***********************************************/
void MyDatatables::setDatabaseConnection(const QString &thisDatabaseConnection)
{
    myLanguageModel->mySetting->setMessage("set Database Connection", QString("%1(%2)").arg("setDatabaseConnection", thisDatabaseConnection), myLanguageModel->mySetting->Debug);
    if (QString::compare(myDatabaseConnection, thisDatabaseConnection, Qt::CaseInsensitive))
    {
        myDatabaseConnection = thisDatabaseConnection;
        emit sendUpdateDatabase();
    }
}
/************************************************
 * @brief get Database Connection.
 * getDatabaseConnection
 ***********************************************/
QString MyDatatables::getDatabaseConnection()
{
    myLanguageModel->mySetting->setMessage("get Database Connection", QString("%1(%2)").arg("getDatabaseConnection", myDatabaseConnection), myLanguageModel->mySetting->Debug);
    return myDatabaseConnection;
}
/************************************************
 * @brief set Sql Driver setSqlDriver(":memory:");.
 * setSqlDriver
 ***********************************************/
bool MyDatatables::setSqlDriver(const QString &thisDriver)
{
    myLanguageModel->mySetting->setMessage("set Sql Driver", QString("%1(%2)").arg("setSqlDriver", thisDriver), myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    QString theDriver = thisDriver;
    QString theNewDriver = thisDriver;
    if (theDriver.length() == 0)  { theDriver = myLanguageModel->mySetting->MY_SQL_DEFAULT; }
    // Check for Database memory setting
    // ui->checkBoxSettingsMemory->isChecked() || combobox
    // Database Driver
    if (theDriver == ":memory:")
    {
        // SQLite version 3 SQLite version 2 Note: obsolete since Qt 5.14
        theNewDriver = theDriver;
    }
    else if (theDriver == "QSQLITE" || theDriver == "QSQLITE2")
    {
        // SQLite version 3 SQLite version 2 Note: obsolete since Qt 5.14
        theNewDriver = theDriver;
    }
    else if (theDriver == "QMYSQL" || theDriver == "MARIADB")
    {
        // MySQL or MariaDB (version 5.0 and above)
        theNewDriver = theDriver;
    }
    else if (theDriver == "QPSQL")
    {
        // PostgreSQL (versions 7.3 and above)
        theNewDriver = theDriver;
    }
    else if (theDriver == "QDB2")
    {
        // IBM DB2 (version 7.1 and above)
        theNewDriver = theDriver;
    }
    else if (theDriver == "QIBASE")
    {
        // Borland InterBase
        theNewDriver = theDriver;
    }
    else if (theDriver == "QOCI")
    {
        // Oracle Call Interface Driver
        theNewDriver = theDriver;
    }
    else if (theDriver == "QTDS")
    {
        // Sybase Adaptive Server - Note: obsolete since Qt 4.7
        theNewDriver = theDriver;
    }
    else
    {
        myLanguageModel->mySetting->setMessage("set Sql Driver", QString("%1").arg(tr("setSqlDriver Driver not found")), myLanguageModel->mySetting->Critical);
        theNewDriver = theDriver;
        return false;
    }
    // Only change value if needed
    if (QString::compare(mySqlDriver, theNewDriver, Qt::CaseInsensitive))
    {
        mySqlDriver = theNewDriver;
        myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_TYPE, theNewDriver);
    }
    #endif
    return true;
} // end setSqlDriver
/************************************************
 * @brief create Database Connection.
 * createDatabaseConnection
 ***********************************************/
bool MyDatatables::createDatabaseConnection(const QString &thisDatabaseConnection)
{
    myLanguageModel->mySetting->setMessage("create Database Connection", "createDatabaseConnection", myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    // Make sure Drive is set
    if (mySqlDriver == "NOTSET") { setSqlDriver(myLanguageModel->mySetting->MY_DEFAULT_SQL); }
    myDatabaseConnection = thisDatabaseConnection;
    // Database Driver
    if (mySqlDriver == ":memory:")
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE"); //!< set myDb SQLite
        myDb.setDatabaseName(":memory:");
    }
    else
    {
        if (mySqlDriver == "QSQLITE" || mySqlDriver == "QSQLITE2")
        {   //!< set myDb QSQLITE or QSQLITE2
            // SQLite version 3 and SQLite version 2 Note: obsolete since Qt 5.14
            if (myDatabaseConnection.isEmpty())
            {
                myDatabaseConnection = QString("Project").arg(myLanguageModel->mySetting->getAppDataLocation(), QDir::separator(), myLanguageModel->mySetting->getAppName());
            }
            QString thePath = myLanguageModel->mySetting->getFileInfo(myLanguageModel->mySetting->AbsolutePath, myDatabaseConnection);
            QString theFileName = myLanguageModel->mySetting->getFileInfo(myLanguageModel->mySetting->FileName, myDatabaseConnection);

            if (myDatabaseConnection.contains(".db"))
            {
                if (!myLanguageModel->mySetting->isPathExists(thePath))
                {
                    thePath = myLanguageModel->mySetting->getAppDataLocation();
                }
                if (theFileName.isEmpty())
                {
                    theFileName = myLanguageModel->mySetting->getAppName();
                }

                myDatabaseConnection = myLanguageModel->mySetting->combinePathFileName(thePath, theFileName);

            }
            else
            {
                myDatabaseConnection = getSqlLiteDbName();
            }
            //
            myDb = QSqlDatabase::addDatabase(mySqlDriver); //!< set myDb SQLite
            myDb.setDatabaseName(myDatabaseConnection);
            //    myDb.setHostName(getSqlHostName());
            //    myDb.setUserName(getSqlUserName());
            //    myDb.setPassword(getSqlPassword());
            //
        }
        else if (mySqlDriver == "QDB2")
        {   //!< set myDb QDB2
            // IBM DB2 (version 7.1 and above)
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else if (mySqlDriver == "QIBASE")
        {   //!< set myDb QIBASE
            // Borland InterBase
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else if (mySqlDriver == "QMYSQL" || mySqlDriver == "MARIADB")
        {   //!< set myDb QMYSQL or MARIADB
            // MySQL or MariaDB (version 5.0 and above)
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else if (mySqlDriver == "QOCI")
        {   //!< set myDb QOCI
            // Oracle Call Interface Driver
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else if (mySqlDriver == "QPSQL")
        {   //!< set myDb QPSQL
            // PostgreSQL (versions 7.3 and above)
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else if (mySqlDriver == "QTDS")
        {   //!< set myDb QTDS
            // Sybase Adaptive Server - Note: obsolete since Qt 4.7
            myDb = QSqlDatabase::addDatabase(mySqlDriver, myConnectionName);
            myDb.setHostName(getSqlHostName());
            myDb.setDatabaseName(getSqlDatabaseName());
            myDb.setUserName(getSqlUserName());
            myDb.setPassword(getSqlPassword());
        }
        else
        {
            myLanguageModel->mySetting->showMessageBox(tr("Database SQL Driver not found").toLocal8Bit(), tr("Debug program").toLocal8Bit(), myLanguageModel->mySetting->Critical);
        }
    } // end ! if (:memory:)
    if (!myDb.open())
    {
        if(!QSqlDatabase::isDriverAvailable(mySqlDriver))
        {
            myLanguageModel->mySetting->showMessageBox(tr("Database SQL Driver is missing").toLocal8Bit(), QString("%1 %2").arg(tr("Install SQL").toLocal8Bit(), mySqlDriver), myLanguageModel->mySetting->Critical);
            return false;
        }
        else
        {
            myLanguageModel->mySetting->showMessageBox(QString("%1: %2").arg(tr("Cannot open database"), myDb.lastError().text()).toLocal8Bit(), tr("Unable to establish a database connection").toLocal8Bit(), myLanguageModel->mySetting->Critical);
            return false;
        }
    }
    // Set Settings
    if (mySqlDriver != ":memory:")
    {
        myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_NAME, myDatabaseConnection);
    }
    #endif
    return true;
} // end createDatabaseConnection
/************************************************
 * @brief Set myInsertID, returns true or false.
 * runQuery
 ***********************************************/
bool MyDatatables::runQuery(const QString &thisQuery)
{
    myLanguageModel->mySetting->setMessage("runQuery", QString("%1(%2)").arg("runQuery", thisQuery), myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    QSqlQuery theQuery; //!< SQL Query
    if (theQuery.exec(thisQuery))
    {
        setRecordID(theQuery.lastInsertId().toString());
        return true;
    }
    else
    {
        myLanguageModel->mySetting->setMessage("on comboBox Sql Database Type current Index Changed", QString("%1: %2 - %3 - %4 - %5 - %6").arg(QObject::tr("Error running Query"), "runQuery", theQuery.lastError().text(), QObject::tr("SqLite error code"), theQuery.lastError().text(), thisQuery), MyOrgSettings::MyMessageTypes::Critical);
        setRecordID("-1");
        return false;
    }
    #else
    return true;
    #endif
}
/************************************************
 * @brief move Db.
 * moveDb
 ***********************************************/
bool MyDatatables::moveDb(const QString &thisSourceFile,const QString &thisSourcePath, const QString &thisDescription)
{
    myLanguageModel->mySetting->setMessage("moveDb", QString("%1(%2, %3, %4)").arg("moveDb", thisSourceFile, thisSourcePath, thisDescription), myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    QFile file(QString("%1%2%3").arg(thisSourcePath, QDir::separator(), thisSourceFile));
    //
    QString theNewDatabaseName = QString("%1%2%3").arg(thisDescription, QDir::separator(), thisSourceFile);
    //
    if (myLanguageModel->mySetting->isFileExists(theNewDatabaseName))
    {
        if (!myLanguageModel->mySetting->questionYesNo("Overwrite Database", "Are you sure you want to overwrite existing Database?"))
        {
            return true;
        }
    }
    //
    if (myDb.isOpen()) { myDb.close(); }
    if (file.rename(theNewDatabaseName))
    {
        myDatabaseName = theNewDatabaseName;
        return createDatabaseConnection(getSqlDriver());
    }
    else { return true; }
    #else
    return true;
    #endif
}
/************************************************
 * @brief run Procces given exe path, argument, and if you want to wait and how long,
 *        in both cases this is a blocking call and will wait till finished and return value.
 * runProcces
 ***********************************************/
QString MyDatatables::runProcces(const QString &thisExePath, const QString &thisArgument, bool isWait, int thisWaitTimeSec)
{
    myLanguageModel->mySetting->setMessage("runProcces", QString("%1(%2, %3, 4%)").arg("runProcces", thisExePath, thisArgument, QString::number(thisWaitTimeSec)), myLanguageModel->mySetting->Debug);
    QProcess *thisProcess = new QProcess(this);
    if (isWait)
    {
        thisProcess->start(thisExePath, QStringList() << thisArgument);
        // default wait time 30 sec
        if(!thisProcess->waitForStarted()) { qWarning() << tr("runProcces cannot start process"); }
        // wait time
        int waitTime = thisWaitTimeSec * 1000; // 60000 = 60 sec divide by 1000
        // now wait
        if (!thisProcess->waitForFinished(waitTime)) { qWarning() << tr("runProcces timeout .."); }
    }
    else
    {
        thisProcess->start(thisExePath, QStringList() << thisArgument);
        thisProcess->waitForFinished();
    }
    //
    thisProcess->setProcessChannelMode(QProcess::MergedChannels);
    myRunReturnCode = thisProcess->exitCode();
    return QString(thisProcess->readAllStandardOutput().simplified());
}
/************************************************
 * @brief get Run eturn Code.
 * getRunReturnCode
 ***********************************************/
int MyDatatables::getRunReturnCode()
{
    myLanguageModel->mySetting->setMessage("get Run Return Code", QString("%1(%2)").arg("getRunReturnCode", myRunReturnCode), myLanguageModel->mySetting->Debug);
    return myRunReturnCode;
}
/************************************************
 * @brief get DateTime Formated.
 * getDateTimeFormated
 * .toString(getDateTimeFormat())
 ***********************************************/
QDateTime MyDatatables::getDateTimeFromNow(int thisDaysFromNow)
{
    myLanguageModel->mySetting->setMessage("get Date Time Formated", QString("%1(%2)").arg("getDateTimeFormated", thisDaysFromNow), myLanguageModel->mySetting->Debug);
    if (thisDaysFromNow == 0)
        { return QDateTime::currentDateTime(); }
    return QDateTime::currentDateTime().addDays(thisDaysFromNow);
}
/************************************************
 * @brief get DateTime Format.
 * getDateTimeFormat
 ***********************************************/
QString MyDatatables::getDateTimeFormat()
{
    myLanguageModel->mySetting->setMessage("get Date Time Format", QString("%1(%2)").arg("getDateTimeFormat", myDateTimeFormat), myLanguageModel->mySetting->Debug);
    return myDateTimeFormat;
}
/************************************************
 * @brief set DateTime Format.
 * setDateTimeFormat
 ***********************************************/
void MyDatatables::setDateTimeFormat(const QString &thisDateTimeFormat)
{
    myLanguageModel->mySetting->setMessage("set Date Time Format", QString("%1(%2)").arg("setDateTimeFormat", thisDateTimeFormat), myLanguageModel->mySetting->Debug);
    if (QString::compare(myDateTimeFormat, thisDateTimeFormat, Qt::CaseInsensitive))
    {
        myDateTimeFormat = thisDateTimeFormat;
        emit sendUpdateDatabase();
    }
}
/************************************************
 * @brief insert Projects into SQL Database.
 * insertProjects
 ***********************************************/
bool MyDatatables::insertProjects()
{
    myLanguageModel->mySetting->setMessage("insert Projects", "insertProjects", myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    // ProjectName, DateStarted, DateDue, Description, Progress, Completed, Started, FormatStarted, FormatDue, Password, Approved, Assigned
    QString theQueryString = QLatin1String(R"(INSERT INTO Projects (ProjectName, DateStarted, DateDue, Description, Progress, Status, Completed, Started, FormatStarted, FormatDue, Password, Approved, Assigned) values(:ProjectName, :DateStarted, :DateDue, :Description, :Progress, :Status, :Completed, :Started, :FormatStarted, :FormatDue, :Password, :Approved, :Assigned))");
    myLanguageModel->mySetting->setMessage("insert Projects", QString("%1(%2)").arg("insertProjects", theQueryString), myLanguageModel->mySetting->Debug);
    QSqlQuery theQuery;
    theQuery.prepare(theQueryString);
    //theQuery.bindValue(":id", myProject->getID());                     // id: Update only
    theQuery.bindValue(":ProjectName",   myProject->getProjectName());   // ProjectName
    theQuery.bindValue(":DateStarted",   myProject->getDateStarted());   // DateStarted
    theQuery.bindValue(":DateDue",       myProject->getDateDue());       // DateDue
    theQuery.bindValue(":Description",   myProject->getDescription());   // Description
    theQuery.bindValue(":Progress",      myProject->getProgress());      // Progress
    theQuery.bindValue(":Status",        myProject->getStatus());        // Status
    theQuery.bindValue(":Completed",     myProject->getCompleted());     // Completed
    theQuery.bindValue(":Started",       myProject->getStarted());       // Started
    theQuery.bindValue(":FormatStarted", myProject->getFormatStarted()); // FormatStarted
    theQuery.bindValue(":FormatDue",     myProject->getFormatDue());     // FormatDue
    theQuery.bindValue(":Password",      myProject->getPassword());      // Password
    theQuery.bindValue(":Approved",      myProject->getApproved());      // Approved
    theQuery.bindValue(":Assigned",      myProject->getAssigned());      // Assigned
    if (theQuery.exec())
    {
        setRecordID(theQuery.lastInsertId().toString());
        return true;
    }
    else
    {
        myLanguageModel->mySetting->setMessage("insertProjects", QString("%1: %2 - %3 - %4 - %5 - %6").arg(QObject::tr("Error running Query"), "insertProjects", theQuery.lastError().text(), QObject::tr("SqLite error code"), theQuery.lastError().text(), theQueryString), MyOrgSettings::MyMessageTypes::Critical);
        setRecordID("-1");
        return false;
    }
    #else
    // FIXME now what local storage?
    #endif
    return true;
}
/************************************************
 * @brief addProject Assumes you have ran setProject: ProjectName, DateStarted, DateDue, Description, Progress, Completed, FormatStarted, FormatDue, Password, Approved, Assigned.
 * addProject
 ***********************************************/
bool MyDatatables::addProject()
{
    myLanguageModel->mySetting->setMessage("addProject", "addProject", myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    // SELECT id, ProjectName FROM Projects WHERE Project =
    if (isProjectNameQuery(myProject->getProjectName()))
    {
        myLanguageModel->mySetting->showMessageBox(QObject::tr("Record found!").toLocal8Bit(), QString("%1: %2").arg(tr("Not adding: Record found in database"), myProject->getProjectName()).toLocal8Bit(), myLanguageModel->mySetting->Warning);
        return false;
    }
    return insertProjects();
    #else
    return true;
    #endif
}
/************************************************
 * @brief delete Project.
 * deleteProject
 ***********************************************/
void MyDatatables::deleteProject(const QString &thisID)
{
    myLanguageModel->mySetting->setMessage("deleteProject", QString("%1(%2)").arg("deleteProject", thisID), myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    QSqlQuery query; //!< SQL Query
    QString theQuery = QString("DELETE FROM Projects WHERE id = ").append(thisID);
    myLanguageModel->mySetting->setMessage("delete Project Query", QString("%1(%2)").arg("deleteProjectQuery", theQuery), myLanguageModel->mySetting->Debug);
    if (query.exec(theQuery))
    {
        deleteProgressStatus(myProgress->getID());
    }
    else
    {
        myLanguageModel->mySetting->setMessage("deleteProject", QString("%1: %2 - %3 - %4 - %5)").arg(QObject::tr("SqLite error"), query.lastError().text(), QObject::tr("SqLite error code"), query.lastError().text(), thisID), myLanguageModel->mySetting->Critical);
    }
    #endif
}
/************************************************
 * @brief get Project Name Select Query SELECT id, ProjectName FROM Projects.
 * getProjectNameSelectQuery
 ***********************************************/
QString MyDatatables::getProjectNameSelectQuery()
{
    myLanguageModel->mySetting->setMessage("getProjectNameSelectQuery", QString("%1(%2)").arg("getProjectNameSelectQuery", "SELECT id, ProjectName FROM Projects"), myLanguageModel->mySetting->Debug);
    return QString("SELECT id, ProjectName FROM Projects");
}
/************************************************
 * @brief get Project Name By Name Query SELECT id, ProjectName FROM Projects WHERE ProjectName = ?.
 * getProjectNameByNameQuery
 ***********************************************/
QString MyDatatables::getProjectNameByNameQuery(const QString &thisProject)
{
    myLanguageModel->mySetting->setMessage("getProjectNameByNameQuery", QString("%1(%2)").arg("getProjectNameByNameQuery", thisProject), myLanguageModel->mySetting->Debug);
    return QString("SELECT id, ProjectName FROM Projects WHERE ProjectName = '%1'").arg(thisProject);
}
/************************************************
 * @brief is Project Name Query
 * isProjectNameQuery
 ***********************************************/
bool MyDatatables::isProjectNameQuery(const QString &thisProjectName)
{
    myLanguageModel->mySetting->setMessage("isProjectNameQuery", QString("%1(%2)").arg("isProjectNameQuery", thisProjectName), myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    QSqlQuery theQuery; //!< SQL Query
    QString theQueryCommand = getProjectNameByNameQuery(thisProjectName);
    if (theQuery.exec(theQueryCommand))
    {
        if (theQuery.first()) { return true;  }
        else                  { return false; }
    }
    else
    {
        myLanguageModel->mySetting->setMessage("isProjectNameQuery", QString("%1: %2 - %3 - %4 - %5").arg(QObject::tr("SqLite error isProjectQuery"), theQuery.lastError().text(), QObject::tr("SqLite error code"), theQuery.lastError().text(), thisProjectName), myLanguageModel->mySetting->Critical);
    }
    #endif
    return false;
}
/************************************************
 * @brief get Project Full Select Query ID SELECT * FROM Projects WHERE id =.
 * getProjectFullSelectQueryID
 ***********************************************/
QString MyDatatables::getProjectFullSelectQueryID(const QString &thisWhereID)
{
    myLanguageModel->mySetting->setMessage("getProjectFullSelectQueryID", QString("%1(%2)").arg("getProjectFullSelectQueryID = SELECT * FROM Projects WHERE id = ", thisWhereID), myLanguageModel->mySetting->Debug);
    return QString("SELECT * FROM Projects WHERE id = ").append(thisWhereID);
}
/************************************************
 * @brief get Project Name Select Query ID  SELECT id, ProjectName FROM Projects WHERE id.
 * getProjectNameSelectQueryID
 ***********************************************/
QString MyDatatables::getProjectNameSelectQueryID(const QString &thisWhereID)
{
    myLanguageModel->mySetting->setMessage("get Project Name Select Query ID", QString("%1(%2)").arg("getProjectNameSelectQueryID=SELECT id, ProjectName FROM Projects WHERE id = ", thisWhereID), myLanguageModel->mySetting->Debug);
    return QString("SELECT id, ProjectName FROM Projects WHERE id = ").append(thisWhereID);
}
/************************************************
 * @brief save Project Projects: id, ProjectName DateStarted, DateDue, Description, Progress, Status, Completed, Started, FormatStarted, FormatDue, Password, Approved, Assigned
 * saveProject
 ***********************************************/
void MyDatatables::saveProject()
{
    myLanguageModel->mySetting->setMessage("saveProject", "saveProject", myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    QSqlQuery theQuery; //!< SQL Query
    // FIXME check if ProjectName has changed if so update ProgressStatus
    QString theQueryString = QString("UPDATE Projects set ProjectName = :ProjectName, DateStarted = :DateStarted, DateDue = :DateDue, Description = :Description, Progress = :Progress, Status = :Status, Completed = :Completed, Started = :Started, FormatStarted = :FormatStarted, FormatDue = :FormatDue, Password = :Password, Approved = :Approved, Assigned = :Assigned WHERE id = :id");
    theQuery.prepare(theQueryString);
    theQuery.bindValue(":id",            myProject->getID());            // id: Update only
    theQuery.bindValue(":ProjectName",   myProject->getProjectName());   // ProjectName
    theQuery.bindValue(":DateStarted",   myProject->getDateStarted());   // DateStarted
    theQuery.bindValue(":DateDue",       myProject->getDateDue());       // DateDue
    theQuery.bindValue(":Description",   myProject->getDescription());   // Description
    theQuery.bindValue(":Progress",      myProject->getProgress());      // Progress
    theQuery.bindValue(":Status",        myProject->getStatus());        // Status
    theQuery.bindValue(":Completed",     myProject->getCompleted());     // Completed
    theQuery.bindValue(":Started",       myProject->getStarted());       // Started
    theQuery.bindValue(":FormatStarted", myProject->getFormatStarted()); // FormatStarted
    theQuery.bindValue(":FormatDue",     myProject->getFormatDue());     // FormatDue
    theQuery.bindValue(":Password",      myProject->getPassword());      // Password
    theQuery.bindValue(":Approved",      myProject->getApproved());      // Approved
    theQuery.bindValue(":Assigned",      myProject->getAssigned());      // Assigned
    if (theQuery.exec())
    {
        setRecordID(theQuery.lastInsertId().toString());
    }
    else
    {
        setRecordID("-1");
        myLanguageModel->mySetting->setMessage("saveProject", QString("%1: %2 - %3 - %4").arg(QObject::tr("SQL error saveProject"), theQuery.lastError().text(), QObject::tr("SqLite error code"), theQuery.lastError().text()), myLanguageModel->mySetting->Critical);
    }
    isSaveSettings = false;
    #endif
}
/************************************************
 * @brief set Project Sets all Variables used in the Configuarion Database in one Place:
 *      ProjectName DateStarted, DateDue, Description, Progress, Status, Completed, Started, FormatStarted, FormatDue, Password, Approved, Assigned.
 * setProject
 ***********************************************/
void MyDatatables::setProject(const QString &thisProjectID, const QString &thisProjectName, const QString &thisDateStarted, const QString &thisDateDue, const QString &thisDescription,  const QString &thisProgress, const QString &thisStatus, const QString &thisCompleted, const QString &thisStarted, const QString &thisFormatStarted, const QString &thisFormatDue, const QString &thisPassword, const QString &thisApproved, const QString &thisAssigned)
{
    myLanguageModel->mySetting->setMessage("setProject", QString("%1(%2, %3, %4, %5, %6, %7, %8, %9, %10, %11)").arg("setProject", thisProjectName, thisDateStarted, thisDateDue, thisDescription, thisProgress, thisStatus, thisCompleted, thisStarted, thisFormatStarted, thisFormatDue), myLanguageModel->mySetting->Debug);
    myProject->setID(thisProjectID);
    myProject->setProjectName(thisProjectName);
    myProject->setDateStarted(thisDateStarted);
    myProject->setDateDue(thisDateDue);
    myProject->setDescription(thisDescription);
    myProject->setProgress(thisProgress);
    myProject->setStatus(thisStatus);
    myProject->setCompleted(thisCompleted);
    myProject->setStarted(thisStarted);
    myProject->setFormatStarted(thisFormatStarted);
    myProject->setFormatDue(thisFormatDue);
    myProject->setPassword(thisPassword);
    myProject->setApproved(thisApproved);
    myProject->setAssigned(thisAssigned);
}
/************************************************
 * @brief clean String, slash, ' may be an issue,
 * and why I am using bindValue to fix this automatically,
 * and avoid SQL Injection.
 * cleanString
 ***********************************************/
QString MyDatatables::cleanString(const QString &thisString)
{
    QString theString = thisString;
    theString.replace("/","\\\\");
    theString.replace("'","\'");
    return theString;
}
/************************************************
 * @brief insert ProgressStatus into SQL Database.
 * insertProgressStatus
 ***********************************************/
bool MyDatatables::insertProgressStatus(const QString &thisProjectName)
{
    myLanguageModel->mySetting->setMessage("insert ProgressStatus", "insertProgressStatus", myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    // StatusName
    QString theQueryString = QLatin1String(R"(INSERT INTO ProgressStatus (ProjectName, StatusName) values(:ProjectName, :StatusName))");
    myLanguageModel->mySetting->setMessage("insert Progress Status", QString("%1(%2)").arg("insertProgressStatus", theQueryString), myLanguageModel->mySetting->Debug);
    QSqlQuery theQuery;
    theQuery.prepare(theQueryString);
    //theQuery.bindValue(":id", myProject->getID());                   // id: Update only
    theQuery.bindValue(":ProjectName", myProgress->getProjectName());  // ProjectName
    theQuery.bindValue(":StatusName",  myProgress->getStatusName());   // DateStarted
    if (theQuery.exec())
    {
        setRecordID(theQuery.lastInsertId().toString());
        return true;
    }
    else
    {
        myLanguageModel->mySetting->setMessage("insertProgressStatus", QString("%1: %2 - %3 - %4 - %5 - %6").arg(QObject::tr("Error running Query"), "insertProgressStatus", theQuery.lastError().text(), QObject::tr("SqLite error code"), theQuery.lastError().text(), theQueryString), MyOrgSettings::MyMessageTypes::Critical);
        setRecordID("-1");
        return false;
    }
    #else
    // FIXME Storage
    #endif
    return true;
}
/************************************************
 * @brief addProgressStatus Assumes you have ran setProgressStatus: StatusName.
 * addProgressStatus
 ***********************************************/
bool MyDatatables::addProgressStatus(const QString &thisProjectName)
{
    myLanguageModel->mySetting->setMessage("addProgressStatus", "addProgressStatus", myLanguageModel->mySetting->Debug);
#ifdef USE_SQL_FLAG
    // SELECT id, StatusName FROM ProgressStatus WHERE StatusName = ? AND ProjectName = ?
    if (isProgressStatusNameQuery(myProgress->getStatusName(), thisProjectName))
    {
        myLanguageModel->mySetting->showMessageBox(QObject::tr("Record found!").toLocal8Bit(), QString("%1: %2").arg(tr("Not adding: Record found in database"), myProgress->getStatusName()).toLocal8Bit(), myLanguageModel->mySetting->Warning);
        return false;
    }
    return insertProgressStatus(thisProjectName);
#else
    return true;
#endif
}
/************************************************
 * @brief delete ProgressStatus.
 * deleteProgressStatus
 ***********************************************/
void MyDatatables::deleteProgressStatus(const QString &thisID)
{
    myLanguageModel->mySetting->setMessage("deleteProgressStatus", QString("%1(%2)").arg("deleteProgressStatus", thisID), myLanguageModel->mySetting->Debug);
#ifdef USE_SQL_FLAG
    QSqlQuery query; //!< SQL Query
    QString theQuery = QString("DELETE FROM ProgressStatus WHERE id = %1").arg(thisID);
    myLanguageModel->mySetting->setMessage("delete ProgressStatus Query", QString("%1(%2)").arg("deleteProgressStatusQuery", theQuery), myLanguageModel->mySetting->Debug);
    if (!query.exec(theQuery))
    {
        myLanguageModel->mySetting->setMessage("deleteProgressStatus", QString("%1: %2 - %3 - %4 - %5)").arg(QObject::tr("SqLite error"), query.lastError().text(), QObject::tr("SqLite error code"), query.lastError().text(), thisID), myLanguageModel->mySetting->Critical);
    }
#endif
}
/************************************************
 * @brief get ProgressStatus Name Select Query SELECT id, StatusName FROM ProgressStatus.
 * getProgressStatusSelectQuery
 ***********************************************/
QString MyDatatables::getProgressStatusSelectQuery(const QString &thisProjectName)
{
    myLanguageModel->mySetting->setMessage("getProgressStatusSelectQuery", QString("%1(%2)").arg("getProgressStatusSelectQuery", "SELECT id, StatusName FROM ProgressStatus WHERE ProjectName = ?"), myLanguageModel->mySetting->Debug);
    return QString("SELECT id, StatusName FROM ProgressStatus WHERE ProjectName = '%1'").arg(thisProjectName);
}
/************************************************
 * @brief get ProgressStatus Name By Name Query SELECT id, StatusName FROM ProgressStatus WHERE StatusName = ? AND ProjectName = ?.
 * getProgressStatusByNameQuery
 ***********************************************/
QString MyDatatables::getProgressStatusByNameQuery(const QString &thisStatusName, const QString &thisProjectName)
{
    myLanguageModel->mySetting->setMessage("getProgressStatusByNameQuery", QString("%1(%2, %3)").arg("getProgressStatusByNameQuery", thisStatusName, thisProjectName), myLanguageModel->mySetting->Debug);
    return QString("SELECT id, StatusName FROM ProgressStatus WHERE StatusName = '%1' AND ProjectName = '%2'").arg(thisStatusName, thisProjectName);
}
/************************************************
 * @brief is Progress Status Name Query
 * isProgressStatusNameQuery
 ***********************************************/
bool MyDatatables::isProgressStatusNameQuery(const QString &thisStatusName, const QString &thisProjectName)
{
    myLanguageModel->mySetting->setMessage("isProgressStatusNameQuery", QString("%1(%2, %3)").arg("isProgressStatusNameQuery", thisStatusName, thisProjectName), myLanguageModel->mySetting->Debug);
#ifdef USE_SQL_FLAG
    QSqlQuery theQuery; //!< SQL Query
    QString theQueryCommand = getProgressStatusByNameQuery(thisStatusName, thisProjectName);
    if (theQuery.exec(theQueryCommand))
    {
        if (theQuery.first()) { return true;  }
        else                  { return false; }
    }
    else
    {
        myLanguageModel->mySetting->setMessage("isProgressStatusNameQuery", QString("%1: %2 - %3 - %4 - %5").arg(QObject::tr("SqLite error isProgressStatusQuery"), theQuery.lastError().text(), QObject::tr("SqLite error code"), theQuery.lastError().text(), thisStatusName), myLanguageModel->mySetting->Critical);
    }
#endif
    return false;
}
/************************************************
 * @brief get ProgressStatus Full Select Query ID SELECT * FROM ProgressStatus WHERE id = ?.
 * getProgressStatusFullSelectQueryID
 ***********************************************/
QString MyDatatables::getProgressStatusFullSelectQueryID(const QString &thisWhereID)
{
    myLanguageModel->mySetting->setMessage("getProgressStatusFullSelectQueryID", QString("%1(%2)").arg("getProgressStatusFullSelectQueryID = SELECT * FROM ProgressStatus WHERE id = ", thisWhereID), myLanguageModel->mySetting->Debug);
    return QString("SELECT * FROM ProgressStatus WHERE id = %1").arg(thisWhereID);
}
/************************************************
 * @brief get ProgressStatus Select Query ID  SELECT id, StatusName FROM ProgressStatus WHERE id.
 * getProgressStatusSelectQueryID
 ***********************************************/
QString MyDatatables::getProgressStatusSelectQueryID(const QString &thisWhereID)
{
    myLanguageModel->mySetting->setMessage("get ProgressStatus Name Select Query ID", QString("%1(%2)").arg("getProgressStatusSelectQueryID=SELECT id, StatusName FROM ProgressStatus WHERE id = ", thisWhereID), myLanguageModel->mySetting->Debug);
    return QString("SELECT id, StatusName FROM ProgressStatus WHERE id = %1").arg(thisWhereID);
}
/************************************************
 * @brief save ProgressStatus ProgressStatus holds the name of the Projects Progress Status id, ProjectName, StatusName
 * saveProgressStatus
 ***********************************************/
void MyDatatables::saveProgressStatus()
{
    myLanguageModel->mySetting->setMessage("saveProgressStatus", "saveProgressStatus", myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    QSqlQuery theQuery; //!< SQL Query
    QString theQueryString = QString("UPDATE ProgressStatus set ProjectName = :ProjectName, StatusName = :StatusName WHERE id = :id");
    theQuery.prepare(theQueryString);
    theQuery.bindValue(":id", myProgress->getID());                      // id: Update only
    theQuery.bindValue(":ProjectName",  myProgress->getProjectName());   // ProjectName
    theQuery.bindValue(":StatusName",   myProgress->getStatusName());    // DateStarted
    myLanguageModel->mySetting->setMessage("saveProgressStatus", "thisQuery: |" + theQueryString + "|  getProgressStatus = " + myProgress->getStatusName() + "| ID=" + myProgress->getID() + "| ProjectName=" + myProgress->getProjectName(), myLanguageModel->mySetting->Debug);
    if (!theQuery.exec())
    {
        myLanguageModel->mySetting->setMessage("saveProgressStatus", QString("%1: %2 - %3 - %4").arg(QObject::tr("SQL error saveProgressStatus"), theQuery.lastError().text(), QObject::tr("SqLite error code"), theQuery.lastError().text()), myLanguageModel->mySetting->Critical);
    }
    isSaveSettings = false;
    #endif
}
/************************************************
 * @brief set ProgressStatus Sets all Variables used in the Configuarion Database in one Place:
 *      id, ProjectName, StatusName
 * setProgressStatus
 ***********************************************/
void MyDatatables::setProgressStatus(const QString &thisProgressID, const QString &thisProjectName, const QString &thisStatusName)
{
    myLanguageModel->mySetting->setMessage("setProgressStatus", QString("%1(%2, %3)").arg("setProgressStatus", thisProgressID, thisStatusName), myLanguageModel->mySetting->Debug);
    myProgress->setID(thisProgressID);
    myProgress->setProjectName(thisProjectName);
    myProgress->setStatusName(thisStatusName);
}
/************************************************
 * @brief set Main Loaded.
 * setMainLoaded
 ***********************************************/
void MyDatatables::setMainLoaded(bool thisMainLoaded)
{
    myLanguageModel->mySetting->setMessage("setMainLoaded", QString("%1(%2)").arg("setMainLoaded", thisMainLoaded), myLanguageModel->mySetting->Debug);
    if (isMainLoaded != thisMainLoaded)
        { isMainLoaded = thisMainLoaded; }
    myLanguageModel->setMainLoaded(isMainLoaded);
}
/************************************************
 * @brief get Main Loaded.
 * getMainLoaded
 ***********************************************/
bool MyDatatables::getMainLoaded()
{
    myLanguageModel->mySetting->setMessage("getMainLoaded", QString("%1(%2)").arg("getMainLoaded", isMainLoaded), myLanguageModel->mySetting->Debug);
    return isMainLoaded;
}
/************************************************
 * @brief check Database.
 * checkDatabase
 ***********************************************/
bool MyDatatables::checkDatabase(const QString &thisSqlValue)
{
    myLanguageModel->mySetting->setMessage("checkDatabase", "checkDatabase", myLanguageModel->mySetting->Debug);
    #ifdef USE_SQL_FLAG
    QString theSqlValue = thisSqlValue;
    // Database
    if (theSqlValue == "-1")
    {
        theSqlValue = ":memory:";
    }
    setSqlDriver(theSqlValue);
    if (!createDatabaseConnection(theSqlValue)) { return false; }
    //
    // Projects
    //
    if (!isDbTable("Projects"))
    {
        /*
         * Table Projects holds the name of the Project
         * id integer PRIMARY KEY autoincrement,
         * id, ProjectName, DateStarted, DateDue, Description, Progress, Status, Completed, Started, FormatStarted, FormatDue, Password, Approved, Assigned
        */
        if (runQuery(QLatin1String(R"(CREATE TABLE Projects(id integer PRIMARY KEY autoincrement, ProjectName, DateStarted, DateDue, Description, Progress, Status, Completed, Started, FormatStarted, FormatDue, Password, Approved, Assigned))")))
        {
            QString theProjectName   = getProjectName();
            // FIXME .toString(getDateTimeFormat())
            QString theDateStarted   = getDateTimeFromNow(0).toString();
            QString theDateDue       = getDateTimeFromNow(90).toString();
            QString theDescription   = "";
            QString theProgress      = "";
            QString theStatus        = getProjectStatus();
            QString theStarted       = "false";
            QString theCompleted     = "false";
            QString theFormatStarted = "MonthDayYear";
            QString theFormatDue     = "MonthDayYear";
            QString thePassword      = "";
            QString theApproved      = "false";
            QString theAssigned      = "false";
            setProject(0, theProjectName, theDateStarted, theDateDue, theDescription, theProgress, theStatus, theCompleted, theStarted, theFormatStarted, theFormatDue, thePassword, theApproved, theAssigned);
            if (insertProjects())
            {
                myProjectID = getRecordID();
                myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_PROJECT_ID, myProjectID);
            }
            else
            {
                myLanguageModel->mySetting->setMessage(QObject::tr("check Database Insert Table Fail Projects"), QString("%1: %2").arg("checkDatabase: Projects", getSqlDriver()), myLanguageModel->mySetting->Critical);
            }
        }
        //
    } // end if (!isDbTable("Projects"))
    //
    // Progress Status
    //
    if (!isDbTable("ProgressStatus"))
    {
        /*
         * Table ProgressStatus holds the name of the Projects Progress Status id, StatusName
         * id integer PRIMARY KEY autoincrement,
         * id, ProjectName, StatusName
        */
        if (runQuery(QLatin1String(R"(CREATE TABLE ProgressStatus(id integer PRIMARY KEY autoincrement, ProjectName, StatusName))")))
        {
            //
            setProgressStatus(0, getProjectName(), "Status");
            if (!insertProgressStatus(getProjectName()))
            {
                myLanguageModel->mySetting->setMessage(QObject::tr("check Database Insert Table Fail ProgressStatus"), QString("%1: %2").arg("checkDatabase: ProgressStatus", getSqlDriver()), myLanguageModel->mySetting->Critical);
            }
        }
        //
    } // end if (!isDbTable("ProgressStatus"))
    //
    #endif
    return true;
} // checkDatabase
/************************************************
 * @brief get Date Time Format.
 * getDateTimeFormat
 ***********************************************/
QString MyDatatables::getDateTimeFormat(const QString &thisFormat)
{
    myLanguageModel->mySetting->setMessage("get DateTime Format", QString("getDateTimeFormat(%1)").arg(s_DateTimeFormat.value(thisFormat)), MyOrgSettings::MyMessageTypes::Debug);
    return tr(s_DateTimeFormat.value(thisFormat).toLocal8Bit());
} // end getDateTimeFormat
/************************************************
 * @brief get DateTime Format Name.
 * getDateTimeFormatName
 ***********************************************/
QString MyDatatables::getDateTimeFormatName(const QString &thisFormat)
{
    myLanguageModel->mySetting->setMessage("get DateTime Format Name", QString("getDateTimeFormatName(%1)").arg(s_DateTimeFormat.value(thisFormat)), MyOrgSettings::MyMessageTypes::Debug);
    return tr(s_DateTimeFormatName.value(thisFormat).toLocal8Bit());
} // end getDateTimeFormatName
/************************************************
 * @brief getDateTimeFormatCode.
 * getDateTimeFormatCode
 ***********************************************/
MyDatatables::MyDateTimeFormat MyDatatables::getDateTimeFormatCode(const QString &thisFormat)
{
    myLanguageModel->mySetting->setMessage("get Date TimeFormat Code", QString("getDateTimeFormatCode(%1)").arg(thisFormat), MyOrgSettings::MyMessageTypes::Debug);
    if (thisFormat == "MonthDayYear")
    {
        return MyDatatables::MonthDayYear;
    }
    else if (thisFormat == "DayMonthYear")
    {
        return MyDatatables::DayMonthYear;
    }
    else if (thisFormat == "YearMonthDay")
    {
        return MyDatatables::YearMonthDay;
    }
    else if (thisFormat == "YearDayMonth")
    {
        return MyDatatables::YearDayMonth;
    }
    else if (thisFormat == "Military")
    {
        return MyDatatables::Military;
    }
    return MyDatatables::MonthDayYear;
}
/************************************************
 * @brief s_DateTimeFormat
 * s_DateTimeFormat
 ***********************************************/
const QMap<QString, QString> MyDatatables::s_DateTimeFormat =
{
    { QStringLiteral("Month/Day/Year Time"), QStringLiteral("M/d/yyyy h:mm AP")  },
    { QStringLiteral("Day/Month/Year Time"), QStringLiteral("d/M/yyyy h:mm AP")  },
    { QStringLiteral("Year/Month/Day Time"), QStringLiteral("yyyy/M/d h:mm AP")  },
    { QStringLiteral("Year/Day/Month Time"), QStringLiteral("yyyy/d/M h:mm AP")  },
    { QStringLiteral("Military Time"),       QStringLiteral("d/MMM/yyyy h:mm AP") },
};
/************************************************
 * @brief s_DateTimeFormatName
 * s_DateTimeFormatName
 ***********************************************/
const QMap<QString, QString> MyDatatables::s_DateTimeFormatName =
{
    { QStringLiteral("M/d/yyyy h:mm AP"), QStringLiteral("Month/Day/Year Time")  },
    { QStringLiteral("d/M/yyyy h:mm AP"), QStringLiteral("Day/Month/Year Time")  },
    { QStringLiteral("yyyy/M/d h:mm AP"), QStringLiteral("Year/Month/Day Time")  },
    { QStringLiteral("yyyy/d/M h:mm AP"), QStringLiteral("Year/Day/Month Time")  },
    { QStringLiteral("Military h:mm AP"), QStringLiteral("Day/Month/Year Time")  },
};
/*** ************************* End of File ***********************************/
