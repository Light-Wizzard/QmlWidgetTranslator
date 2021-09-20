/************************************************
* @file MainWindow.cpp
* @brief Main Window.
* @author Jeffrey Scott Flesher <Jeffrey.Scott.Flesher@>
* @version 1.0
* @section LICENSE
* Unlicenced, Free, CopyLeft.
* @section DESCRIPTION
* Main Window.
* I check variables before setting them to prevent triggers
* @mainpage
* MainWindow.
 ***********************************************/
#include "MainWindow.h"
#include "ui_MainWindow.h"
/************************************************
 * @brief MainWindow.
 * MainWindow
 ***********************************************/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    setWindowTitle(QApplication::applicationName());
    // Set up UI
    ui->setupUi(this);
    //
    ui->lineEditProjectsProgressStatus->hide();
    // USE_SQL_FLAG Defined in cmake
    #ifdef USE_SQL_FLAG
    // SQL Database Types Do not Translate these
    ui->comboBoxSqlDatabaseType->addItem(":memory:");
    ui->comboBoxSqlDatabaseType->addItem("QSQLITE");
    ui->comboBoxSqlDatabaseType->addItem("QMYSQL");
    ui->comboBoxSqlDatabaseType->addItem("QPSQL");
    ui->comboBoxSqlDatabaseType->addItem("QDB2");
    ui->comboBoxSqlDatabaseType->addItem("QIBASE");
    ui->comboBoxSqlDatabaseType->addItem("QOCI");
    ui->comboBoxSqlDatabaseType->addItem("QTDS");
    #else
    ui->comboBoxSqlDatabaseType->setHidden(true);
    ui->comboBoxProjects->setHidden(true);
    ui->pushButtonProjectsAdd->setHidden(true);
    ui->pushButtonProjectsDelete->setHidden(true);
    ui->pushButtonProjectsSave->setHidden(true);
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabSQL")));
    ui->toolBar->actions().at(0)->setVisible(false); // Set Save hidden
    ui->toolBar->actions().at(1)->setVisible(false); // Set divider hidden
    ui->labelProjectsOptions->setHidden(true);
    ui->labelProjectsNameValidator->setHidden(true);
    ui->labelProjectsRecordNumber->setHidden(true);
    ui->labelProjectsRecordId->setHidden(true);
    ui->labelProjectProgressStatus->setHidden(true);
    ui->comboBoxProgressStatus->setHidden(true);
    ui->lineEditProjectsProgressStatus->setHidden(true);
    ui->pushButtonProjectsProgressStatusAdd->setHidden(true);
    ui->pushButtonProjectsProgressStatusModify->setHidden(true);
    ui->pushButtonProjectsProgressStatusDelete->setHidden(true);
    ui->pushButtonProjectsClear->setHidden(true);
    #endif
    //
#ifdef QT_NO_DEBUG
    ui->labelSettignsMessaging->hide();
    ui->checkBoxSettignsMessaging->hide();
#else
#endif
    // Connect actions
    connect(ui->actionExit,    &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionAbout,   &QAction::triggered, this, &MainWindow::onAbout);
    connect(ui->actionHelp,    &QAction::triggered, this, &MainWindow::onHelp);
    connect(ui->actionAuthor,  &QAction::triggered, this, &MainWindow::onAuthor);
    connect(ui->actionSave,    &QAction::triggered, this, &MainWindow::onSave);
    //
    connect(ui->actionBold,      &QAction::triggered, this, &MainWindow::onTextBold);
    connect(ui->actionUnderline, &QAction::triggered, this, &MainWindow::onTextUnderline);
    connect(ui->actionItalic,    &QAction::triggered, this, &MainWindow::onTextItalic);
    connect(ui->textEditProjectDescription, &QTextEdit::currentCharFormatChanged, this, &MainWindow::onCurrentCharFormatChanged);
    connect(ui->textEditProjectDescription, &QTextEdit::cursorPositionChanged,    this, &MainWindow::onCursorPositionChanged);

}
/************************************************
 * @brief MainWindow Deconstructor.
 * ~MainWindow
 ***********************************************/
MainWindow::~MainWindow()
{
    myLanguageModel->mySetting->setMessage("Main Window", "~MainWindow", MyOrgSettings::MyMessageTypes::Debug);
    Q_CLEANUP_RESOURCE(QmlWidgetTranslator);
    delete ui;
}
/************************************************
 * @brief close Event.
 * closeEvent
 ***********************************************/
void MainWindow::closeEvent(QCloseEvent *event)
{
    myLanguageModel->mySetting->setMessage("close Event", "closeEvent", MyOrgSettings::MyMessageTypes::Debug);
    writeAllSettings();
    QMainWindow::closeEvent(event);
    close();
} // end closeEvent
/************************************************
 * @brief change Event.
 * changeEvent
 ***********************************************/
void MainWindow::changeEvent(QEvent *event)
{
    if (!getMainLoaded()) { return; }
    QMetaEnum metaEnum = QMetaEnum::fromType<QEvent::Type>();
    myLanguageModel->mySetting->setMessage("change Event", QString("%1: %2").arg("changeEvent", metaEnum.valueToKey(event ->type())), MyOrgSettings::MyMessageTypes::Debug);
    if (event ->type() == QEvent::LanguageChange && getMainLoaded())
    {
        if (myLanguageModel->getLanguageName() != getLastLanguageName())
        {
            // retranslate designer form (single inheritance approach)
            ui->retranslateUi(this);
            // retranslate other widgets which weren't added in designer
            retranslate();
        }
    }
    // remember to call base class implementation
    QMainWindow::changeEvent(event);
}
/************************************************
 * @brief on Internet Progress.
 * onInternetProgress
 ***********************************************/
void MainWindow::onInternetProgress()
{
    ui->statusbar->showMessage(tr("Internet is down, trying to reconnect"));
}
/************************************************
 * @brief read Settings First.
 * readSettingsFirst
 ***********************************************/
void MainWindow::readSettingsFirst()
{
    isDebugMessage = myLanguageModel->mySetting->readSettingsBool(myLanguageModel->mySetting->MY_IS_DEBUG_MESSAGE, isDebugMessage);
    if (isDebugMessage)
        { ui->checkBoxSettignsMessaging->setCheckState(Qt::CheckState::Checked); }
    else
        { ui->checkBoxSettignsMessaging->setCheckState(Qt::CheckState::Unchecked); }
    setMessagingStates(isDebugMessage);
    // Go to Tab
    int theIndex = myLanguageModel->mySetting->readSettingsInt(myLanguageModel->mySetting->MY_LAST_TAB_INDEX, myLanguageModel->mySetting->MY_DEFAULT_TAB_INDEX.toInt());
    if (theIndex < 0)
    {
        theIndex = 0;
    }
    ui->tabWidget->setCurrentIndex(theIndex);
}
/************************************************
 * @brief set Messaging States.
 * setMessagingStates
 ***********************************************/
void MainWindow::setMessagingStates(bool thisMessageState)
{
    if (thisMessageState)
    {
        myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_IS_DEBUG_MESSAGE, "true");
        isDebugMessage = true;
        myDbModel->setDebugMessage(true);
        myLanguageModel->mySetting->setDebugMessage(true);
        myLanguageModel->mySetting->myCrypto->setDebugMessage(true);
    }
    else
    {
        myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_IS_DEBUG_MESSAGE, "false");
        isDebugMessage = false;
        myDbModel->setDebugMessage(false);
        myLanguageModel->mySetting->setDebugMessage(false);
        myLanguageModel->setDebugMessage(false);
        myLanguageModel->mySetting->myCrypto->setDebugMessage(false);
    }
}
/************************************************
 * @brief on Run First On Startup.
 * onRunFirstOnStartup
 ***********************************************/
void MainWindow::onRunFirstOnStartup()
{
    myLanguageModel->mySetting->setMessage("on Run First On Startup", "onRunFirstOnStartup", MyOrgSettings::MyMessageTypes::Debug);
    readAllSettings();
    // Read Saved Language
    myLanguageModel->readLanguage();
    //
    setMainLoaded(true); // Set true for event
    if (!myDbModel->checkDatabase(myDbType)) close();
    // Load Language
    loadLanguage(myLanguageModel->getLanguageName());
}
/************************************************
 * @brief set Main Loaded Set to prevent triggers.
 * setMainLoaded
 ***********************************************/
void MainWindow::setMainLoaded(bool isMain)
{
    isMainLoaded = isMain;
    myLanguageModel->setMainLoaded(isMain);  // Set to prevent triggers
    setMessagingStates(isMain);
}
/************************************************
 * @brief get Main Loaded Set to prevent triggers.
 * getMainLoaded
 ***********************************************/
bool MainWindow::getMainLoaded()
{
    return isMainLoaded;
}
/************************************************
 * @brief set Database Model is called from main.c.
 * setDatabaseModel
 ***********************************************/
void MainWindow::setDatabaseModel()
{
    myUiLanguageName = myLanguageModel->languageCodeToName(myLanguageModel->getDefaultLanguageCode());
    //
    myDbModel = new MyDatatables(myLanguageModel, this);
    myDbModel->setProjectDefaultStatus(myDbModel->getProjectStatus());
    // Read in Settings First
    readSettingsFirst();
    // Progress bar
    connect(myLanguageModel->mySetting, &MyOrgSettings::sendInternetProgress, this, &MainWindow::onInternetProgress);
    // Do a one time Single Shot call to onRunFirstOnStartup to allow the GUI to load before calling what is in that call
    QTimer::singleShot(666, this, &MainWindow::onRunFirstOnStartup);
}
/************************************************
 * @brief retranslate.
 * retranslate
 ***********************************************/
