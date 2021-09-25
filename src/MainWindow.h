#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QCloseEvent>
#include <QTableView>
#include <QStandardItemModel>
#include <QAbstractItemView>
#include <QAbstractListModel>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QDir>
#include <QFile>
#include <QMap>
#include <QObject>
#include <QPointer>
#include <QTimer>
#include <QTranslator>
#include <QVector>
#include <QMainWindow>
#include <QFileDialog>
#include <QLineEdit>
//
#include <QtCore>
#include <QtGlobal>

#ifdef USE_SQL_FLAG
    #include <QtSql>
#endif
//
#include "MyLanguageModel.h"
#include "MyDatatables.h"

QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/************************************************
 * @brief Main Window Constructor.
 * /class MainWindow
 * @author Jeffrey Scott Flesher
 ***********************************************/
class MainWindow : public QMainWindow
{
        Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);  //!< MainWindow
        ~MainWindow();  //!< MainWindow Deconstructor
        /*!
            @brief Tabs must be forced to be int 0 based indexes that match the actual ui for widgetTab, this enforces compile-time checks.
            \enum MainTabs
         */
        enum MainTabs
        {
            TabSettings     = 0,  //!< \c TabSettings     @brief Tab Settings.
            TabSql          = 1,  //!< \c TabSql          @brief Tab SQL
            TabProjects     = 2,  //!< \c TabProjects     @brief Tab Projects.
            TabTabHelp      = 3,  //!< \c TabHelp         @brief Tab Help.
            TabAll          = 9   //!< \c TabAll          @brief Tab All used for Actions on all Tabs.
        }; // end enum MainTabs
        Q_ENUM(MainTabs)
        //
        void onRunFirstOnStartup();  //!< on Run First On Startup
        void retranslate();          //!< retranslate
        // Orgnization Settings
        void readSettingsFirst();    //!< read Settings First
        void readAllSettings();      //!< read All Settings
        void readSqlDatabaseInfo();  //!< read Sql Database Info
        void writeSqlDatabaseInfo(); //!< write Sql Database Info
        void writeAllSettings();     //!< write All Settings
        // Language Model
        void setLanguageModel(MyLanguageModel *thisLanguageModel);  //!< set Language Model
        MyLanguageModel getLanuguageModel();                        //!< get Lanuguage Model
        // Messaging State
        void setMessagingStates(bool thisMessageState); //!< set Messaging States
        // ComboBox
        void loadLanguageComboBox();                    //!< load Language ComboBox
        void loadProjectComboBox(const QString &thisProjectName); //!< load Project ComboBox
        void loadProjectComboBoxDateTimeFormatStarted(); //!< load Project ComboBox DateTime Format Started
        void loadProjectComboBoxDateTimeFormatDue();     //!< load Project ComboBox DateTime Format Due
        void loadProjectProgressStatusComboBox(const QString &thisProjectName, const QString &thisStatusName); //!< load Project Progress Status ComboBox
        //
        void setSqlBrowseButton();                       //!< set SQL Browse Button
        //
        void setDatabaseModel();                         //!< set Database Model
        //
        void fillForms(const QString &thisProjectID);    //!< fill Forms
        void clearForm(const QString &thisIndexStart, const QString &thisIndexDue); //!< clear Form
        void setProjects(); //!< set Projects
        //
        void setDateTimeFormat(MyDatatables::MyDateTimeFormat thisDateTimeFormat, const QString &thisComboBox); //!< set DateTime Format
        QDateTime getDataTimeFromString(const QString &thisDateTimeString, const QString &thisControlName, const QString &thisFormatName); //!< get Data Time From String
        //
        QString getComboBoxProjectsID(int thisIndex);        //!< get ComboBox Projects ID
        QString getComboBoxProgressStatusID(int thisIndex);  //!< get ComboBox Progress Status ID
        //
        void setProgressStatus(const QString &thisStatusName);  //!< set Progress Status
        //
        void setDateTimeFormatStartedValue(const QString &thisDateTimeFormat); //!< set DateTime Format Started Value
        QString getDateTimeFormatStartedValue();                               //!< get DateTime Format Started Value
        //
        void setDateTimeFormatDueValue(const QString &thisDateTimeFormat);     //!< set DateTime Format Due Value
        QString getDateTimeFormatDueValue();                                   //!< get DateTime Format Due Value
        //
        void setLastLanguageName(const QString &thisLastLanguageName);     //!< set Last Language Name
        QString getLastLanguageName();                                     //!< get Last Language Name
        //
        void setMainLoaded(bool isMain);  //!< set Main Loaded
        bool getMainLoaded();             //!< get Main Loaded
        //
        void loadLanguage(const QString &thisLanguage);  //!< load Language
        //
        void validateProjectName(const QString &thisText); //!< validate Project Name

    public slots:
        void onSaveAll(const QString &thisStatus); //!< on Save
        void onSave();                             //!< on Save

    protected:
        void closeEvent(QCloseEvent *event) override;      //!< close Event

    protected slots:
        virtual void changeEvent(QEvent * event) override; //!< change Event

    private slots:
        void on_comboBoxLanguage_currentIndexChanged(const QString &thisLanguage);       //!< on comboBox Language current Index Changed
        void on_comboBoxSqlDatabaseType_currentIndexChanged(const QString &thisSqlType); //!< on comboBox SQL Database Type current Index Changed
        void on_comboBoxProjects_currentIndexChanged(int thisIndex); //!< on comboBox Projects current Index Changed
        void on_comboBoxProjectsDateTimeFormatStart_currentIndexChanged(const QString &thisDateTimeFormat); //!< on comboBox Projects DateTime Format Start current Index Changed
        void on_comboBoxProjectsDateTimeFormatDue_currentIndexChanged(const QString &thisDateTimeFormat);   //!< on comboBox Projects DateTime Format Due current Index Changed
        // Push Buttons SQL
        void on_pushButtonSqlDatabaseNameBrowse_clicked();  //!< on pushButton SQL Database Name Browse clicked
        void on_pushButtonSqlPasswordShow_clicked();        //!< on pushButton SQL Password Show clicked
        void on_pushButtonSqlSave_clicked();                //!< on pushButton SQL Save clicked
        // Projects
        void on_pushButtonProjectsSave_clicked();           //!< on pushButton Projects Save clicked
        void on_pushButtonProjectsDelete_clicked();         //!< on pushButton Projects Delete clicked
        void on_pushButtonProjectsAdd_clicked();            //!< on pushButton Projects Add clicked
        void on_pushButtonProjectsClear_clicked();          //!< on pushButton Projects Clear clicked
        void on_pushButtonProjectsDateStart_clicked();      //!< on pushButton Projects DateStart clicked
        void on_pushButtonProjectsDateDue_clicked();        //!< on pushButton Projects DateDue clicked
        void on_pushButtonProjectsProgressStatusAdd_clicked();    //!< on pushButton Projects Progress Status Add clicked
        void on_pushButtonProjectsProgressStatusDelete_clicked(); //!< on pushButton Projects Progress Status Delete clicked
        void on_pushButtonProjectsProgressStatusModify_clicked(); //!< on pushButton Projects Progress Status Modify clicked
        void on_pushButtonProjectsShowPassword_clicked();   //!< on pushButton Projects Show Password clicked
        // Events
        void onHelp();                                      //!< on Help
        void onAbout();                                     //!< on About
        void onAuthor();                                    //!< on Author
        void onInternetProgress();                          //!< on Internet Progress
        //
        void on_lineEditProjectsName_textChanged(const QString &thisText); //!< on lineEdit Projects Name text Changed
        void on_tabWidget_currentChanged(int index); //!< on tab Widget current Changed


        void onTextBold();
        void onTextUnderline();
        void onTextItalic();

        void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
        void fontChanged(const QFont &f);
        void onCurrentCharFormatChanged(const QTextCharFormat &format);
        void onCursorPositionChanged();

    private:
        Ui::MainWindow  *ui;                               //!< \c ui                   @brief UI
        MyLanguageModel *myLanguageModel;                  //!< \c myLanguageModel      @brief my Language Model
        MyDatatables    *myDbModel;                        //!< \c myDbModel            @brief my Database Model.
        QString          myUiLanguageName     = "";        //!< \c myUiLanguageName     @brief UI Language Name.
        QString          myLastLanguageName   = "";        //!< \c myLastLanguageName   @brief Last Language Name.
        QString          myDbType;                         //!< \c myDbType             @brief my Database Type.
        QString          myDateTimeFormatStartedValue;     //!< \c myDateTimeFormatStartedValue @brief my Date Time Format Started Value.
        QString          myDateTimeFormatDueValue;         //!< \c myDateTimeFormatDueValue @brief my Date Time Format Due Value.
        QString          myDefaultStatusName  = "Waiting"; //!< \c myDefaultStatusName  @brief my Default Status Name.
        int              myLastProjectID;                  //!< \c myLastProjectID      @brief my Last Project ID.
        int              myLastStatusID;                   //!< \c myLastStatusID       @brief my Last Status ID.
        bool             isDebugMessage       = false;     //!< \c isDebugMessage       @brief true of false for Debugging.
        bool             isMainLoaded         = false;     //!< \c isMainLoaded         @brief Set true after one shot time loads.
        int              myRecordID;                       //!< \c isMainLoaded         @brief my Database Record ID.
};
#endif // MAINWINDOW_H
/******************************* End of File *********************************/
