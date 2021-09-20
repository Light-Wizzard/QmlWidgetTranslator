/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *actionAuthor;
    QAction *actionSave;
    QAction *actionBold;
    QAction *actionItalic;
    QAction *actionUnderline;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabSettings;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayoutSettings;
    QLabel *labelSettingsLanguage;
    QHBoxLayout *horizontalLayoutSettingsLanguage;
    QComboBox *comboBoxLanguage;
    QSpacerItem *horizontalSpacerSettingsLanguage;
    QLabel *labelSettingsUiLanguage;
    QHBoxLayout *horizontalLayoutSettingsUI;
    QLabel *labelSettingsLanguageUI;
    QLabel *labelSettignsMessaging;
    QHBoxLayout *horizontalLayoutSettignsMessaging;
    QCheckBox *checkBoxSettignsMessaging;
    QSpacerItem *horizontalSpacerSettignsMessaging;
    QWidget *tabSQL;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayoutSql;
    QLabel *labelSqlSqlType;
    QLabel *labelSqlHostName;
    QLineEdit *lineEditSqlHostName;
    QLabel *labelSqlUserName;
    QLineEdit *lineEditSqlUserName;
    QLabel *labelSqlPassword;
    QHBoxLayout *horizontalLayoutSqlPassword;
    QLineEdit *lineEditSqlPassword;
    QPushButton *pushButtonSqlPasswordShow;
    QLabel *labelSqlOptions;
    QHBoxLayout *horizontalLayoutSqlOptions;
    QPushButton *pushButtonSqlSave;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayoutSqlDatabaseName;
    QLineEdit *lineEditSqlDatabaseName;
    QPushButton *pushButtonSqlDatabaseNameBrowse;
    QLabel *labelSqlDatabaseName;
    QHBoxLayout *horizontalLayoutSqlType;
    QComboBox *comboBoxSqlDatabaseType;
    QSpacerItem *horizontalSpacerSqlType;
    QWidget *tabProjects;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout;
    QLabel *labelProjectsComboBox;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxProjects;
    QLineEdit *lineEditProjectsName;
    QLabel *labelProjectsNameValidator;
    QSpacerItem *horizontalSpacerProjectsComboBox;
    QLabel *labelProjectsRecordNumber;
    QLabel *labelProjectsRecordId;
    QLabel *labelProjectsDate;
    QLabel *labelProjectsDateDue;
    QLabel *labelProjectDescription;
    QTextEdit *textEditProjectDescription;
    QLabel *labelProjectProgress;
    QLabel *labelProjectProgressStatus;
    QTextEdit *textEditProjectsProgress;
    QHBoxLayout *horizontalLayoutProgressStatus;
    QComboBox *comboBoxProgressStatus;
    QSpacerItem *horizontalSpacerProgressStatus;
    QLineEdit *lineEditProjectsProgressStatus;
    QPushButton *pushButtonProjectsProgressStatusAdd;
    QPushButton *pushButtonProjectsProgressStatusModify;
    QPushButton *pushButtonProjectsProgressStatusDelete;
    QLabel *labelProjectsStatus;
    QHBoxLayout *horizontalLayoutProjectsCompleted;
    QCheckBox *checkBoxProjectsApproved;
    QCheckBox *checkBoxProjectsAssigned;
    QGroupBox *groupBoxProgress;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonProjectsStarted;
    QRadioButton *radioButtonProjectsCompleted;
    QSpacerItem *horizontalSpacerProjectsCompleted;
    QLabel *labelProjectsOptions;
    QHBoxLayout *horizontalLayoutProjectsOptions;
    QPushButton *pushButtonProjectsSave;
    QPushButton *pushButtonProjectsAdd;
    QPushButton *pushButtonProjectsClear;
    QPushButton *pushButtonProjectsDelete;
    QHBoxLayout *horizontalLayoutProjectsDateStart;
    QDateTimeEdit *dateTimeEditProjectsDateStart;
    QComboBox *comboBoxProjectsDateTimeFormatStart;
    QSpacerItem *horizontalSpacerProjectsDateStart;
    QPushButton *pushButtonProjectsDateStart;
    QHBoxLayout *horizontalLayoutProjectsDateDue;
    QDateTimeEdit *dateTimeEditProjectsDateDue;
    QComboBox *comboBoxProjectsDateTimeFormatDue;
    QSpacerItem *horizontalSpacerProjectsDateDue;
    QPushButton *pushButtonProjectsDateDue;
    QLabel *labelProjectsPassword;
    QHBoxLayout *horizontalLayoutProjectsPassword;
    QLineEdit *lineEditProjectsPassword;
    QSpacerItem *horizontalSpacerProjectsPassword;
    QPushButton *pushButtonProjectsShowPassword;
    QWidget *tabHelp;
    QVBoxLayout *verticalLayout_6;
    QTextEdit *textEditHelp;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuFormat;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(819, 628);
        QFont font;
        font.setPointSize(13);
        MainWindow->setFont(font);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/exit_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon1);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon2);
        actionAuthor = new QAction(MainWindow);
        actionAuthor->setObjectName(QString::fromUtf8("actionAuthor"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/handshake.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAuthor->setIcon(icon3);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName(QString::fromUtf8("actionBold"));
        actionBold->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/textbold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon5);
        actionItalic = new QAction(MainWindow);
        actionItalic->setObjectName(QString::fromUtf8("actionItalic"));
        actionItalic->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/textitalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionItalic->setIcon(icon6);
        actionUnderline = new QAction(MainWindow);
        actionUnderline->setObjectName(QString::fromUtf8("actionUnderline"));
        actionUnderline->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/textunder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnderline->setIcon(icon7);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabSettings = new QWidget();
        tabSettings->setObjectName(QString::fromUtf8("tabSettings"));
        verticalLayout_3 = new QVBoxLayout(tabSettings);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayoutSettings = new QFormLayout();
        formLayoutSettings->setObjectName(QString::fromUtf8("formLayoutSettings"));
        labelSettingsLanguage = new QLabel(tabSettings);
        labelSettingsLanguage->setObjectName(QString::fromUtf8("labelSettingsLanguage"));

        formLayoutSettings->setWidget(0, QFormLayout::LabelRole, labelSettingsLanguage);

        horizontalLayoutSettingsLanguage = new QHBoxLayout();
        horizontalLayoutSettingsLanguage->setObjectName(QString::fromUtf8("horizontalLayoutSettingsLanguage"));
        comboBoxLanguage = new QComboBox(tabSettings);
        comboBoxLanguage->setObjectName(QString::fromUtf8("comboBoxLanguage"));
        comboBoxLanguage->setCurrentText(QString::fromUtf8(""));

        horizontalLayoutSettingsLanguage->addWidget(comboBoxLanguage);

        horizontalSpacerSettingsLanguage = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSettingsLanguage->addItem(horizontalSpacerSettingsLanguage);


        formLayoutSettings->setLayout(0, QFormLayout::FieldRole, horizontalLayoutSettingsLanguage);

        labelSettingsUiLanguage = new QLabel(tabSettings);
        labelSettingsUiLanguage->setObjectName(QString::fromUtf8("labelSettingsUiLanguage"));

        formLayoutSettings->setWidget(1, QFormLayout::LabelRole, labelSettingsUiLanguage);

        horizontalLayoutSettingsUI = new QHBoxLayout();
        horizontalLayoutSettingsUI->setObjectName(QString::fromUtf8("horizontalLayoutSettingsUI"));
        labelSettingsLanguageUI = new QLabel(tabSettings);
        labelSettingsLanguageUI->setObjectName(QString::fromUtf8("labelSettingsLanguageUI"));
        labelSettingsLanguageUI->setText(QString::fromUtf8("English"));

        horizontalLayoutSettingsUI->addWidget(labelSettingsLanguageUI);


        formLayoutSettings->setLayout(1, QFormLayout::FieldRole, horizontalLayoutSettingsUI);

        labelSettignsMessaging = new QLabel(tabSettings);
        labelSettignsMessaging->setObjectName(QString::fromUtf8("labelSettignsMessaging"));

        formLayoutSettings->setWidget(2, QFormLayout::LabelRole, labelSettignsMessaging);

        horizontalLayoutSettignsMessaging = new QHBoxLayout();
        horizontalLayoutSettignsMessaging->setObjectName(QString::fromUtf8("horizontalLayoutSettignsMessaging"));
        checkBoxSettignsMessaging = new QCheckBox(tabSettings);
        checkBoxSettignsMessaging->setObjectName(QString::fromUtf8("checkBoxSettignsMessaging"));

        horizontalLayoutSettignsMessaging->addWidget(checkBoxSettignsMessaging);

        horizontalSpacerSettignsMessaging = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSettignsMessaging->addItem(horizontalSpacerSettignsMessaging);


        formLayoutSettings->setLayout(2, QFormLayout::FieldRole, horizontalLayoutSettignsMessaging);


        verticalLayout_3->addLayout(formLayoutSettings);

        tabWidget->addTab(tabSettings, QString());
        tabSQL = new QWidget();
        tabSQL->setObjectName(QString::fromUtf8("tabSQL"));
        verticalLayout_2 = new QVBoxLayout(tabSQL);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayoutSql = new QFormLayout();
        formLayoutSql->setObjectName(QString::fromUtf8("formLayoutSql"));
        labelSqlSqlType = new QLabel(tabSQL);
        labelSqlSqlType->setObjectName(QString::fromUtf8("labelSqlSqlType"));

        formLayoutSql->setWidget(1, QFormLayout::LabelRole, labelSqlSqlType);

        labelSqlHostName = new QLabel(tabSQL);
        labelSqlHostName->setObjectName(QString::fromUtf8("labelSqlHostName"));

        formLayoutSql->setWidget(2, QFormLayout::LabelRole, labelSqlHostName);

        lineEditSqlHostName = new QLineEdit(tabSQL);
        lineEditSqlHostName->setObjectName(QString::fromUtf8("lineEditSqlHostName"));
        lineEditSqlHostName->setInputMask(QString::fromUtf8(""));
        lineEditSqlHostName->setText(QString::fromUtf8(""));
        lineEditSqlHostName->setPlaceholderText(QString::fromUtf8(""));

        formLayoutSql->setWidget(2, QFormLayout::FieldRole, lineEditSqlHostName);

        labelSqlUserName = new QLabel(tabSQL);
        labelSqlUserName->setObjectName(QString::fromUtf8("labelSqlUserName"));

        formLayoutSql->setWidget(3, QFormLayout::LabelRole, labelSqlUserName);

        lineEditSqlUserName = new QLineEdit(tabSQL);
        lineEditSqlUserName->setObjectName(QString::fromUtf8("lineEditSqlUserName"));
        lineEditSqlUserName->setInputMask(QString::fromUtf8(""));
        lineEditSqlUserName->setText(QString::fromUtf8(""));
        lineEditSqlUserName->setPlaceholderText(QString::fromUtf8(""));

        formLayoutSql->setWidget(3, QFormLayout::FieldRole, lineEditSqlUserName);

        labelSqlPassword = new QLabel(tabSQL);
        labelSqlPassword->setObjectName(QString::fromUtf8("labelSqlPassword"));

        formLayoutSql->setWidget(4, QFormLayout::LabelRole, labelSqlPassword);

        horizontalLayoutSqlPassword = new QHBoxLayout();
        horizontalLayoutSqlPassword->setObjectName(QString::fromUtf8("horizontalLayoutSqlPassword"));
        lineEditSqlPassword = new QLineEdit(tabSQL);
        lineEditSqlPassword->setObjectName(QString::fromUtf8("lineEditSqlPassword"));
        lineEditSqlPassword->setInputMask(QString::fromUtf8(""));
        lineEditSqlPassword->setText(QString::fromUtf8(""));
        lineEditSqlPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        lineEditSqlPassword->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayoutSqlPassword->addWidget(lineEditSqlPassword);

        pushButtonSqlPasswordShow = new QPushButton(tabSQL);
        pushButtonSqlPasswordShow->setObjectName(QString::fromUtf8("pushButtonSqlPasswordShow"));

        horizontalLayoutSqlPassword->addWidget(pushButtonSqlPasswordShow);


        formLayoutSql->setLayout(4, QFormLayout::FieldRole, horizontalLayoutSqlPassword);

        labelSqlOptions = new QLabel(tabSQL);
        labelSqlOptions->setObjectName(QString::fromUtf8("labelSqlOptions"));

        formLayoutSql->setWidget(5, QFormLayout::LabelRole, labelSqlOptions);

        horizontalLayoutSqlOptions = new QHBoxLayout();
        horizontalLayoutSqlOptions->setObjectName(QString::fromUtf8("horizontalLayoutSqlOptions"));
        pushButtonSqlSave = new QPushButton(tabSQL);
        pushButtonSqlSave->setObjectName(QString::fromUtf8("pushButtonSqlSave"));

        horizontalLayoutSqlOptions->addWidget(pushButtonSqlSave);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSqlOptions->addItem(horizontalSpacer);


        formLayoutSql->setLayout(5, QFormLayout::FieldRole, horizontalLayoutSqlOptions);

        horizontalLayoutSqlDatabaseName = new QHBoxLayout();
        horizontalLayoutSqlDatabaseName->setObjectName(QString::fromUtf8("horizontalLayoutSqlDatabaseName"));
        lineEditSqlDatabaseName = new QLineEdit(tabSQL);
        lineEditSqlDatabaseName->setObjectName(QString::fromUtf8("lineEditSqlDatabaseName"));
        lineEditSqlDatabaseName->setInputMask(QString::fromUtf8(""));
        lineEditSqlDatabaseName->setText(QString::fromUtf8(""));
        lineEditSqlDatabaseName->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayoutSqlDatabaseName->addWidget(lineEditSqlDatabaseName);

        pushButtonSqlDatabaseNameBrowse = new QPushButton(tabSQL);
        pushButtonSqlDatabaseNameBrowse->setObjectName(QString::fromUtf8("pushButtonSqlDatabaseNameBrowse"));

        horizontalLayoutSqlDatabaseName->addWidget(pushButtonSqlDatabaseNameBrowse);


        formLayoutSql->setLayout(0, QFormLayout::FieldRole, horizontalLayoutSqlDatabaseName);

        labelSqlDatabaseName = new QLabel(tabSQL);
        labelSqlDatabaseName->setObjectName(QString::fromUtf8("labelSqlDatabaseName"));

        formLayoutSql->setWidget(0, QFormLayout::LabelRole, labelSqlDatabaseName);

        horizontalLayoutSqlType = new QHBoxLayout();
        horizontalLayoutSqlType->setObjectName(QString::fromUtf8("horizontalLayoutSqlType"));
        comboBoxSqlDatabaseType = new QComboBox(tabSQL);
        comboBoxSqlDatabaseType->setObjectName(QString::fromUtf8("comboBoxSqlDatabaseType"));
        comboBoxSqlDatabaseType->setCurrentText(QString::fromUtf8(""));

        horizontalLayoutSqlType->addWidget(comboBoxSqlDatabaseType);

        horizontalSpacerSqlType = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutSqlType->addItem(horizontalSpacerSqlType);


        formLayoutSql->setLayout(1, QFormLayout::FieldRole, horizontalLayoutSqlType);


        verticalLayout_2->addLayout(formLayoutSql);

        tabWidget->addTab(tabSQL, QString());
        tabProjects = new QWidget();
        tabProjects->setObjectName(QString::fromUtf8("tabProjects"));
        verticalLayout_4 = new QVBoxLayout(tabProjects);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelProjectsComboBox = new QLabel(tabProjects);
        labelProjectsComboBox->setObjectName(QString::fromUtf8("labelProjectsComboBox"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelProjectsComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBoxProjects = new QComboBox(tabProjects);
        comboBoxProjects->setObjectName(QString::fromUtf8("comboBoxProjects"));
        comboBoxProjects->setCurrentText(QString::fromUtf8(""));

        horizontalLayout->addWidget(comboBoxProjects);

        lineEditProjectsName = new QLineEdit(tabProjects);
        lineEditProjectsName->setObjectName(QString::fromUtf8("lineEditProjectsName"));
        lineEditProjectsName->setInputMask(QString::fromUtf8(""));

        horizontalLayout->addWidget(lineEditProjectsName);

        labelProjectsNameValidator = new QLabel(tabProjects);
        labelProjectsNameValidator->setObjectName(QString::fromUtf8("labelProjectsNameValidator"));
        labelProjectsNameValidator->setText(QString::fromUtf8("Validator"));

        horizontalLayout->addWidget(labelProjectsNameValidator);

        horizontalSpacerProjectsComboBox = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacerProjectsComboBox);

        labelProjectsRecordNumber = new QLabel(tabProjects);
        labelProjectsRecordNumber->setObjectName(QString::fromUtf8("labelProjectsRecordNumber"));

        horizontalLayout->addWidget(labelProjectsRecordNumber);

        labelProjectsRecordId = new QLabel(tabProjects);
        labelProjectsRecordId->setObjectName(QString::fromUtf8("labelProjectsRecordId"));
        labelProjectsRecordId->setText(QString::fromUtf8("0"));

        horizontalLayout->addWidget(labelProjectsRecordId);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        labelProjectsDate = new QLabel(tabProjects);
        labelProjectsDate->setObjectName(QString::fromUtf8("labelProjectsDate"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelProjectsDate);

        labelProjectsDateDue = new QLabel(tabProjects);
        labelProjectsDateDue->setObjectName(QString::fromUtf8("labelProjectsDateDue"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelProjectsDateDue);

        labelProjectDescription = new QLabel(tabProjects);
        labelProjectDescription->setObjectName(QString::fromUtf8("labelProjectDescription"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelProjectDescription);

        textEditProjectDescription = new QTextEdit(tabProjects);
        textEditProjectDescription->setObjectName(QString::fromUtf8("textEditProjectDescription"));
        textEditProjectDescription->setAutoFormatting(QTextEdit::AutoAll);
        textEditProjectDescription->setMarkdown(QString::fromUtf8(""));
        textEditProjectDescription->setPlaceholderText(QString::fromUtf8(""));

        formLayout->setWidget(3, QFormLayout::FieldRole, textEditProjectDescription);

        labelProjectProgress = new QLabel(tabProjects);
        labelProjectProgress->setObjectName(QString::fromUtf8("labelProjectProgress"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelProjectProgress);

        labelProjectProgressStatus = new QLabel(tabProjects);
        labelProjectProgressStatus->setObjectName(QString::fromUtf8("labelProjectProgressStatus"));

        formLayout->setWidget(6, QFormLayout::LabelRole, labelProjectProgressStatus);

        textEditProjectsProgress = new QTextEdit(tabProjects);
        textEditProjectsProgress->setObjectName(QString::fromUtf8("textEditProjectsProgress"));

        formLayout->setWidget(4, QFormLayout::FieldRole, textEditProjectsProgress);

        horizontalLayoutProgressStatus = new QHBoxLayout();
        horizontalLayoutProgressStatus->setObjectName(QString::fromUtf8("horizontalLayoutProgressStatus"));
        comboBoxProgressStatus = new QComboBox(tabProjects);
        comboBoxProgressStatus->setObjectName(QString::fromUtf8("comboBoxProgressStatus"));
        comboBoxProgressStatus->setCurrentText(QString::fromUtf8(""));

        horizontalLayoutProgressStatus->addWidget(comboBoxProgressStatus);

        horizontalSpacerProgressStatus = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutProgressStatus->addItem(horizontalSpacerProgressStatus);

        lineEditProjectsProgressStatus = new QLineEdit(tabProjects);
        lineEditProjectsProgressStatus->setObjectName(QString::fromUtf8("lineEditProjectsProgressStatus"));
        lineEditProjectsProgressStatus->setInputMask(QString::fromUtf8(""));
        lineEditProjectsProgressStatus->setText(QString::fromUtf8(""));
        lineEditProjectsProgressStatus->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayoutProgressStatus->addWidget(lineEditProjectsProgressStatus);

        pushButtonProjectsProgressStatusAdd = new QPushButton(tabProjects);
        pushButtonProjectsProgressStatusAdd->setObjectName(QString::fromUtf8("pushButtonProjectsProgressStatusAdd"));

        horizontalLayoutProgressStatus->addWidget(pushButtonProjectsProgressStatusAdd);

        pushButtonProjectsProgressStatusModify = new QPushButton(tabProjects);
        pushButtonProjectsProgressStatusModify->setObjectName(QString::fromUtf8("pushButtonProjectsProgressStatusModify"));

        horizontalLayoutProgressStatus->addWidget(pushButtonProjectsProgressStatusModify);

        pushButtonProjectsProgressStatusDelete = new QPushButton(tabProjects);
        pushButtonProjectsProgressStatusDelete->setObjectName(QString::fromUtf8("pushButtonProjectsProgressStatusDelete"));

        horizontalLayoutProgressStatus->addWidget(pushButtonProjectsProgressStatusDelete);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayoutProgressStatus);

        labelProjectsStatus = new QLabel(tabProjects);
        labelProjectsStatus->setObjectName(QString::fromUtf8("labelProjectsStatus"));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelProjectsStatus);

        horizontalLayoutProjectsCompleted = new QHBoxLayout();
        horizontalLayoutProjectsCompleted->setObjectName(QString::fromUtf8("horizontalLayoutProjectsCompleted"));
        checkBoxProjectsApproved = new QCheckBox(tabProjects);
        checkBoxProjectsApproved->setObjectName(QString::fromUtf8("checkBoxProjectsApproved"));

        horizontalLayoutProjectsCompleted->addWidget(checkBoxProjectsApproved);

        checkBoxProjectsAssigned = new QCheckBox(tabProjects);
        checkBoxProjectsAssigned->setObjectName(QString::fromUtf8("checkBoxProjectsAssigned"));

        horizontalLayoutProjectsCompleted->addWidget(checkBoxProjectsAssigned);

        groupBoxProgress = new QGroupBox(tabProjects);
        groupBoxProgress->setObjectName(QString::fromUtf8("groupBoxProgress"));
        horizontalLayout_2 = new QHBoxLayout(groupBoxProgress);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButtonProjectsStarted = new QRadioButton(groupBoxProgress);
        radioButtonProjectsStarted->setObjectName(QString::fromUtf8("radioButtonProjectsStarted"));

        horizontalLayout_2->addWidget(radioButtonProjectsStarted);

        radioButtonProjectsCompleted = new QRadioButton(groupBoxProgress);
        radioButtonProjectsCompleted->setObjectName(QString::fromUtf8("radioButtonProjectsCompleted"));

        horizontalLayout_2->addWidget(radioButtonProjectsCompleted);


        horizontalLayoutProjectsCompleted->addWidget(groupBoxProgress);

        horizontalSpacerProjectsCompleted = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutProjectsCompleted->addItem(horizontalSpacerProjectsCompleted);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayoutProjectsCompleted);

        labelProjectsOptions = new QLabel(tabProjects);
        labelProjectsOptions->setObjectName(QString::fromUtf8("labelProjectsOptions"));

        formLayout->setWidget(8, QFormLayout::LabelRole, labelProjectsOptions);

        horizontalLayoutProjectsOptions = new QHBoxLayout();
        horizontalLayoutProjectsOptions->setObjectName(QString::fromUtf8("horizontalLayoutProjectsOptions"));
        pushButtonProjectsSave = new QPushButton(tabProjects);
        pushButtonProjectsSave->setObjectName(QString::fromUtf8("pushButtonProjectsSave"));

        horizontalLayoutProjectsOptions->addWidget(pushButtonProjectsSave);

        pushButtonProjectsAdd = new QPushButton(tabProjects);
        pushButtonProjectsAdd->setObjectName(QString::fromUtf8("pushButtonProjectsAdd"));

        horizontalLayoutProjectsOptions->addWidget(pushButtonProjectsAdd);

        pushButtonProjectsClear = new QPushButton(tabProjects);
        pushButtonProjectsClear->setObjectName(QString::fromUtf8("pushButtonProjectsClear"));

        horizontalLayoutProjectsOptions->addWidget(pushButtonProjectsClear);

        pushButtonProjectsDelete = new QPushButton(tabProjects);
        pushButtonProjectsDelete->setObjectName(QString::fromUtf8("pushButtonProjectsDelete"));

        horizontalLayoutProjectsOptions->addWidget(pushButtonProjectsDelete);


        formLayout->setLayout(8, QFormLayout::FieldRole, horizontalLayoutProjectsOptions);

        horizontalLayoutProjectsDateStart = new QHBoxLayout();
        horizontalLayoutProjectsDateStart->setObjectName(QString::fromUtf8("horizontalLayoutProjectsDateStart"));
        dateTimeEditProjectsDateStart = new QDateTimeEdit(tabProjects);
        dateTimeEditProjectsDateStart->setObjectName(QString::fromUtf8("dateTimeEditProjectsDateStart"));
        dateTimeEditProjectsDateStart->setMinimumSize(QSize(200, 0));

        horizontalLayoutProjectsDateStart->addWidget(dateTimeEditProjectsDateStart);

        comboBoxProjectsDateTimeFormatStart = new QComboBox(tabProjects);
        comboBoxProjectsDateTimeFormatStart->setObjectName(QString::fromUtf8("comboBoxProjectsDateTimeFormatStart"));
        comboBoxProjectsDateTimeFormatStart->setCurrentText(QString::fromUtf8(""));

        horizontalLayoutProjectsDateStart->addWidget(comboBoxProjectsDateTimeFormatStart);

        horizontalSpacerProjectsDateStart = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutProjectsDateStart->addItem(horizontalSpacerProjectsDateStart);

        pushButtonProjectsDateStart = new QPushButton(tabProjects);
        pushButtonProjectsDateStart->setObjectName(QString::fromUtf8("pushButtonProjectsDateStart"));

        horizontalLayoutProjectsDateStart->addWidget(pushButtonProjectsDateStart);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayoutProjectsDateStart);

        horizontalLayoutProjectsDateDue = new QHBoxLayout();
        horizontalLayoutProjectsDateDue->setObjectName(QString::fromUtf8("horizontalLayoutProjectsDateDue"));
        dateTimeEditProjectsDateDue = new QDateTimeEdit(tabProjects);
        dateTimeEditProjectsDateDue->setObjectName(QString::fromUtf8("dateTimeEditProjectsDateDue"));
        dateTimeEditProjectsDateDue->setMinimumSize(QSize(200, 0));
        dateTimeEditProjectsDateDue->setBaseSize(QSize(0, 0));

        horizontalLayoutProjectsDateDue->addWidget(dateTimeEditProjectsDateDue);

        comboBoxProjectsDateTimeFormatDue = new QComboBox(tabProjects);
        comboBoxProjectsDateTimeFormatDue->setObjectName(QString::fromUtf8("comboBoxProjectsDateTimeFormatDue"));
        comboBoxProjectsDateTimeFormatDue->setCurrentText(QString::fromUtf8(""));

        horizontalLayoutProjectsDateDue->addWidget(comboBoxProjectsDateTimeFormatDue);

        horizontalSpacerProjectsDateDue = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutProjectsDateDue->addItem(horizontalSpacerProjectsDateDue);

        pushButtonProjectsDateDue = new QPushButton(tabProjects);
        pushButtonProjectsDateDue->setObjectName(QString::fromUtf8("pushButtonProjectsDateDue"));

        horizontalLayoutProjectsDateDue->addWidget(pushButtonProjectsDateDue);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayoutProjectsDateDue);

        labelProjectsPassword = new QLabel(tabProjects);
        labelProjectsPassword->setObjectName(QString::fromUtf8("labelProjectsPassword"));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelProjectsPassword);

        horizontalLayoutProjectsPassword = new QHBoxLayout();
        horizontalLayoutProjectsPassword->setObjectName(QString::fromUtf8("horizontalLayoutProjectsPassword"));
        lineEditProjectsPassword = new QLineEdit(tabProjects);
        lineEditProjectsPassword->setObjectName(QString::fromUtf8("lineEditProjectsPassword"));
        lineEditProjectsPassword->setMinimumSize(QSize(333, 0));
        lineEditProjectsPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayoutProjectsPassword->addWidget(lineEditProjectsPassword);

        horizontalSpacerProjectsPassword = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutProjectsPassword->addItem(horizontalSpacerProjectsPassword);

        pushButtonProjectsShowPassword = new QPushButton(tabProjects);
        pushButtonProjectsShowPassword->setObjectName(QString::fromUtf8("pushButtonProjectsShowPassword"));

        horizontalLayoutProjectsPassword->addWidget(pushButtonProjectsShowPassword);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayoutProjectsPassword);


        verticalLayout_4->addLayout(formLayout);

        tabWidget->addTab(tabProjects, QString());
        tabHelp = new QWidget();
        tabHelp->setObjectName(QString::fromUtf8("tabHelp"));
        verticalLayout_6 = new QVBoxLayout(tabHelp);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        textEditHelp = new QTextEdit(tabHelp);
        textEditHelp->setObjectName(QString::fromUtf8("textEditHelp"));

        verticalLayout_6->addWidget(textEditHelp);

        tabWidget->addTab(tabHelp, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 819, 29));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuFormat = new QMenu(menubar);
        menuFormat->setObjectName(QString::fromUtf8("menuFormat"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuFormat->menuAction());
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAuthor);
        menuHelp->addSeparator();
        menuHelp->addAction(actionHelp);
        menuFormat->addAction(actionBold);
        menuFormat->addAction(actionItalic);
        menuFormat->addAction(actionUnderline);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionBold);
        toolBar->addAction(actionItalic);
        toolBar->addAction(actionUnderline);
        toolBar->addSeparator();
        toolBar->addAction(actionAbout);
        toolBar->addAction(actionAuthor);
        toolBar->addAction(actionHelp);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionAuthor->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionBold->setText(QCoreApplication::translate("MainWindow", "Bold", nullptr));
        actionItalic->setText(QCoreApplication::translate("MainWindow", "Italic", nullptr));
        actionUnderline->setText(QCoreApplication::translate("MainWindow", "Underline", nullptr));
        labelSettingsLanguage->setText(QCoreApplication::translate("MainWindow", "Change Language", nullptr));