void MainWindow::retranslate()
{
    if (!getMainLoaded()) { return; }
    myLanguageModel->mySetting->setMessage("retranslate", "retranslate", MyOrgSettings::MyMessageTypes::Debug);
    // FIXME
    // readAllSettings setProjectID
    fillForms(myDbModel->getProjectID());
    //
    loadLanguageComboBox();
    loadProjectComboBox(myDbModel->getProjectName());
    loadProjectComboBoxDateTimeFormatStarted();
    loadProjectComboBoxDateTimeFormatDue();

    loadProjectProgressStatusComboBox(myDbModel->getProjectName(), myDbModel->getProjectStatus());
    //
    setLastLanguageName(ui->comboBoxLanguage->currentText());
}
/************************************************
 * @brief load Language.
 * loadLanguage
 ***********************************************/
void MainWindow::loadLanguage(const QString &thisLanguage)
{
    if (getLastLanguageName() != thisLanguage)
    {
        myLanguageModel->setLanguage(thisLanguage);
        //loadLanguageComboBox();
    }
}
/************************************************
 * @brief Write All Settings.
 * writeAllSettings
 ***********************************************/
void MainWindow::writeAllSettings()
{
    myLanguageModel->mySetting->setMessage("write All Settings", "writeAllSettings", MyOrgSettings::MyMessageTypes::Debug);
    // Debug Messaging
    myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_IS_DEBUG_MESSAGE, isDebugMessage ? "true" : "false");
    // Language
    myLanguageModel->setLanguageCode(myLanguageModel->languageNameToCode(ui->comboBoxLanguage->currentText()));
    myLanguageModel->setLanguageName(ui->comboBoxLanguage->currentText());
    //myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_LOCALE_LANG_CODE, thisCurrentLanguageCode);
    myLanguageModel->writeLanguage();
    // Last Tab
    myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_LAST_TAB_INDEX, QString::number(ui->tabWidget->currentIndex()));
    // Last Status Index
    myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_PROJECT_STATUS, ui->comboBoxProgressStatus->currentText().trimmed());
    // Last Project
    myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_PROJECT_NAME, ui->comboBoxProjects->currentText().trimmed());


    // Write Geometry on exit
    myLanguageModel->mySetting->setGeometry(saveGeometry());
    myLanguageModel->mySetting->setWindowState(saveState());
    //
    #ifdef USE_SQL_FLAG
    writeSqlDatabaseInfo();
    #endif
}
/************************************************
 * @brief read Settings.
 * readAllSettings
 ***********************************************/
void MainWindow::readAllSettings()
{
    myLanguageModel->mySetting->setMessage("read All Settings", "readAllSettings", MyOrgSettings::MyMessageTypes::Debug);
    restoreGeometry(myLanguageModel->mySetting->getGeometry());
    restoreState(myLanguageModel->mySetting->getWindowState());
    //
    // SQL Memory option Chech
    // default set to myProjectID="-1"
    QString theProjectID = myLanguageModel->mySetting->readSettings(myLanguageModel->mySetting->MY_SQL_PROJECT_ID, myDbModel->getProjectID());
    // We cannot read from the database yet, we are only getting the last states we know of
    if (theProjectID != "-1") { myDbModel->setProjectID(theProjectID); } else { myDbModel->setProjectID("1"); }
    myDbModel->setProjectName(myLanguageModel->mySetting->readSettings(myLanguageModel->mySetting->MY_SQL_PROJECT_NAME, myDbModel->getProjectName()));
    myDbModel->setProjectStatus(myLanguageModel->mySetting->readSettings(myLanguageModel->mySetting->MY_PROJECT_STATUS, myDbModel->getProjectDefaultStatus()));
    // Project ID
    ui->labelProjectsRecordId->setText(myDbModel->getProjectID());
    // FIXME

    //
    #ifdef USE_SQL_FLAG
    readSqlDatabaseInfo();
    #endif
}
/************************************************
 * @brief write SQL Database Info Uses SimpleCrypt to encrypt and decrypt Password.
 * writeSqlDatabaseInfo
 ***********************************************/
void MainWindow::writeSqlDatabaseInfo()
{
    myLanguageModel->mySetting->setMessage("write Sql Database Info", "writeSqlDatabaseInfo", MyOrgSettings::MyMessageTypes::Debug);
    #ifdef USE_SQL_FLAG
    // SQL Database Type Value
    myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_TYPE, ui->comboBoxSqlDatabaseType->currentText());
    // SQL Database Name
    myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_NAME,  ui->lineEditSqlDatabaseName->text());
    // SQL Database Type Host
    myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_HOST,  ui->lineEditSqlHostName->text());
    // SQL Database Type User
    myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_USER,  ui->lineEditSqlUserName->text());
    // SQL Encrypted Password, it is saved in Ini file
    if (!ui->lineEditSqlPassword->text().isEmpty())
        { myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_PASS, myLanguageModel->mySetting->encryptThis(ui->lineEditSqlPassword->text())); }
    #endif
}
/************************************************
 * @brief read SQL Database Info Uses SimpleCrypt to encrypt and decrypt Password.
 * readSqlDatabaseInfo
 ***********************************************/
void MainWindow::readSqlDatabaseInfo()
{
    #ifdef USE_SQL_FLAG
    myLanguageModel->mySetting->setMessage("read Sql Database Info", "readSqlDatabaseInfo", MyOrgSettings::MyMessageTypes::Debug);
    myDbType = myLanguageModel->mySetting->readSettings(myLanguageModel->mySetting->MY_SQL_DB_TYPE, myLanguageModel->mySetting->MY_DEFAULT_SQL);

    myDbModel->setSqlDriver(myDbType);
    if (myDbType == ":memory:")
    {
        // Database Name
        myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_NAME, "");
        ui->lineEditSqlDatabaseName->setText("");
        // Host Name
        myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_HOST, "");
        ui->lineEditSqlHostName->setText(""); // No Default
        // SQL User
        myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_USER, "");
        ui->lineEditSqlUserName->setText(""); // No Default
        // SQL Decrypt Password, it is saved in Ini file
        myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_PASS, "");
        ui->lineEditSqlPassword->setText("");
    }
    else
    {
        // There is no way to know if it read the default value if you pass it in
        QString theDb = myLanguageModel->mySetting->readSettings(myLanguageModel->mySetting->MY_SQL_DB_NAME);
        if (theDb.isEmpty())
        {
            theDb = myDbModel->getSqlLiteDbName();
            myLanguageModel->mySetting->writeSettings(myLanguageModel->mySetting->MY_SQL_DB_NAME, theDb);
        }
        // SQL Database Name
        ui->lineEditSqlDatabaseName->setText(theDb);
        // Set ComboBox for SQL
        ui->comboBoxSqlDatabaseType->setCurrentIndex(ui->comboBoxSqlDatabaseType->findText(myDbType));
        // SQL Type Value
        //mySqlDb->setComboBoxSqlValue(myLanguageModel->mySetting->readSettings(myLanguageModel->mySetting->MY_SQL_DB_TYPE, myLanguageModel->mySetting->MY_SQL_DEFAULT));
        // SQL Host
        ui->lineEditSqlHostName->setText(myLanguageModel->mySetting->readSettings(myLanguageModel->mySetting->MY_SQL_DB_HOST, "")); // No Default
        // SQL User
        ui->lineEditSqlUserName->setText(myLanguageModel->mySetting->readSettings(myLanguageModel->mySetting->MY_SQL_DB_USER, "")); // No Default
        // SQL Decrypt Password, it is saved in Ini file
        QString thePassword = myLanguageModel->mySetting->decryptThis(myLanguageModel->mySetting->readSettings(myLanguageModel->mySetting->MY_SQL_DB_PASS, ""));
        if (!thePassword.isEmpty())
            { ui->lineEditSqlPassword->setText(thePassword); }
        else
            { ui->lineEditSqlPassword->setText(""); }
    }
    setSqlBrowseButton();
    #endif
}
/************************************************
 * @brief on Author.
 * onAuthor
 ***********************************************/
void MainWindow::onAuthor()
{
    myLanguageModel->mySetting->setMessage("on Author", "onAuthor", MyOrgSettings::MyMessageTypes::Debug);
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabHelp")));
    //
    QString theFileName = QString(":help/About-Author_%1.md").arg(myLanguageModel->getLanguageCode());
    if (!myLanguageModel->mySetting->isFileExists(theFileName))
        { theFileName = QString(":help/About-Author_%1.md").arg(myLanguageModel->mySetting->MY_DEFAULT_LANGUAGE_CODE); }
    ui->textEditHelp->setMarkdown(myLanguageModel->mySetting->readFile(theFileName));
}
/************************************************
 * @brief Main Window Destructor.
 * onAbout
 ***********************************************/
