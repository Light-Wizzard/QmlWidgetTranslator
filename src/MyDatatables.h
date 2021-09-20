#ifndef MYDATATABLES_H
#define MYDATATABLES_H

#include <QObject>
#include <QtDebug>
#ifdef USE_SQL_FLAG
    #include <QtSql>
#endif
#include "MyLanguageModel.h"
/************************************************
 * @brief Project Class.
 * \class MyProjectClass
 * id, ProjectName, DateStarted, DateDue, Description, Progress, Status, Completed, Started, FormatStarted, FormatDue, Password, Approved, Assigned
 ***********************************************/
class MyProjectClass
{
    public:
        MyProjectClass(const QString &thisID, const QString &thisProjectName, const QString &thisDateStarted, const QString &thisDateDue, const QString &thisDescription,  const QString &thisProgress, const QString &thisStatus, const QString &thisCompleted, const QString &thisStarted, const QString &thisFormatStarted, const QString &thisFormatDue)
            : myID{thisID}, myProjectName{thisProjectName}, myDateStarted{thisDateStarted}, myDateDue{thisDateDue}, myDescription{thisDescription}, myProgress{thisProgress}, myStatus{thisStatus}, myCompleted{thisCompleted}, myStarted{thisStarted}, myFormatStarted{thisFormatStarted}, myFormatDue{thisFormatDue} {}
        // Getters
        QString getID()            const { return myID;            } //!< ID
        QString getProjectName()   const { return myProjectName;   } //!< Project Name
        QString getDateStarted()   const { return myDateStarted;   } //!< Date Started
        QString getDateDue()       const { return myDateDue;       } //!< Date Due
        QString getDescription()   const { return myDescription;   } //!< Description Text Field
        QString getProgress()      const { return myProgress;      } //!< Progress Text Field
        QString getStatus()        const { return myStatus;        } //!< ComboBox of Status
        QString getCompleted()     const { return myCompleted;     } //!< Check Boxe
        QString getStarted()       const { return myStarted;       } //!< Check Box
        QString getFormatStarted() const { return myFormatStarted; } //!< get Format Started
        QString getFormatDue()     const { return myFormatDue;     } //!< get Format Due
        QString getPassword()      const { return myPassword;      } //!< get Password
        QString getApproved()      const { return myApproved;      } //!< get Approved
        QString getAssigned()      const { return myAssigned;      } //!< get Assigned
        // Setters
        void setID(const QString &s)            { myID            = s; }
        void setProjectName(const QString &s)   { myProjectName   = s; }
        void setDateStarted(const QString &s)   { myDateStarted   = s; }
        void setDateDue(const QString &s)       { myDateDue       = s; }
        void setDescription(const QString &s)   { myDescription   = s; }
        void setProgress(const QString &s)      { myProgress      = s; }
        void setStatus(const QString &s)        { myStatus        = s; }
        void setCompleted(const QString &s)     { myCompleted     = s; }
        void setStarted(const QString &s)       { myStarted       = s; }
        void setFormatStarted(const QString &s) { myFormatStarted = s; }
        void setFormatDue(const QString &s)     { myFormatDue     = s; }
        void setPassword(const QString &s)      { myPassword      = s; }
        void setApproved(const QString &s)      { myApproved      = s; }
        void setAssigned(const QString &s)      { myAssigned      = s; }

    private:
        QString myID, myProjectName, myDateStarted, myDateDue, myDescription, myProgress;
        QString myStatus, myCompleted, myStarted, myFormatStarted, myFormatDue;
        QString myPassword, myApproved, myAssigned;
};
/************************************************
 * @brief Progress Class.
 * \class MyProgressClass
 ***********************************************/
