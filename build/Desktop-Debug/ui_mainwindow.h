/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startButton;
    QPushButton *stopButton;
    QLabel *label;
    QLabel *label_7;
    QTextEdit *logDisplay;
    QPushButton *testFullButton;
    QPushButton *testRaceButton;
    QPushButton *testEmptyButton;
    QPushButton *testMultiProdButton;
    QPushButton *testMultiConsButton;
    QPushButton *balancedTestButton;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *slotsLayout;
    QLabel *slot0;
    QLabel *slot1;
    QLabel *slot2;
    QLabel *slot3;
    QLabel *slot4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *statusLayout;
    QLabel *semFullLabel;
    QLabel *semEmptyLabel;
    QLabel *producerStatusLabel;
    QLabel *consumerStatusLabel;
    QPushButton *exitButton;
    QLabel *label_3;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(895, 662);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #f0fafa;\n"
"}\n"
"\n"
"QWidget {\n"
"    background-color: #f0fafa;\n"
"    font-family: Arial;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #4db6ac;\n"
"    color: #ffffff;\n"
"    border-radius: 8px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #3a9e94;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #3a9e94;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #b2dfdb;\n"
"    color: #80cbc4;\n"
"}\n"
"\n"
"QTextEdit {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #4db6ac;\n"
"	\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    color: #00695c;\n"
"	font-size:14px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #00695c; \n"
"    font-weight: bold;\n"
"	font:16px;\n"
"	qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"QLabel#slot0, QLabel#slot1, QLabel#slot2, QLabel#slot3, QLabel#slot4 {\n"
"    background-color: #b2dfdb;\n"
"    border: 2px solid #4db6ac;\n"
"    bor"
                        "der-radius: 8px;\n"