void MainWindow::onAbout()
{
    myLanguageModel->mySetting->setMessage("on About", "onAbout", MyOrgSettings::MyMessageTypes::Debug);
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabHelp")));
    //
    QString theFileName = QString(":help/About_%1.md").arg(myLanguageModel->getLanguageCode());
    if (!myLanguageModel->mySetting->isFileExists(theFileName))
        { theFileName = QString(":help/About_%1.md").arg(myLanguageModel->mySetting->MY_DEFAULT_LANGUAGE_CODE); }
    ui->textEditHelp->setMarkdown(myLanguageModel->mySetting->readFile(theFileName));
}
/************************************************
 * @brief Help.
 * onHelp
 ***********************************************/
void MainWindow::onHelp()
{
    myLanguageModel->mySetting->setMessage("on Help", "onHelp", MyOrgSettings::MyMessageTypes::Debug);
    // Go to Tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabWidget->findChild<QWidget*>("tabHelp")));
    //
    QString theFileName = QString(":help/Help_%1.md").arg(myLanguageModel->getLanguageCode());
    if (!myLanguageModel->mySetting->isFileExists(theFileName))
    { theFileName = QString(":help/Help_%1.md").arg(myLanguageModel->mySetting->MY_DEFAULT_LANGUAGE_CODE); }
    QString theFileContent = myLanguageModel->mySetting->readFile(theFileName);
    // Do not translate this file
    QString theLanguageFileName = ":help/Language.txt";
    if (myLanguageModel->mySetting->isFileExists(theLanguageFileName))
        { theFileContent.append(myLanguageModel->mySetting->readFile(theLanguageFileName)); }
    ui->textEditHelp->setMarkdown(theFileContent);
}
/************************************************
 * @brief on comboBox Language current Index Changed.
 * on_comboBoxLanguage_currentIndexChanged
 ***********************************************/
void MainWindow::on_comboBoxLanguage_currentIndexChanged(const QString &thisLanguage)
{
    if (!getMainLoaded()) { return; }
    loadLanguage(thisLanguage);
}
/************************************************
 * @brief load Language ComboBox.
 * loadLanguageComboBox
 ***********************************************/
void MainWindow::loadLanguageComboBox()
{
    myLanguageModel->mySetting->setMessage("load Language ComboBox", "loadLanguageComboBox", MyOrgSettings::MyMessageTypes::Debug);
    bool lastMainLoaded = getMainLoaded();
    setMainLoaded(false);
    int theCurrentIndex = ui->comboBoxLanguage->currentIndex();
    ui->comboBoxLanguage->clear();
    const QStringList theQmFiles =  myLanguageModel->getQmFiles(myLanguageModel->getTranslationSource());
    QStandardItemModel *theLangModel = new QStandardItemModel(this);
    theLangModel->setColumnCount(2);
    for (int i = 0; i < theQmFiles.size(); ++i)
    {
        QString theLanguageName = myLanguageModel->getLanguageFromFile(myLanguageModel->getTransFilePrefix(), theQmFiles.at(i));
        QStandardItem* theCol0 = new QStandardItem(theLanguageName);
        QStandardItem* theCol1 = new QStandardItem(myLanguageModel->translateThis(theLanguageName));
        theLangModel->setItem(i, 0, theCol0);
        theLangModel->setItem(i, 1, theCol1);
    } // end for
    QTableView* theTableView = new QTableView(this);
    theTableView->setModel(theLangModel);
    theTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    theTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    theTableView->setAutoScroll(false);
    theTableView->verticalHeader()->setVisible(false);
    theTableView->horizontalHeader()->setVisible(false);
    theTableView->setColumnWidth (0, 196);
    theTableView->setColumnWidth (1, 196);
    // Set comboBox
    ui->comboBoxLanguage->setMinimumWidth(400);
    ui->comboBoxLanguage->setModel(theLangModel);
    ui->comboBoxLanguage->setView(theTableView);
    // Bold UI Language name
    QStandardItemModel *m = qobject_cast<QStandardItemModel *>(ui->comboBoxLanguage->model());
    // FIXME
    QString theDefaultLangageName = myLanguageModel->languageCodeToName(myLanguageModel->getDefaultLanguageCode());
    QStandardItem *item = m ? m->item(ui->comboBoxLanguage->findText(theDefaultLangageName)) : nullptr;
    if (item)
    {
        auto f = item->font();
        f.setBold(true);
        item->setFont(f);
    }
    if (theCurrentIndex > 0)
    {
        ui->comboBoxLanguage->setCurrentIndex(theCurrentIndex);
    }
    else
    {
        ui->comboBoxLanguage->setCurrentIndex(ui->comboBoxLanguage->findText(myLanguageModel->getLanguageName()));
    }
    setMainLoaded(lastMainLoaded);  // Set to prevent triggers
}
/************************************************
 * @brief set SQL Browse Button.
 * setSqlBrowseButton
 ***********************************************/
void MainWindow::setSqlBrowseButton()
{
    myLanguageModel->mySetting->setMessage("setSqlBrowseButton", "setSqlBrowseButton", MyOrgSettings::MyMessageTypes::Debug);
    ui->pushButtonSqlDatabaseNameBrowse->setEnabled(ui->comboBoxSqlDatabaseType->currentText() == myLanguageModel->mySetting->MY_SQL_DEFAULT);
    ui->pushButtonSqlDatabaseNameBrowse->setVisible(ui->comboBoxSqlDatabaseType->currentText() == myLanguageModel->mySetting->MY_SQL_DEFAULT);
}
/************************************************
 * @brief on comboBox SQL Database Type current Index Changed.
 * on_comboBoxSqlDatabaseType_currentIndexChanged
 ***********************************************/
void MainWindow::on_comboBoxSqlDatabaseType_currentIndexChanged(const QString &thisSqlType)
{
    if (!getMainLoaded()) { return; }
    myLanguageModel->mySetting->setMessage("on comboBox Sql Database Type current Index Changed", QString("%1: %2").arg("on_comboBoxSqlDatabaseType_currentIndexChanged", thisSqlType), MyOrgSettings::MyMessageTypes::Debug);
    if (myDbModel->setSqlDriver(thisSqlType))
    {
        readSqlDatabaseInfo();
        if (!myDbModel->createDatabaseConnection(myDbType))
        {
            myLanguageModel->mySetting->setMessage("on comboBox Sql Database Type current Index Changed", QString("%1: %2 - %3").arg(QObject::tr("Could not connect to SQL Database"), "on_comboBoxSqlDatabaseType_currentIndexChanged", thisSqlType), MyOrgSettings::MyMessageTypes::Critical);
        }
    }
}
/************************************************
 * @brief SQL Database Name Browse clicked.
 * on_pushButtonSqlDatabaseNameBrowse_clicked
 ***********************************************/
void MainWindow::on_pushButtonSqlDatabaseNameBrowse_clicked()
{
    myLanguageModel->mySetting->setMessage("on_pushButtonSqlDatabaseNameBrowse_clicked", "on_pushButtonSqlDatabaseNameBrowse_clicked", MyOrgSettings::MyMessageTypes::Debug);
    QFileDialog dialogSqlDbFolder;
    dialogSqlDbFolder.setFileMode(QFileDialog::Directory);
    dialogSqlDbFolder.setOption(QFileDialog::ShowDirsOnly);
    dialogSqlDbFolder.setOption(QFileDialog::DontResolveSymlinks);
    //
    QString theSqlFolder = dialogSqlDbFolder.getExistingDirectory(this, tr("Sqlite Folder Location"), myLanguageModel->mySetting->getAppDataLocation());
    if (!theSqlFolder.isEmpty())
    {
        QString theDbLocation = ui->lineEditSqlDatabaseName->text();
        QString theDbNewLocation = QString("%1/%2.db").arg(theSqlFolder, myDbModel->getSqlDatabaseName());
        if (theDbLocation != theDbNewLocation)
        {
            //
            if (myLanguageModel->mySetting->getFileInfo(MyOrgSettings::IsFile, ui->lineEditSqlDatabaseName->text()) == "true")
            {
                QString thePath = myLanguageModel->mySetting->getFileInfo(MyOrgSettings::CanonicalFilePath, ui->lineEditSqlDatabaseName->text());
                // moveDb
                if (myDbModel->moveDb(theDbNewLocation, thePath, theDbNewLocation))
                { ui->lineEditSqlDatabaseName->setText(theDbNewLocation); }
                else
                { myLanguageModel->mySetting->showMessageBox(QObject::tr("Database Move Failed").toLocal8Bit(), QString("%1: %2").arg(tr("Failed to move Database"), ui->lineEditSqlDatabaseName->text()).toLocal8Bit(), myLanguageModel->mySetting->Critical); }
            }
        }
    }
}
/************************************************
 * @brief on pushButton SQL Password Show clicked.
 * on_pushButtonSqlPasswordShow_clicked
 ***********************************************/
void MainWindow::on_pushButtonSqlPasswordShow_clicked()
{
    myLanguageModel->mySetting->setMessage("on_pushButtonSqlPasswordShow_clicked", "on_pushButtonSqlPasswordShow_clicked", MyOrgSettings::MyMessageTypes::Debug);
    if (ui->pushButtonSqlPasswordShow->text() == "Show")
    {
        ui->pushButtonSqlPasswordShow->setText(tr("Hide"));
        ui->lineEditSqlPassword->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->pushButtonSqlPasswordShow->setText(tr("Show"));
        ui->lineEditSqlPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    }
}
/************************************************
 * @brief on pushButton SQL Save clicked.
 * on_pushButtonSqlSave_clicked
 ***********************************************/