#if QT_CONFIG(accessibility)
        comboBoxLanguage->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        comboBoxLanguage->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        labelSettingsUiLanguage->setText(QCoreApplication::translate("MainWindow", "UI Language", nullptr));
        labelSettignsMessaging->setText(QCoreApplication::translate("MainWindow", "Logging", nullptr));
        checkBoxSettignsMessaging->setText(QCoreApplication::translate("MainWindow", "Debug Messages", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSettings), QCoreApplication::translate("MainWindow", "Settings", nullptr));
        labelSqlSqlType->setText(QCoreApplication::translate("MainWindow", "SQL Type", nullptr));
        labelSqlHostName->setText(QCoreApplication::translate("MainWindow", "Host Name", nullptr));
        labelSqlUserName->setText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        labelSqlPassword->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButtonSqlPasswordShow->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        labelSqlOptions->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        pushButtonSqlSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButtonSqlDatabaseNameBrowse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        labelSqlDatabaseName->setText(QCoreApplication::translate("MainWindow", "Database Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSQL), QCoreApplication::translate("MainWindow", "SQL", nullptr));
        labelProjectsComboBox->setText(QCoreApplication::translate("MainWindow", "Projects", nullptr));
        labelProjectsRecordNumber->setText(QCoreApplication::translate("MainWindow", "Record", nullptr));
        labelProjectsDate->setText(QCoreApplication::translate("MainWindow", "Project Start Date", nullptr));
        labelProjectsDateDue->setText(QCoreApplication::translate("MainWindow", "Projects Due Date", nullptr));
        labelProjectDescription->setText(QCoreApplication::translate("MainWindow", "Project Description", nullptr));
        labelProjectProgress->setText(QCoreApplication::translate("MainWindow", "Progress", nullptr));
        labelProjectProgressStatus->setText(QCoreApplication::translate("MainWindow", "Progress Status", nullptr));
        pushButtonProjectsProgressStatusAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButtonProjectsProgressStatusModify->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        pushButtonProjectsProgressStatusDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        labelProjectsStatus->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        checkBoxProjectsApproved->setText(QCoreApplication::translate("MainWindow", "Approved", nullptr));
        checkBoxProjectsAssigned->setText(QCoreApplication::translate("MainWindow", "Assigned", nullptr));
        groupBoxProgress->setTitle(QString());
        radioButtonProjectsStarted->setText(QCoreApplication::translate("MainWindow", "Started", nullptr));
        radioButtonProjectsCompleted->setText(QCoreApplication::translate("MainWindow", "Completed", nullptr));
        labelProjectsOptions->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        pushButtonProjectsSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButtonProjectsAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButtonProjectsClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButtonProjectsDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButtonProjectsDateStart->setText(QCoreApplication::translate("MainWindow", "Now", nullptr));
        pushButtonProjectsDateDue->setText(QCoreApplication::translate("MainWindow", "90 Days", nullptr));
        labelProjectsPassword->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButtonProjectsShowPassword->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabProjects), QCoreApplication::translate("MainWindow", "Projects", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHelp), QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuFormat->setTitle(QCoreApplication::translate("MainWindow", "Format", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