"    color: #00695c;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 5px;\n"
"    min-height: 50px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"QLabel#semFullLabel, QLabel#semEmptyLabel {\n"
"    background-color: #e0f7f4;\n"
"    border: 2px solid #4db6ac;\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLabel#producerStatusLabel, QLabel#consumerStatusLabel {\n"
"    background-color: #e0f7f4;\n"
"    border: 2px solid #4db6ac;\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"    font-size: 13px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(20, 200, 88, 55));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(20, 260, 88, 55));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 130, 101, 51));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(250, 30, 141, 31));
        logDisplay = new QTextEdit(centralwidget);
        logDisplay->setObjectName(QString::fromUtf8("logDisplay"));
        logDisplay->setGeometry(QRect(140, 70, 351, 361));
        testFullButton = new QPushButton(centralwidget);
        testFullButton->setObjectName(QString::fromUtf8("testFullButton"));
        testFullButton->setGeometry(QRect(60, 490, 171, 55));
        testRaceButton = new QPushButton(centralwidget);
        testRaceButton->setObjectName(QString::fromUtf8("testRaceButton"));
        testRaceButton->setGeometry(QRect(520, 560, 181, 55));
        testEmptyButton = new QPushButton(centralwidget);
        testEmptyButton->setObjectName(QString::fromUtf8("testEmptyButton"));
        testEmptyButton->setGeometry(QRect(60, 560, 171, 55));
        testMultiProdButton = new QPushButton(centralwidget);
        testMultiProdButton->setObjectName(QString::fromUtf8("testMultiProdButton"));
        testMultiProdButton->setGeometry(QRect(260, 490, 231, 55));
        testMultiProdButton->setStyleSheet(QString::fromUtf8(""));
        testMultiConsButton = new QPushButton(centralwidget);
        testMultiConsButton->setObjectName(QString::fromUtf8("testMultiConsButton"));
        testMultiConsButton->setGeometry(QRect(260, 560, 231, 55));
        balancedTestButton = new QPushButton(centralwidget);
        balancedTestButton->setObjectName(QString::fromUtf8("balancedTestButton"));
        balancedTestButton->setGeometry(QRect(520, 490, 181, 55));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 450, 141, 31));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(510, 70, 101, 361));
        slotsLayout = new QVBoxLayout(verticalLayoutWidget);
        slotsLayout->setObjectName(QString::fromUtf8("slotsLayout"));
        slotsLayout->setContentsMargins(0, 0, 0, 0);
        slot0 = new QLabel(verticalLayoutWidget);
        slot0->setObjectName(QString::fromUtf8("slot0"));
        slot0->setMinimumSize(QSize(10, 64));

        slotsLayout->addWidget(slot0);

        slot1 = new QLabel(verticalLayoutWidget);
        slot1->setObjectName(QString::fromUtf8("slot1"));
        slot1->setMinimumSize(QSize(10, 64));

        slotsLayout->addWidget(slot1);

        slot2 = new QLabel(verticalLayoutWidget);
        slot2->setObjectName(QString::fromUtf8("slot2"));
        slot2->setMinimumSize(QSize(10, 64));

        slotsLayout->addWidget(slot2);

        slot3 = new QLabel(verticalLayoutWidget);
        slot3->setObjectName(QString::fromUtf8("slot3"));
        slot3->setMinimumSize(QSize(10, 64));

        slotsLayout->addWidget(slot3);

        slot4 = new QLabel(verticalLayoutWidget);
        slot4->setObjectName(QString::fromUtf8("slot4"));
        slot4->setMinimumSize(QSize(10, 64));

        slotsLayout->addWidget(slot4);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(650, 70, 221, 361));
        statusLayout = new QVBoxLayout(verticalLayoutWidget_2);
        statusLayout->setObjectName(QString::fromUtf8("statusLayout"));
        statusLayout->setContentsMargins(0, 0, 0, 0);
        semFullLabel = new QLabel(verticalLayoutWidget_2);
        semFullLabel->setObjectName(QString::fromUtf8("semFullLabel"));

        statusLayout->addWidget(semFullLabel);

        semEmptyLabel = new QLabel(verticalLayoutWidget_2);
        semEmptyLabel->setObjectName(QString::fromUtf8("semEmptyLabel"));

        statusLayout->addWidget(semEmptyLabel);

        producerStatusLabel = new QLabel(verticalLayoutWidget_2);
        producerStatusLabel->setObjectName(QString::fromUtf8("producerStatusLabel"));

        statusLayout->addWidget(producerStatusLabel);

        consumerStatusLabel = new QLabel(verticalLayoutWidget_2);
        consumerStatusLabel->setObjectName(QString::fromUtf8("consumerStatusLabel"));

        statusLayout->addWidget(consumerStatusLabel);

        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(730, 490, 131, 55));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(500, 20, 121, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 895, 19));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "STATUS:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ACTIVITY LOG", nullptr));
        testFullButton->setText(QCoreApplication::translate("MainWindow", "BUFFER FULL TEST", nullptr));
        testRaceButton->setText(QCoreApplication::translate("MainWindow", "RACE CONDITION TEST", nullptr));
        testEmptyButton->setText(QCoreApplication::translate("MainWindow", "BUFFER EMPTY TEST", nullptr));
        testMultiProdButton->setText(QCoreApplication::translate("MainWindow", "MULTIPLE PRODUCERS TEST", nullptr));
        testMultiConsButton->setText(QCoreApplication::translate("MainWindow", "MULTIPLE CONSUMERS TEST", nullptr));
        balancedTestButton->setText(QCoreApplication::translate("MainWindow", "BALANCED TEST", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TEST CASES:", nullptr));
        slot0->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        slot1->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        slot2->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        slot3->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        slot4->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        semFullLabel->setText(QCoreApplication::translate("MainWindow", "Sem Full ", nullptr));
        semEmptyLabel->setText(QCoreApplication::translate("MainWindow", "Sem Empty", nullptr));
        producerStatusLabel->setText(QCoreApplication::translate("MainWindow", "Producer Status", nullptr));
        consumerStatusLabel->setText(QCoreApplication::translate("MainWindow", "Consumer Status", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "BUFFER:", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