class MyProgressClass
{
    public:
    MyProgressClass(const QString &thisID, const QString &thisProjectName, const QString &thisStatusName)
        : myID{thisID}, myProjectName{thisProjectName}, myStatusName{thisStatusName} {}
    // Getters
    QString getID()             const { return myID;             } //!< ID
    QString getProjectName()    const { return myProjectName;    } //!< Project Name
    QString getStatusName()     const { return myStatusName;     } //!< Progress Status
    // Setters
    void setID(const QString &s)             { myID             = s; }
    void setProjectName(const QString &s)    { myProjectName    = s; }
    void setStatusName(const QString &s)     { myStatusName     = s; }

    private:
        QString myID, myProjectName, myStatusName;
};
/************************************************
 * @brief My Datatables.
 * \class MyDatatables
 ***********************************************/
class MyDatatables : public QObject
{
        Q_OBJECT
    public:
        explicit MyDatatables(MyLanguageModel *thisLanguageModel = nullptr, QObject *parent = nullptr);
        ~MyDatatables();
        /*!
            \enum MyDateTimeFormat
            @brief My DateTime Format
         */
        enum MyDateTimeFormat
        {
            MonthDayYear = 100, //!< \c MonthDayYear    @brief Month/Day/Year
            DayMonthYear = 101, //!< \c DayMonthYear    @brief Day/Month/Year
            YearMonthDay = 102, //!< \c YearMonthDay    @brief Year/Month/Day
            YearDayMonth = 103, //!< \c YearDayMonth    @brief Year/Day/Month
            Military     = 104, //!< \c Military        @brief Day/Month/Year
        }; // end enum MyFileinfo
        // Makes DateTime Format easier
        Q_ENUM(MyDateTimeFormat)
        //
        const QString MY_SQL_DATETIME_FORMAT         = "Month/Day/Year Time"; //!< \c MY_SQL_DATETIME_FORMAT @brief Used to store datetime in sql string format.
        const QString MY_DEFAULT_STATUS              = "Status";              //!< \c MY_DEFAULT_STATUS @brief Default Status.
        MyDateTimeFormat MY_SQL_DATETIME_FORMAT_TYPE = MonthDayYear;          //!< \c MY_SQL_DATETIME_FORMAT_TYPE @brief You must change both values to match
        //
        MyProjectClass  *myProject;                  //!< \c myProject  @brief My Project Variables
        MyProgressClass *myProgress;                 //!< \c myProgress @brief My Progress Variables
        MyLanguageModel *myLanguageModel;            //!< \c MyLanguageModel @brief My Language Model
        //
        bool checkDatabase(const QString &thisSqlValue); //!< check Database
        bool insertProjects();                     //!< insert Project
        bool addProject();                         //!< add Project
        void deleteProject(const QString &thisID); //!< delete Project
        void saveProject(); //!< save Project
        //
        void setProject(const QString &thisProjectID, const QString &thisProjectName, const QString &thisProject, const QString &thisSecret, const QString &thisEnvironment, const QString &thisProgress, const QString &thisStatus, const QString &thisCompleted, const QString &thisStarted, const QString &thisFormatStarted, const QString &thisFormatDue, const QString &thisPassword, const QString &thisApproved, const QString &thisAssigned);
        // Query
        QString getProjectNameSelectQueryID(const QString &thisWhereID);  //!< get Projects Name Select Query ID
        QString getProjectNameSelectQuery();                              //!< get Projects Name Select Query
        QString getProjectFullSelectQueryID(const QString &thisWhereID);  //!< get Projects Full Select Query ID
        QString getProjectNameByNameQuery(const QString &thisProject);    //!< get Projects Name By Name Query
        bool isProjectNameQuery(const QString &thisProjectName);          //!< is Project Name Query
        // Project Name
        void setProjectName(const QString &thisProjectName);              //!< set Project Name
        QString getProjectName();                                         //!< get Project Name
        // Project ID
        void setProjectID(const QString &thisProjectID);                  //!< set Project ID
        QString getProjectID();                                           //!< get Project ID
        // Project Folder
        void setDateStarted(const QString &thisDateStarted);              //!< set Project Folder
        QString getDateStarted();                                         //!< get Project Folder
        // ComboBox SQL Value
        void setComboBoxSqlValue(const QString &thisComboBoxSqlValue);    //!< set ComboBox SqlValue
        QString getComboBoxSqlValue();                                    //!< get ComboBox SqlValue
        // Database Connection
        bool createDatabaseConnection(const QString &thisDatabaseConnection); //!< create Database Connection
        bool isDbTable(const QString &thisTable);                   //!< is Db Table
        // Sql Driver
        bool setSqlDriver(const QString &thisDriver);               //!< set Sql Driver
        QString getSqlDriver();                                     //!< get Sql Driver
        // Sql Table Name
        void setSqlTableName(const QString &thisTableName);         //!< set Sql Table Name
        QString getSqlTableName();                                  //!< get Sql Table Name
        // Sql Host Name
        void setSqlHostName(const QString &thisHostName);           //!< set Sql Host Name
        QString getSqlHostName();                                   //!< get Sql Host Name
        // Sql User Name
        void setSqlUserName(const QString &thisUserName);           //!< set Sql User Name
        QString getSqlUserName();                                   //!< get Sql User Name
        // Sql Password
        void setSqlPassword(const QString &thisPassword);           //!< set Sql Password
        QString getSqlPassword();                                   //!< get Sql Password
        // Sql Database Name
        void setSqlDatabaseName(const QString &thisDatabaseName);   //!< set Sql Database Name
        QString getSqlDatabaseName();                               //!< get Sql Database Name
        QString getSqlLiteDbName();                                 //!< get SqlLite Db Name
        #ifdef USE_SQL_FLAG
        // Sql Database
        void setSqlDatabase(QSqlDatabase thisDatabase);             //!< set Sql Database
        QSqlDatabase getSqlDatabase();                              //!< get Sql Database
        #endif
        // Connection Name
        QString getConnectionName();                                //!< get Connection Name
        void setConnectionName(const QString &thisConnectionName);  //!< set Connection Name
        // RecordID
        QString getRecordID();                                      //!< get RecordID
        void setRecordID(const QString &thisRecordID);              //!< set RecordID
        // run Query
        bool runQuery(const QString &thisQuery);                    //!< runQuery
        // move Db
        bool moveDb(const QString &thisSourceFile, const QString &thisSourcePath, const QString &thisDescription); //!<  Move Db
        QString runProcces(const QString &thisExePath, const QString &thisArgument, bool isWait, int thisWaitTimeSec);   //!< run Procces
        // Run Return Code
        int getRunReturnCode();                      //!< get Run Return Code
        // Is Debug Message
        void setDebugMessage(bool thisState);        //!< set Debug Message
        bool getDebugMessage();                      //!< get Debug Message
        // Main Loaded
        void setMainLoaded(bool thisMainLoaded);     //!< set Main Loaded
        bool getMainLoaded();                        //!< get Main Loaded
        // DatabaseConnection
        void setDatabaseConnection(const QString &thisDatabaseConnection); //!< set Database Connection
        QString getDatabaseConnection();                  //!< get Database Connection
        // Date
        QDateTime getDateTimeFromNow(int thisDaysFromNow);         //!< get DateTime From Now
        QString getDateTimeFormat();                               //!< get DateTime Format
        void setDateTimeFormat(const QString &thisDateTimeFormat); //!< set DateTime Format
        QString getDateTimeFormat(const QString &thisFormat);      //!< get DateTime Format
        QString getDateTimeFormatName(const QString &thisFormat);  //!< get DateTime Format Name
        MyDatatables::MyDateTimeFormat getDateTimeFormatCode(const QString &thisFormat); //!< get DateTime Format Code
        // Progress
        void setProgressStatus(const QString &thisProgressID, const QString &thisProjectName, const QString &thisStatusName); //!< set Progress Status
        void saveProgressStatus();                                               //!< save Progress Status
        // SQL Query
        QString getProgressStatusSelectQueryID(const QString &thisWhereID);      //!< get Progress Status Select Query ID
        QString getProgressStatusFullSelectQueryID(const QString &thisWhereID);  //!< get Progress Status Full Select Query ID
        bool isProgressStatusNameQuery(const QString &thisStatusName, const QString &thisProjectName);    //!< is Progress Status Name Query
        QString getProgressStatusByNameQuery(const QString &thisStatusName, const QString &thisProjectName);  //!< get Progress Status By Name Query
        QString getProgressStatusSelectQuery(const QString &thisProjectName);  //!< getProgressStatusSelectQuery
        // Progress Status
        void deleteProgressStatus(const QString &thisID);           //!< delete Progress Status
        bool addProgressStatus(const QString &thisProjectName);     //!< add Progress Status
        bool insertProgressStatus(const QString &thisProjectName);  //!< insert Progress Status
        // Project Status
        void setProjectStatus(const QString &thisProjecStatus); //!< set Project Status
        QString getProjectStatus();                             //!< get Project Status
        // Project Default Status
        void setProjectDefaultStatus(const QString &thisProjecDefaultStatus); //!< set Project Default Status
        QString getProjectDefaultStatus();                                    //!< get Project Default Status
        // Utilities
        QString cleanString(const QString &thisString); //!< clean String