void MainWindow::on_pushButtonSqlSave_clicked()
{
    myLanguageModel->mySetting->setMessage("on_pushButtonSqlDatabaseNameBrowse_clicked", "on_pushButtonSqlDatabaseNameBrowse_clicked", MyOrgSettings::MyMessageTypes::Debug);
    writeAllSettings();
    setSqlBrowseButton();
}
/************************************************
 * @brief set Language Model.
 * setLanguageModel
 ***********************************************/
void MainWindow::setLanguageModel(MyLanguageModel *thisLanguageModel)
{
    myLanguageModel = thisLanguageModel;
    myLanguageModel->mySetting->setMessage("set Language Model", "setLanguageModel", MyOrgSettings::MyMessageTypes::Debug);
    setDatabaseModel();
}
/************************************************
 * @brief get Lanuguage Model.
 * getLanuguageModel
 ***********************************************/
MyLanguageModel MainWindow::getLanuguageModel()
{
    myLanguageModel->mySetting->setMessage("get Lanuguage Model", "getLanuguageModel", MyOrgSettings::MyMessageTypes::Debug);
    return myLanguageModel;
}
/************************************************
 * @brief loadDateTimeFormatStarted.
 * loadDateTimeFormatStarted
 ***********************************************/
void MainWindow::loadProjectComboBoxDateTimeFormatStarted()
{
    myLanguageModel->mySetting->setMessage("loadDateTimeFormatStarted", "loadDateTimeFormatStarted", MyOrgSettings::MyMessageTypes::Debug);
    //
    QMetaEnum theEnum = QMetaEnum::fromType<MyDatatables::MyDateTimeFormat>();
    bool lastMainLoaded = getMainLoaded();
    setMainLoaded(false);
    int theCurrentIndex = ui->comboBoxProjectsDateTimeFormatStart->currentIndex();
    if (theCurrentIndex < 0)
    {
        theCurrentIndex = -1; // FIXME
    }
    ui->comboBoxProjectsDateTimeFormatStart->clear();
    //
    QStandardItemModel *theLangModel = new QStandardItemModel(this);
    theLangModel->setColumnCount(2);
    for (int theKeyIndex = 0; theKeyIndex < theEnum.keyCount(); theKeyIndex++)
    {
        QString theLanguageName = theEnum.key(theKeyIndex);
        //QString theLanguageName = myQOnlineTranslator.languageNameToCode(e.key(k));
        QStandardItem* theCol0 = new QStandardItem(theLanguageName);
        QStandardItem* theCol1 = new QStandardItem(tr(theLanguageName.toLocal8Bit()));
        theLangModel->setItem(theKeyIndex, 0, theCol0);
        theLangModel->setItem(theKeyIndex, 1, theCol1);
    } // end for
    QTableView* tableView = new QTableView(this);
    tableView->setModel(theLangModel);
    tableView->verticalHeader()->setVisible(false);
    tableView->horizontalHeader()->setVisible(false);
    tableView->setColumnWidth (0, 196);
    tableView->setColumnWidth (1, 196);
    tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setAutoScroll(false);
    // Set comboBox
    ui->comboBoxProjectsDateTimeFormatStart->setMinimumWidth(400);
    ui->comboBoxProjectsDateTimeFormatStart->setModel(theLangModel);
    ui->comboBoxProjectsDateTimeFormatStart->setView(tableView);
    if (theCurrentIndex == -1)
    { ui->comboBoxProjectsDateTimeFormatStart->setCurrentIndex(ui->comboBoxProjectsDateTimeFormatStart->findText(myDateTimeFormatStartedValue)); }
    else
    { ui->comboBoxProjectsDateTimeFormatStart->setCurrentIndex(theCurrentIndex); }
    setDateTimeFormat(myDbModel->getDateTimeFormatCode(myDateTimeFormatStartedValue), "Start");
    setMainLoaded(lastMainLoaded);  // Set to prevent triggers
}
/************************************************
 * @brief loadDateTimeFormatDue.
 * loadDateTimeFormatDue
 ***********************************************/
void MainWindow::loadProjectComboBoxDateTimeFormatDue()
{
    myLanguageModel->mySetting->setMessage("loadDateTimeFormatDue", "loadDateTimeFormatDue", MyOrgSettings::MyMessageTypes::Debug);
    //
    QMetaEnum theEnum = QMetaEnum::fromType<MyDatatables::MyDateTimeFormat>();
    bool lastMainLoaded = getMainLoaded();
    setMainLoaded(false);  // Set to prevent triggers
    int theCurrentIndex = ui->comboBoxProjectsDateTimeFormatDue->currentIndex();
    if (theCurrentIndex < 0)
    {
        theCurrentIndex = -1; // FIXME
    }
    ui->comboBoxProjectsDateTimeFormatDue->clear();
    //
    QStandardItemModel *theLangModel = new QStandardItemModel(this);
    theLangModel->setColumnCount(2);
    for (int theKeyIndex = 0; theKeyIndex < theEnum.keyCount(); theKeyIndex++)
    {
        QString theLanguageName = theEnum.key(theKeyIndex);
        //QString theLanguageName = myQOnlineTranslator.languageNameToCode(e.key(k));
        QStandardItem* theCol0 = new QStandardItem(theLanguageName);
        QStandardItem* theCol1 = new QStandardItem(tr(theLanguageName.toLocal8Bit()));
        theLangModel->setItem(theKeyIndex, 0, theCol0);
        theLangModel->setItem(theKeyIndex, 1, theCol1);
    } // end for
    QTableView* tableView = new QTableView(this);
    tableView->setModel(theLangModel);
    tableView->verticalHeader()->setVisible(false);
    tableView->horizontalHeader()->setVisible(false);
    tableView->setColumnWidth (0, 196);
    tableView->setColumnWidth (1, 196);
    tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setAutoScroll(false);
    // Set comboBox
    ui->comboBoxProjectsDateTimeFormatDue->setMinimumWidth(400);
    ui->comboBoxProjectsDateTimeFormatDue->setModel(theLangModel);
    ui->comboBoxProjectsDateTimeFormatDue->setView(tableView);
    if (theCurrentIndex == -1)
    { ui->comboBoxProjectsDateTimeFormatDue->setCurrentIndex(ui->comboBoxProjectsDateTimeFormatDue->findText(myDateTimeFormatDueValue)); }
    else
    { ui->comboBoxProjectsDateTimeFormatDue->setCurrentIndex(theCurrentIndex); }
    setMainLoaded(lastMainLoaded);  // Set to prevent triggers
}
/************************************************
 * @brief load Project Combo.
 * loadProjectCombo
 ***********************************************/
void MainWindow::loadProjectComboBox(const QString &thisProjectName)
{
    myLanguageModel->mySetting->setMessage("load Project ComboBox", "loadProjectComboBox", MyOrgSettings::MyMessageTypes::Debug);
    #ifdef USE_SQL_FLAG
    bool lastMainLoaded = getMainLoaded();
    // FIXME setProject();
    setMainLoaded(false); // Set to prevent triggers
    ui->comboBoxProjects->clear();
    QSqlQueryModel *theModal = new QSqlQueryModel(this); //!< SQL Query Model
    //  SELECT id, ProjectName FROM Projects
    const auto SELECTED_PROJECTS_SQL = QLatin1String(R"(%1)").arg(myDbModel->getProjectNameSelectQuery());
    theModal->setQuery(SELECTED_PROJECTS_SQL);
    if (theModal->lastError().isValid()) { qWarning() << theModal->lastError(); }
    theModal->setHeaderData(0,Qt::Horizontal, tr("ID"));
    theModal->setHeaderData(1, Qt::Horizontal, tr("Project"));
    QTableView *theTableView = new QTableView;
    theTableView->setModel(theModal);
    theTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    theTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    theTableView->verticalHeader()->setVisible(false);
    theTableView->horizontalHeader()->setVisible(false);
    theTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    theTableView->setAutoScroll(false);
    //theTableView->setColumnHidden(0, true);
    theTableView->setColumnWidth (1, 296);
    ui->comboBoxProjects->setModel(theModal);
    ui->comboBoxProjects->setView(theTableView);
    ui->comboBoxProjects->setMinimumWidth(300);
    ui->comboBoxProjects->setModelColumn(1);
    ui->comboBoxProjects->setCurrentIndex(0);
    // Set by Project name or Index
    if (thisProjectName.isEmpty())
    {
        ui->comboBoxProjects->setCurrentIndex(0);
        fillForms(getComboBoxProjectsID(0));
    }
    else
    {
        ui->comboBoxProjects->setCurrentIndex(ui->comboBoxProjects->findText(thisProjectName));
    }
    setMainLoaded(lastMainLoaded);  // Set to prevent triggers
    #endif
}
/************************************************
 * @brief load Project Progress Status Combo.
 * loadProjectProgressStatusComboBox
 ***********************************************/
void MainWindow::loadProjectProgressStatusComboBox(const QString &thisProjectName, const QString &thisStatusName)
{
    myLanguageModel->mySetting->setMessage("load Project Progress Status ComboBox", QString("%1(%2)").arg(tr("loadProjectProgressStatusComboBox"), thisStatusName), MyOrgSettings::MyMessageTypes::Debug);
    #ifdef USE_SQL_FLAG
    QString theStatusName = thisStatusName.trimmed();
    bool lastMainLoaded = getMainLoaded();
    setMainLoaded(false);  // Set to prevent triggers
    ui->comboBoxProgressStatus->clear();
    QSqlQueryModel *theModal = new QSqlQueryModel(this); //!< SQL Query Model
    //  SELECT id, ProjectName FROM Projects
    const auto SELECTED_PROGRESS_SQL = QLatin1String(R"(%1)").arg(myDbModel->getProgressStatusSelectQuery(thisProjectName));
    theModal->setQuery(SELECTED_PROGRESS_SQL);
    if (theModal->lastError().isValid()) { qWarning() << theModal->lastError(); }
    theModal->setHeaderData(0,Qt::Horizontal, tr("ID"));
    theModal->setHeaderData(1, Qt::Horizontal, tr("Progress Status"));
    QTableView *theTableView = new QTableView;
    theTableView->setModel(theModal);
    theTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    theTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    theTableView->verticalHeader()->setVisible(false);
    theTableView->horizontalHeader()->setVisible(false);
    theTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    theTableView->setAutoScroll(false);
    //theTableView->setColumnHidden(0, true);
    theTableView->setColumnWidth (1, 296);
    ui->comboBoxProgressStatus->setModel(theModal);
    ui->comboBoxProgressStatus->setView(theTableView);
    ui->comboBoxProgressStatus->setMinimumWidth(300);
    ui->comboBoxProgressStatus->setModelColumn(1);
    ui->comboBoxProgressStatus->setCurrentIndex(0);
    // Set by Project Progress name or Index
    if (theStatusName.isEmpty())
    {
        ui->comboBoxProgressStatus->setCurrentIndex(-1);
    }
    else
    {
        int theIndex = ui->comboBoxProgressStatus->findText(theStatusName);
        if (theIndex < 0)
        {
            if (ui->comboBoxProgressStatus->count() > 0)
            {
                ui->comboBoxProgressStatus->setCurrentIndex(0);
                theStatusName = ui->comboBoxProgressStatus->currentText();
            }
        }
        ui->comboBoxProgressStatus->setCurrentIndex(ui->comboBoxProgressStatus->findText(theStatusName));
    }
    ui->lineEditProjectsProgressStatus->setText(ui->comboBoxProgressStatus->currentText());
    setMainLoaded(lastMainLoaded);  // Set to prevent triggers
    #endif
}
/************************************************
 * @brief clear Forms.
 * clearForms
 ***********************************************/
void MainWindow::clearForm(const QString &thisIndexStart, const QString &thisIndexDue)
{
    myLanguageModel->mySetting->setMessage("clear Form", "clearForm", MyOrgSettings::MyMessageTypes::Debug);
    if (ui->pushButtonProjectsClear->text() == tr("Clear"))
    {
        ui->pushButtonProjectsClear->setText(tr("Unclear"));
        int theLastMain = getMainLoaded();
        setMainLoaded(false);
        myLastProjectID = ui->comboBoxProjects->currentIndex();
        ui->comboBoxProjects->setCurrentIndex(-1);
        ui->comboBoxProjects->setEnabled(false);

        ui->comboBoxProjectsDateTimeFormatStart->setCurrentIndex(ui->comboBoxProjectsDateTimeFormatStart->findText(thisIndexStart));
        ui->comboBoxProjectsDateTimeFormatDue->setCurrentIndex(ui->comboBoxProjectsDateTimeFormatDue->findText(thisIndexDue));
        setDateTimeFormat(myDbModel->getDateTimeFormatCode(ui->comboBoxProjectsDateTimeFormatStart->currentText()), "Start");
        setDateTimeFormat(myDbModel->getDateTimeFormatCode(ui->comboBoxProjectsDateTimeFormatDue->currentText()), "Due");

        myLastStatusID = ui->comboBoxProgressStatus->currentIndex();
        ui->comboBoxProgressStatus->setCurrentIndex(-1);
        ui->comboBoxProgressStatus->setEnabled(false);
        ui->pushButtonProjectsProgressStatusAdd->setEnabled(false);
        ui->pushButtonProjectsProgressStatusDelete->setEnabled(false);
        ui->pushButtonProjectsProgressStatusModify->setEnabled(false);

        ui->lineEditProjectsProgressStatus->clear();
        ui->lineEditProjectsName->clear();
        ui->textEditProjectDescription->clear();
        ui->textEditProjectsProgress->clear();
        ui->checkBoxProjectsAssigned->setCheckState(Qt::CheckState::Unchecked);
        ui->checkBoxProjectsApproved->setCheckState(Qt::CheckState::Unchecked);
        ui->dateTimeEditProjectsDateDue->setDateTime(myDbModel->getDateTimeFromNow(0));
        ui->dateTimeEditProjectsDateStart->setDateTime(myDbModel->getDateTimeFromNow(0));
        ui->radioButtonProjectsCompleted->setChecked(false);
        ui->radioButtonProjectsStarted->setChecked(false);
        ui->pushButtonProjectsSave->setEnabled(false);
        ui->pushButtonProjectsDelete->setEnabled(false);
        ui->lineEditProjectsPassword->clear();
        setMainLoaded(theLastMain);
        validateProjectName("");
    }
    else
    {
        ui->pushButtonProjectsClear->setText(tr("Clear"));
        ui->comboBoxProjects->setEnabled(true);
        ui->comboBoxProjects->setCurrentIndex(myLastProjectID);

        ui->pushButtonProjectsSave->setEnabled(true);
        ui->pushButtonProjectsDelete->setEnabled(true);

        ui->comboBoxProgressStatus->setEnabled(true);
        ui->comboBoxProgressStatus->setCurrentIndex(myLastStatusID);
    }
} // end clearForm
/************************************************
 * @brief on pushButton Projects Save clicked.
 * on_pushButtonProjectsSave_clicked
 ***********************************************/
void MainWindow::on_pushButtonProjectsSave_clicked()
{
    myLanguageModel->mySetting->setMessage("on pushButton Projects Save clicked", "on_pushButtonProjectsSave_clicked", MyOrgSettings::MyMessageTypes::Debug);
    onSaveAll(ui->comboBoxProgressStatus->currentText());
}
/************************************************
 * @brief on Save.
 * onSave
 ***********************************************/
void MainWindow::onSave()
{
    onSaveAll(ui->comboBoxProgressStatus->currentText());
}
/************************************************
 * @brief on Save.
 * onSave
 ***********************************************/
void MainWindow::onSaveAll(const QString &thisStatus)
{
    myLanguageModel->mySetting->setMessage("on Save", QString("%1(%2)").arg("onSave", ui->comboBoxProgressStatus->currentText()), MyOrgSettings::MyMessageTypes::Debug);
    setProjects();
    QString theStatus = thisStatus.trimmed();
    if (theStatus.isEmpty())
    {
        if (ui->comboBoxProgressStatus->currentText().isEmpty())
        {
            if (!ui->lineEditProjectsProgressStatus->text().isEmpty())
            {
                theStatus = ui->lineEditProjectsProgressStatus->text().trimmed();
            }
        }
        else
        {
            theStatus = ui->comboBoxProgressStatus->currentText().trimmed();
        }
    }
    setProgressStatus(theStatus);
    //
    bool theComboReload = false;
    QString theProjectName = "";
    if (ui->comboBoxProjects->currentText().isEmpty())
    {
        if (!ui->lineEditProjectsName->text().isEmpty())
        {
            theProjectName = ui->lineEditProjectsName->text();
        }
    }
    else
    {
        if (!ui->lineEditProjectsName->text().isEmpty())
        {
            theProjectName = ui->lineEditProjectsName->text();
            if (ui->comboBoxProjects->currentText() != ui->lineEditProjectsName->text())
            { theComboReload = true; }
        }
    }
    myDbModel->saveProject();
    if (theComboReload)
        { loadProjectComboBox(theProjectName); }
    myDbModel->saveProgressStatus();
    // ui->lineEditProjectsName->text() ui->lineEditProjectsProgressStatus->text()
    loadProjectProgressStatusComboBox(myDbModel->myProgress->getProjectName(), myDbModel->myProgress->getStatusName());
    //
    on_pushButtonSqlSave_clicked();
}
/************************************************
 * @brief on pushButton Projects Delete clicked.
 * on_pushButtonProjectsDelete_clicked
 ***********************************************/
void MainWindow::on_pushButtonProjectsDelete_clicked()
{
    myLanguageModel->mySetting->setMessage("on pushButton Projects Delete clicked", "on_pushButtonProjectsDelete_clicked", MyOrgSettings::MyMessageTypes::Debug);
    setProjects();
    setProgressStatus(ui->comboBoxProgressStatus->currentText());
    myDbModel->deleteProject(ui->labelProjectsRecordId->text());
    fillForms("");
}
/************************************************
 * @brief on pushButton Projects Add clicked.
 * on_pushButtonProjectsAdd_clicked
 ***********************************************/