    public slots:
        void onUpdateDatabase();   //!< onUpdateDatabase

    signals:
        void sendUpdateDatabase(); //!< send Update Database

    private:
        #ifdef USE_SQL_FLAG
        QSqlDatabase myDb;                             //!< \c myDb                 @brief Database
        #endif
        QString myProjectID          = "-1";           //!< \c myProjectID          @brief Project ID
        QString myProgressID         = "-1";           //!< \c myProgressID         @brief Progess ID
        QString myDateStarted        = "";             //!< \c myDateStarted        @brief Project Folder
        QString myProjectName        = "";             //!< \c myProjectName        @brief Project Name
        QString myDatabaseName       = "";             //!< \c myDatabaseName       @brief Sql Driver DatabaseName with extention for Sqlite
        QString myTableName          = "" ;            //!< \c myTableName          @brief Table Name
        QString mySqlDriver          = "NOTSET";       //!< \c mySqlDriver          @brief Sql Driver NOTSET
        QString myHostName           = "localhost";    //!< \c myHostName           @brief Sql HostName location of your MySQL server and database, localhost
        QString myUserName           = "";             //!< \c myUserName           @brief Sql User Name
        QString myPassword           = "";             //!< \c myPassword           @brief Sql Password
        QString myConnectionName     = "";             //!< \c myConnectionName     @brief Connection Name
        QString myInsertID           = "-1";           //!< \c myInsertID           @brief InsertID for last SQL insert
        QString myDateTimeFormat     = "";             //!< \c myDateTimeFormat     @brief my Date Time Format
        QString myDatabaseConnection = "";             //!< \c myDatabaseConnection @brief my Database Connection
        QString myStatusName         = "";             //!< \c myStatusName         @brief my Status Name
        QString myDefaultStatusName  = "";             //!< \c myDefaultStatusName  @brief my Default Status Name
        int     myRunReturnCode      = 1;              //!< \c myRunReturnCode      @brief Run Return Code
        bool    isMainLoaded         = false;          //!< \c isMainLoaded         @brief Set true after one shot time loads.
        bool    isDebugMessage       = true;           //!< \c isDebugMessage       @brief Debug Message
        bool    isSaveSettings       = false;          //!< \c isSaveSettings       @brief is Save Settings for Auto Save
        static const QMap<QString, QString>  s_DateTimeFormat;     //!< \c s_DateTimeFormat     @brief DateTime Format
        static const QMap<QString, QString>  s_DateTimeFormatName; //!< \c s_DateTimeFormatName @brief DateTime Format Name

};
#endif // MYDATATABLES_H
/*** ************************* End of File ***********************************/