void MainWindow::on_pushButtonProjectsAdd_clicked()
{
    myLanguageModel->mySetting->setMessage("on pushButton Projects Add clicked", "on_pushButtonProjectsAdd_clicked", MyOrgSettings::MyMessageTypes::Debug);
    setProjects();
    setProgressStatus(myDbModel->getProjectStatus());
    myDbModel->addProject();
    myDbModel->myProject->setID(myDbModel->getRecordID());
    myDbModel->addProgressStatus(myDbModel->myProject->getProjectName());
    loadProjectComboBox(myDbModel->myProject->getProjectName());
    fillForms(myDbModel->myProject->getID());
}
/************************************************
 * @brief on pushButton Projects Clear clicked.
 * on_pushButtonProjectsClear_clicked
 ***********************************************/
void MainWindow::on_pushButtonProjectsClear_clicked()
{
    myLanguageModel->mySetting->setMessage("on pushButton Projects Clear clicked", "on_pushButtonProjectsClear_clicked", MyOrgSettings::MyMessageTypes::Debug);
    clearForm("", "");
}
/************************************************
 * @brief on comboBox Projects current Index Changed.
 * on_comboBoxProjects_currentIndexChanged
 ***********************************************/
void MainWindow::on_comboBoxProjects_currentIndexChanged(int thisIndex)
{
    myLanguageModel->mySetting->setMessage("on comboBox Projects current Index Changed", QString("%1(%2)").arg("on_comboBoxProjects_currentIndexChanged", thisIndex), MyOrgSettings::MyMessageTypes::Debug);
    if (!getMainLoaded()) { return; }
    // We have to get the ID from the Model
    fillForms(getComboBoxProjectsID(thisIndex));
}
/************************************************
 * @brief get ComboBox Projects ID.
 * getComboBoxProjectsID
 ***********************************************/
QString MainWindow::getComboBoxProjectsID(int thisIndex)
{
    QAbstractItemModel *theModel = ui->comboBoxProjects->model();
    QModelIndex theIndex = theModel->index(thisIndex, 0); // 0 Refers to the first item or ID
    return theModel->data(theIndex).toString().trimmed(); // Returns 'Item 0'
}
/************************************************
 * @brief get ComboBox Progress Status ID.
 * getComboBoxProgressStatusID
 ***********************************************/
QString MainWindow::getComboBoxProgressStatusID(int thisIndex)
{
    QAbstractItemModel *theModel = ui->comboBoxProgressStatus->model();
    QModelIndex theIndex = theModel->index(thisIndex, 0); // 0 Refers to the first item or ID
    myLanguageModel->mySetting->setMessage("getComboBoxProgressStatusID", QString("%1: %2 < %3").arg("getComboBoxProgressStatusID", QString::number(thisIndex), theModel->data(theIndex).toString()), MyOrgSettings::MyMessageTypes::Debug);
    return theModel->data(theIndex).toString(); // Returns 'Item 0'
}/************************************************
 * @brief on pushButton Projects Date Due clicked.
 * on_pushButtonProjectsDateDue_clicked
 ***********************************************/
void MainWindow::on_pushButtonProjectsDateDue_clicked()
{
    myLanguageModel->mySetting->setMessage("on pushButton Projects Date Due clicked", "on_pushButtonProjectsDateDue_clicked", MyOrgSettings::MyMessageTypes::Debug);
    ui->dateTimeEditProjectsDateDue->setDateTime(myDbModel->getDateTimeFromNow(90));
}
/************************************************
 * @brief on pushButton Projects Date Start clicked.
 * on_pushButtonProjectsDateStart_clicked
 ***********************************************/
void MainWindow::on_pushButtonProjectsDateStart_clicked()
{
    myLanguageModel->mySetting->setMessage("on_pushButtonProjectsDateStart_clicked", "on_pushButtonProjectsDateStart_clicked", MyOrgSettings::MyMessageTypes::Debug);
    ui->dateTimeEditProjectsDateStart->setDateTime(myDbModel->getDateTimeFromNow(0));
}
/************************************************
 * @brief on comboBox Projects DateTime Format Start current Index Changed.
 * on_comboBoxProjectsDateTimeFormatStart_currentIndexChanged
 ***********************************************/
void MainWindow::on_comboBoxProjectsDateTimeFormatStart_currentIndexChanged(const QString &thisDateTimeFormat)
{
    myLanguageModel->mySetting->setMessage("on comboBox Projects DateTime Format Start current Index Changed", QString("%1(%2)").arg("on_comboBoxProjectsDateTimeFormatStart_currentIndexChanged", thisDateTimeFormat), MyOrgSettings::MyMessageTypes::Debug);
    if (!getMainLoaded()) { return; }
    setDateTimeFormatStartedValue(thisDateTimeFormat);
    setDateTimeFormat(myDbModel->getDateTimeFormatCode(thisDateTimeFormat), "Start");
}
/************************************************
 * @brief set Date Time Format Started Value.
 * setDateTimeFormatStartedValue
 ***********************************************/
void MainWindow::setDateTimeFormatStartedValue(const QString &thisDateTimeFormat)
{
    myDateTimeFormatStartedValue = thisDateTimeFormat;
}
/************************************************
 * @brief get Date Time Format Started Value.
 * getDateTimeFormatStartedValue
 ***********************************************/
QString MainWindow::getDateTimeFormatStartedValue()
{
    return myDateTimeFormatStartedValue;
}
/************************************************
 * @brief set Date Time Format Due Value.
 * setDateTimeFormatDueValue
 ***********************************************/
void MainWindow::setDateTimeFormatDueValue(const QString &thisDateTimeFormat)
{
    myDateTimeFormatDueValue = thisDateTimeFormat;
}
/************************************************
 * @brief get Date Time Format Due Value.
 * getDateTimeFormatDueValue
 ***********************************************/
QString MainWindow::getDateTimeFormatDueValue()
{
    return myDateTimeFormatDueValue;
}
/************************************************
 * @brief set Last Language Name.
 * setLastLanguageName
 ***********************************************/
void MainWindow::setLastLanguageName(const QString &thisLastLanguageName)
{
    myLastLanguageName = thisLastLanguageName;
}
/************************************************
 * @brief get Last Language Name.
 * getLastLanguageName
 ***********************************************/
QString MainWindow::getLastLanguageName()
{
    return myLastLanguageName;
}
/************************************************
 * @brief on comboBox Projects DateTime Format Due current Index Changed.
 * on_comboBoxProjectsDateTimeFormatDue_currentIndexChanged
 ***********************************************/
void MainWindow::on_comboBoxProjectsDateTimeFormatDue_currentIndexChanged(const QString &thisDateTimeFormat)
{
    myLanguageModel->mySetting->setMessage("on comboBox Projects DateTime Format Due current Index Changed", QString("%1(%2)").arg("on_comboBoxProjectsDateTimeFormatDue_currentIndexChanged", thisDateTimeFormat), MyOrgSettings::MyMessageTypes::Debug);
    if (!getMainLoaded()) { return; }
    setDateTimeFormatDueValue(thisDateTimeFormat);
    setDateTimeFormat(myDbModel->getDateTimeFormatCode(thisDateTimeFormat), "Due");
}
/************************************************
 * @brief setDateTimeFormat.
 ***********************************************/
void MainWindow::setDateTimeFormat(MyDatatables::MyDateTimeFormat thisDateTimeFormat, const QString &thisComboBox)
{
    // In case you want to change it programmically
    QString theFormat;
    QString theFormatTranslated;
    switch (thisDateTimeFormat)
    {
    case MyDatatables::MonthDayYear:
        // Month/Day/Year Time
        theFormat = "Month/Day/Year Time";
        theFormatTranslated = tr("Month/Day/Year Time");
        break;
    case MyDatatables::DayMonthYear:
        // Day/Month/Year Time
        theFormat = "Day/Month/Year Time";
        theFormatTranslated = tr("Day/Month/Year Time");
        break;
    case MyDatatables::YearMonthDay:
        // Year/Month/Day Time
        theFormat = "Year/Month/Day Time";
        theFormatTranslated = tr("Year/Month/Day Time");
        break;
    case MyDatatables::YearDayMonth:
        // Year/Day/Month Time
        theFormat = "Year/Day/Month Time";
        theFormatTranslated = tr("Year/Day/Month Time");
        break;
    case MyDatatables::Military:
        // Military Time
        theFormat = "Military Time";
        theFormatTranslated = tr("Military Time");
        break;
    }
    myLanguageModel->mySetting->setMessage("setDateTimeFormat", QString("%1: %2").arg(tr("setDateTimeFormat"), myDbModel->getDateTimeFormat(theFormat)), MyOrgSettings::MyMessageTypes::Debug);
    //
    if (thisComboBox == "Due")
    {
        ui->dateTimeEditProjectsDateDue->setDisplayFormat(myDbModel->getDateTimeFormat(theFormat));
    }
    else if (thisComboBox == "Start")
    {
        ui->dateTimeEditProjectsDateStart->setDisplayFormat(myDbModel->getDateTimeFormat(theFormat));
    }
}
/************************************************
 * @brief get DataTime From String.
 * getDataTimeFromString
 ***********************************************/
QDateTime MainWindow::getDataTimeFromString(const QString &thisDateTimeString, const QString &thisControlName, const QString &thisFormatName)
{
    QDateTime dateTime;
    // Set DateTime Format to Type you want to save in the database
    setDateTimeFormat(myDbModel->MY_SQL_DATETIME_FORMAT_TYPE, thisControlName);
    // now set the DateTime control to that time
    dateTime.fromString(thisDateTimeString, myDbModel->getDateTimeFormat(myDbModel->MY_SQL_DATETIME_FORMAT));
    // Now we have to change it to the display type
    setDateTimeFormat(myDbModel->getDateTimeFormatCode(thisFormatName), thisControlName);
    return dateTime;
}
/************************************************
 * @brief set Projects.
 * setProjects
 ***********************************************/
void MainWindow::setProjects()
{
    myLanguageModel->mySetting->setMessage("on pushButton Projects Save clicked", "setProjects", MyOrgSettings::MyMessageTypes::Debug);
    //
    QString theRecordID = ui->labelProjectsRecordId->text();
    if (theRecordID.isEmpty())
    {
        theRecordID = 1;
    }
    QString theProjectsName = ui->lineEditProjectsName->text();
    if (theProjectsName.isEmpty())
    {
        theProjectsName = ui->comboBoxProjects->currentText();
    }
    QString theProjectsDateStart = ui->dateTimeEditProjectsDateStart->text();
    QString theProjectsDateDue = ui->dateTimeEditProjectsDateDue->text();
    QString theProjectDescription = ui->textEditProjectDescription->toHtml();
    QString theProjectsProgress = ui->textEditProjectsProgress->toPlainText();
    QString theProgressStatus = ui->comboBoxProgressStatus->currentText();
    QString theProjectsStarted = ui->radioButtonProjectsStarted->isChecked() ? "true" : "false";
    QString theProjectsCompleted = ui->radioButtonProjectsCompleted->isChecked() ? "true" : "false";
    QString theProjectsDateTimeFormatStart = ui->comboBoxProjectsDateTimeFormatStart->currentText();
    QString theProjectsDateTimeFormatDue = ui->comboBoxProjectsDateTimeFormatDue->currentText();
    QString thePassword = ui->lineEditProjectsPassword->text();
    thePassword = myLanguageModel->mySetting->encryptThis(thePassword);
    QString theAssigned = ui->checkBoxProjectsAssigned->isChecked() ? "true" : "false";
    QString theApproved = ui->checkBoxProjectsApproved->isChecked() ? "true" : "false";
    myDbModel->setProject(theRecordID, theProjectsName, theProjectsDateStart, theProjectsDateDue, theProjectDescription, theProjectsProgress, theProgressStatus, theProjectsCompleted, theProjectsStarted, theProjectsDateTimeFormatStart, theProjectsDateTimeFormatDue, thePassword, theApproved, theAssigned);
}
/************************************************
 * @brief set Progress Status.
 * setProgressStatus
 ***********************************************/
void MainWindow::setProgressStatus(const QString &thisStatusName)
{
    myLanguageModel->mySetting->setMessage("set Progress Status", "setProgressStatus", MyOrgSettings::MyMessageTypes::Debug);
    //
    QString theID = getComboBoxProgressStatusID(ui->comboBoxProgressStatus->currentIndex());
    QString theProjectName = ui->lineEditProjectsName->text();
    myDbModel->setProgressStatus(theID, theProjectName, thisStatusName);
}
/************************************************
 * @brief fill Forms.
 * fillForms
 ***********************************************/
void MainWindow::fillForms(const QString &thisProjectID)
{
    myLanguageModel->mySetting->setMessage("fillForms", QString("%1(%2)").arg("fillForms", thisProjectID), MyOrgSettings::MyMessageTypes::Debug);
    #ifdef USE_SQL_FLAG
    QString theProjectID = thisProjectID;
    if (theProjectID.isEmpty())
    {
        theProjectID = getComboBoxProjectsID(0);
        if (theProjectID.isEmpty())
        {
            clearForm("", "");
            return;
        }
    }
    // Declare all variable in function scope
    QSqlQuery query; //!< SQL Query
    QString myConfigurationSelectQuery = myDbModel->getProjectFullSelectQueryID(theProjectID);
    /*
     * id, ProjectName, DateStarted, DateDue, Description, Progress, Completed
    */
    if (query.exec(myConfigurationSelectQuery))
    {
        if (query.first())
        {
            bool lastMain = getMainLoaded();
            setMainLoaded(false); // Set to prevent triggers
            clearForm(query.value("DateStarted").toString(), query.value("DateDue").toString());
            ui->pushButtonProjectsClear->setText(tr("Clear"));
            ui->pushButtonProjectsProgressStatusAdd->setEnabled(true);
            ui->pushButtonProjectsProgressStatusDelete->setEnabled(true);
            ui->pushButtonProjectsProgressStatusModify->setEnabled(true);
            ui->pushButtonProjectsSave->setEnabled(true);
            ui->pushButtonProjectsDelete->setEnabled(true);
            if (!ui->comboBoxProjects->isEnabled())
                { ui->comboBoxProjects->setEnabled(true); }
            if (!ui->comboBoxProgressStatus->isEnabled())
                { ui->comboBoxProgressStatus->setEnabled(true); }
            ui->comboBoxProjects->setCurrentIndex(ui->comboBoxProjects->findText(query.value("ProjectName").toString().trimmed()));
            myLanguageModel->mySetting->setMessage("fillForms", " ProjectName=|" + query.value("ProjectName").toString() + "| DateDue=|" + query.value("DateDue").toString() + "| DateStarted=|" + query.value("DateStarted").toString() + "| Description=|" + query.value("Description").toString() + "| Progress=|" + query.value("Progress").toString() + "| Completed=|" + query.value("Completed").toString() + "|", myLanguageModel->mySetting->Debug);
            // Set Record ID
            // ProjectName DateStarted, DateDue, Description, Progress, Status, Completed, Started, FormatStarted, FormatDue, Password, Approved, Assigned
            // Password
            QString thePassword = query.value("Password").toString().trimmed();
            thePassword = myLanguageModel->mySetting->decryptThis(thePassword);
            ui->lineEditProjectsPassword->setText(thePassword);
            // ID
            myRecordID = query.value("id").toInt();
            //
            ui->labelProjectsRecordId->setText(query.value("id").toString().trimmed());
            ui->lineEditProjectsName->setText(query.value("ProjectName").toString().trimmed());
            validateProjectName(ui->lineEditProjectsName->text());
            // setMarkdown
            ui->textEditProjectDescription->setHtml(query.value("Description").toString().trimmed());
            ui->textEditProjectsProgress->setMarkdown(query.value("Progress").toString().trimmed());
            if (query.value("Assigned").toString() == "true")
                { ui->checkBoxProjectsAssigned->setCheckState(Qt::CheckState::Checked); }
            else
                { ui->checkBoxProjectsAssigned->setCheckState(Qt::CheckState::Unchecked); }
            if (query.value("Approved").toString() == "true")
                { ui->checkBoxProjectsApproved->setCheckState(Qt::CheckState::Checked); }
            else
                { ui->checkBoxProjectsApproved->setCheckState(Qt::CheckState::Unchecked); }
            // DateTime
            ui->dateTimeEditProjectsDateStart->setDateTime(getDataTimeFromString(query.value("DateStarted").toString().trimmed(), "Start", ui->comboBoxProjectsDateTimeFormatStart->currentText()));
            ui->dateTimeEditProjectsDateDue->setDateTime(getDataTimeFromString(query.value("DateDue").toString().trimmed(), "Due", ui->comboBoxProjectsDateTimeFormatDue->currentText()));
            // Format Started
            setDateTimeFormatStartedValue(query.value("FormatStarted").toString().trimmed());
            setDateTimeFormat(myDbModel->getDateTimeFormatCode(query.value("FormatStarted").toString().trimmed()), "Start");
            // Format Due
            setDateTimeFormatDueValue(query.value("FormatDue").toString().trimmed());
            setDateTimeFormat(myDbModel->getDateTimeFormatCode(query.value("FormatDue").toString().trimmed()), "Due");
            // Load ComboBoxes last
            ui->comboBoxProjectsDateTimeFormatStart->setCurrentIndex(ui->comboBoxProjectsDateTimeFormatStart->findText(query.value("FormatStarted").toString().trimmed()));
            ui->comboBoxProjectsDateTimeFormatDue->setCurrentIndex(ui->comboBoxProjectsDateTimeFormatDue->findText(query.value("FormatDue").toString().trimmed()));
            loadProjectProgressStatusComboBox(query.value("ProjectName").toString().trimmed(), query.value("Status").toString().trimmed());
            if (query.value("Completed").toString() == "true")
                { ui->radioButtonProjectsCompleted->setChecked(true); }
            else
                { ui->radioButtonProjectsCompleted->setChecked(false); }
            if (query.value("Started").toString() == "true")
                { ui->radioButtonProjectsStarted->setChecked(true);  }
            else
                { ui->radioButtonProjectsStarted->setChecked(false); }
            //
            setProjects();
            setProgressStatus(query.value("Status").toString());
            //
            setMainLoaded(lastMain); // Set to prevent triggers
        }
    }
    #endif
} // end fillForms
/************************************************
 * @brief on pushButton Projects Progress Status Add clicked.
 * on_pushButtonProjectsProgressStatusAdd_clicked
 ***********************************************/
void MainWindow::on_pushButtonProjectsProgressStatusAdd_clicked()
{
    if (ui->pushButtonProjectsProgressStatusAdd->text() == tr("Add"))
    {
        ui->lineEditProjectsProgressStatus->setText("");
        ui->lineEditProjectsProgressStatus->show();
        ui->pushButtonProjectsProgressStatusModify->hide();
        ui->pushButtonProjectsProgressStatusDelete->hide();
        ui->pushButtonProjectsProgressStatusAdd->setText(tr("Commit"));
    }
    else
    {
        setProgressStatus(ui->lineEditProjectsProgressStatus->text());
        myDbModel->addProgressStatus(ui->lineEditProjectsName->text());
        loadProjectProgressStatusComboBox(ui->lineEditProjectsName->text(), ui->lineEditProjectsProgressStatus->text());
        ui->lineEditProjectsProgressStatus->hide();
        ui->pushButtonProjectsProgressStatusModify->show();
        ui->pushButtonProjectsProgressStatusDelete->show();
        ui->pushButtonProjectsProgressStatusAdd->setText(tr("Add"));
    }
}
/************************************************
 * @brief on pushButton Projects Progress Status Delete clicked.
 * on_pushButtonProjectsProgressStatusDelete_clicked
 ***********************************************/
void MainWindow::on_pushButtonProjectsProgressStatusDelete_clicked()
{
    setProgressStatus(ui->comboBoxProgressStatus->currentText());
    myDbModel->deleteProgressStatus(getComboBoxProgressStatusID(ui->comboBoxProgressStatus->currentIndex()));
    loadProjectProgressStatusComboBox(ui->lineEditProjectsName->text(), "");
}
/************************************************
 * @brief on pushButton Projects Progress Status Modify clicked.
 * on_pushButtonProjectsProgressStatusModify_clicked
 ***********************************************/
void MainWindow::on_pushButtonProjectsProgressStatusModify_clicked()
{
    if (ui->pushButtonProjectsProgressStatusModify->text() == tr("Modify"))
    {
        ui->lineEditProjectsProgressStatus->setText(ui->comboBoxProgressStatus->currentText());
        ui->lineEditProjectsProgressStatus->show();
        ui->pushButtonProjectsProgressStatusAdd->hide();
        ui->pushButtonProjectsProgressStatusDelete->hide();
        ui->pushButtonProjectsProgressStatusModify->setText(tr("Commit"));
    }
    else
    {
        onSaveAll(ui->lineEditProjectsProgressStatus->text());
        ui->lineEditProjectsProgressStatus->hide();
        ui->pushButtonProjectsProgressStatusModify->setText(tr("Modify"));
        ui->pushButtonProjectsProgressStatusAdd->show();
        ui->pushButtonProjectsProgressStatusDelete->show();
    }
}
/************************************************
 * @brief on pushButton Projects Show Password clicked.
 * on_pushButtonProjectsShowPassword_clicked
 ***********************************************/
void MainWindow::on_pushButtonProjectsShowPassword_clicked()
{
    myLanguageModel->mySetting->setMessage("on_pushButtonProjectsShowPassword_clicked", "on_pushButtonProjectsShowPassword_clicked", MyOrgSettings::MyMessageTypes::Debug);
    if (ui->pushButtonProjectsShowPassword->text() == "Show")
    {
        ui->pushButtonProjectsShowPassword->setText(tr("Hide"));
        ui->lineEditProjectsPassword->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->pushButtonProjectsShowPassword->setText(tr("Show"));
        ui->lineEditProjectsPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    }
}
/************************************************
 * @brief validateProjectName.
 * validateProjectName
 ***********************************************/
void MainWindow::validateProjectName(const QString &thisText)
{
    if (thisText.isEmpty())
    {
        ui->labelProjectsNameValidator->show();
        ui->labelProjectsNameValidator->setText(tr("Input Project Name"));
        ui->labelProjectsNameValidator->setStyleSheet("QLabel { color : red; }");
    }
    else
    {
        ui->labelProjectsNameValidator->hide();
    }
}
/************************************************
 * @brief on lineEdit ProjectsName text Changed.
 * on_lineEditProjectsName_textChanged
 ***********************************************/
void MainWindow::on_lineEditProjectsName_textChanged(const QString &thisText)
{
    if (!getMainLoaded()) { return; }
    validateProjectName(thisText);
}
/************************************************
 * @brief on tabWidget current Changed.
 * on_tabWidget_currentChanged
 ***********************************************/
void MainWindow::on_tabWidget_currentChanged(int index)
{
    switch (index)
    {
    case TabSettings:
        break;
    case TabSql:
        break;
    case TabProjects:
        break;
    case TabTabHelp:
        if (ui->textEditHelp->toMarkdown().isEmpty())
        {
            onHelp();
        }
        break;
    case TabAll:
        break;
    }
}
/******************************************************************************
* onTextBold                                                                 *
*******************************************************************************/
void MainWindow::onTextBold()
{
    if (isDebugMessage) qDebug() << "onTextBold";
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->actionBold->isChecked() ? QFont::Bold : QFont::Normal);
    mergeFormatOnWordOrSelection(fmt);
} // end onTextBold
/******************************************************************************
* onTextUnderline                                                            *
*******************************************************************************/
void MainWindow::onTextUnderline()
{
    if (isDebugMessage) qDebug() << "onTextUnderline";
    QTextCharFormat fmt;
    fmt.setFontUnderline(ui->actionUnderline->isChecked());
    mergeFormatOnWordOrSelection(fmt);
} // end onTextUnderline
/******************************************************************************
* onTextItalic                                                               *
*******************************************************************************/
void MainWindow::onTextItalic()
{
    if (isDebugMessage) qDebug() << "onTextItalic";
    QTextCharFormat fmt;
    fmt.setFontItalic(ui->actionItalic->isChecked());
    mergeFormatOnWordOrSelection(fmt);
} // end onTextItalic
/******************************************************************************
* mergeFormatOnWordOrSelection                                               *
*******************************************************************************/
void MainWindow::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
    if (isDebugMessage) qDebug() << "mergeFormatOnWordOrSelection";
    QTextCursor cursor = ui->textEditProjectDescription->textCursor();
    if (!cursor.hasSelection()) cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    ui->textEditProjectDescription->mergeCurrentCharFormat(format);
} // end mergeFormatOnWordOrSelection
/******************************************************************************
* fontChanged                                                                *
*******************************************************************************/
void MainWindow::fontChanged(const QFont &f)
{
    if (isDebugMessage) qDebug() << "fontChanged=" << f;
    //comboFont->setCurrentIndex(comboFont->findText(QFontInfo(f).family()));
    //comboSize->setCurrentIndex(comboSize->findText(QString::number(f.pointSize())));
    ui->actionBold->setChecked(f.bold());
    ui->actionItalic->setChecked(f.italic());
    ui->actionUnderline->setChecked(f.underline());
} // end fontChanged
/******************************************************************************
* currentCharFormatChanged                                                   *
*******************************************************************************/
void MainWindow::onCurrentCharFormatChanged(const QTextCharFormat &format)
{
    if (isDebugMessage) qDebug() << "currentCharFormatChanged=" << format;
    fontChanged(format.font());
    //colorChanged(format.foreground().color());
} // end onCurrentCharFormatChanged
/******************************************************************************
* onCursorPositionChanged                                                    *
*******************************************************************************/
void MainWindow::onCursorPositionChanged()
{
    if (isDebugMessage) qDebug() << "onCursorPositionChanged";
//    alignmentChanged(ui->textEditProjectDescription->alignment());
//    QTextList *list = ui->textEditProjectDescription->textCursor().currentList();
//    if (list)
//    {
//        switch (list->format().style())
//        {
//        case QTextListFormat::ListDisc:
//            comboStyle->setCurrentIndex(1);
//            break;
//        case QTextListFormat::ListCircle:
//            comboStyle->setCurrentIndex(2);
//            break;
//        case QTextListFormat::ListSquare:
//            comboStyle->setCurrentIndex(3);
//            break;
//        case QTextListFormat::ListDecimal:
//            comboStyle->setCurrentIndex(6);
//            break;
//        case QTextListFormat::ListLowerAlpha:
//            comboStyle->setCurrentIndex(7);
//            break;
//        case QTextListFormat::ListUpperAlpha:
//            comboStyle->setCurrentIndex(8);
//            break;
//        case QTextListFormat::ListLowerRoman:
//            comboStyle->setCurrentIndex(9);
//            break;
//        case QTextListFormat::ListUpperRoman:
//            comboStyle->setCurrentIndex(10);
//            break;
//        default:
//            comboStyle->setCurrentIndex(-1);
//            break;
//        }
//        switch (ui->textEdit->textCursor().block().blockFormat().marker())
//        {
//        case QTextBlockFormat::MarkerType::NoMarker:
//            ui->actionToggleCheckState->setChecked(false);
//            break;
//        case QTextBlockFormat::MarkerType::Unchecked:
//            comboStyle->setCurrentIndex(4);
//            ui->actionToggleCheckState->setChecked(false);
//            break;
//        case QTextBlockFormat::MarkerType::Checked:
//            comboStyle->setCurrentIndex(5);
//            ui->actionToggleCheckState->setChecked(true);
//            break;
//        }
//    }
//    else
//    {
//        int headingLevel = ui->textEdit->textCursor().blockFormat().headingLevel();
//        comboStyle->setCurrentIndex(headingLevel ? headingLevel + 10 : 0);
//    }
} // end onCursorPositionChanged
/******************************* End of File *********************************/


