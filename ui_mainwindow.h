/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QLineEdit *sendIDEdit;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_6;
    QComboBox *comboBox_5;
    QPushButton *sendBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QLineEdit *sendDataEdit;
    QGroupBox *groupBox_3;
    QPushButton *cleanListBtn;
    QTableWidget *tableWidget;
    QCheckBox *checkBox_4;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *comboBox_3;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QComboBox *comboBox_2;
    QComboBox *comboBox;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_13;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_StartTimer;
    QPushButton *pushButton_Clear_2;
    QChartView *graphicsView_2;
    QPushButton *pushButton_velocityctl_forward;
    QPushButton *pushButton_motor_disable;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QGroupBox *groupBox_7;
    QLabel *label_4;
    QLabel *label_15;
    QComboBox *comboBox_7;
    QComboBox *comboBox_8;
    QPushButton *pushButton_9;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1389, 1066);
        MainWindow->setMinimumSize(QSize(1260, 590));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(460, 10, 371, 191));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout->addWidget(label_11);

        sendIDEdit = new QLineEdit(groupBox_2);
        sendIDEdit->setObjectName(QString::fromUtf8("sendIDEdit"));

        horizontalLayout->addWidget(sendIDEdit);

        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        horizontalLayout->addWidget(comboBox_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBox_6 = new QComboBox(groupBox_2);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setEnabled(true);

        horizontalLayout_2->addWidget(comboBox_6);

        comboBox_5 = new QComboBox(groupBox_2);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setEnabled(true);

        horizontalLayout_2->addWidget(comboBox_5);

        sendBtn = new QPushButton(groupBox_2);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setEnabled(false);

        horizontalLayout_2->addWidget(sendBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_3->addWidget(label_14);

        sendDataEdit = new QLineEdit(groupBox_2);
        sendDataEdit->setObjectName(QString::fromUtf8("sendDataEdit"));

        horizontalLayout_3->addWidget(sendDataEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 210, 1381, 371));
        cleanListBtn = new QPushButton(groupBox_3);
        cleanListBtn->setObjectName(QString::fromUtf8("cleanListBtn"));
        cleanListBtn->setGeometry(QRect(1270, 60, 81, 28));
        tableWidget = new QTableWidget(groupBox_3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 1251, 341));
        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setEnabled(true);
        checkBox_4->setGeometry(QRect(1268, 30, 101, 20));
        checkBox_4->setChecked(true);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 221, 191));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 19, 201, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_3 = new QComboBox(layoutWidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout->addWidget(comboBox_3, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);

        gridLayout->addWidget(pushButton_2, 4, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);

        gridLayout->addWidget(pushButton_4, 3, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);

        gridLayout->addWidget(pushButton_3, 4, 1, 1, 1);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(240, 10, 211, 191));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_6);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_7);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_8);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_4->addWidget(label_12);

        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_4->addWidget(label_13);


        horizontalLayout_4->addLayout(verticalLayout_4);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(9, 649, 1371, 401));
        pushButton_Clear = new QPushButton(groupBox_5);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(620, 20, 241, 28));
        pushButton_StartTimer = new QPushButton(groupBox_5);
        pushButton_StartTimer->setObjectName(QString::fromUtf8("pushButton_StartTimer"));
        pushButton_StartTimer->setGeometry(QRect(240, 20, 241, 28));
        pushButton_Clear_2 = new QPushButton(groupBox_5);
        pushButton_Clear_2->setObjectName(QString::fromUtf8("pushButton_Clear_2"));
        pushButton_Clear_2->setGeometry(QRect(600, -50, 241, 28));
        graphicsView_2 = new QChartView(centralWidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(20, 700, 1251, 331));
        pushButton_velocityctl_forward = new QPushButton(centralWidget);
        pushButton_velocityctl_forward->setObjectName(QString::fromUtf8("pushButton_velocityctl_forward"));
        pushButton_velocityctl_forward->setGeometry(QRect(250, 590, 241, 28));
        pushButton_motor_disable = new QPushButton(centralWidget);
        pushButton_motor_disable->setObjectName(QString::fromUtf8("pushButton_motor_disable"));
        pushButton_motor_disable->setGeometry(QRect(630, 590, 241, 28));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(1100, 10, 281, 191));
        gridLayout_3 = new QGridLayout(groupBox_6);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_5 = new QPushButton(groupBox_6);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_3->addWidget(pushButton_5, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_6);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout_3->addWidget(pushButton_6, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(groupBox_6);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout_3->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox_6);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout_3->addWidget(pushButton_8, 1, 1, 1, 1);

        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(830, 10, 251, 191));
        label_4 = new QLabel(groupBox_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 30, 54, 12));
        label_15 = new QLabel(groupBox_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 70, 54, 12));
        comboBox_7 = new QComboBox(groupBox_7);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setGeometry(QRect(110, 20, 101, 31));
        comboBox_8 = new QComboBox(groupBox_7);
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));
        comboBox_8->setGeometry(QRect(110, 60, 101, 31));
        pushButton_9 = new QPushButton(groupBox_7);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(20, 100, 211, 23));
        verticalLayoutWidget = new QWidget(groupBox_7);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 130, 171, 141));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(verticalLayoutWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout_2->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(verticalLayoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        verticalLayout_2->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(verticalLayoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        verticalLayout_2->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(verticalLayoutWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        verticalLayout_2->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(verticalLayoutWidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        verticalLayout_2->addWidget(pushButton_14);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CAN Tool", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\217\221\351\200\201", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ID(0x):", nullptr));
        sendIDEdit->setText(QCoreApplication::translate("MainWindow", "00000000", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2230", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2231", nullptr));

        comboBox_6->setItemText(0, QCoreApplication::translate("MainWindow", "\346\240\207\345\207\206\345\270\247", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("MainWindow", "\346\211\251\345\261\225\345\270\247", nullptr));

        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\270\247", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "\350\277\234\347\250\213\345\270\247", nullptr));

        sendBtn->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256(0x,\344\273\245\347\251\272\346\240\274\351\232\224\345\274\200)\357\274\232", nullptr));
        sendDataEdit->setText(QCoreApplication::translate("MainWindow", "00 11 22 33 44 55 66 77", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\216\245\346\224\266", nullptr));
        cleanListBtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "\345\256\236\346\227\266\346\230\276\347\244\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\347\264\242\345\274\225\357\274\232", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "10Kbps", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "20Kbps", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "40Kbps", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "50Kbps", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("MainWindow", "80Kbps", nullptr));
        comboBox_3->setItemText(5, QCoreApplication::translate("MainWindow", "100Kbps", nullptr));
        comboBox_3->setItemText(6, QCoreApplication::translate("MainWindow", "125Kbps", nullptr));
        comboBox_3->setItemText(7, QCoreApplication::translate("MainWindow", "200Kbps", nullptr));
        comboBox_3->setItemText(8, QCoreApplication::translate("MainWindow", "250Kbps", nullptr));
        comboBox_3->setItemText(9, QCoreApplication::translate("MainWindow", "400Kbps", nullptr));
        comboBox_3->setItemText(10, QCoreApplication::translate("MainWindow", "500Kbps", nullptr));
        comboBox_3->setItemText(11, QCoreApplication::translate("MainWindow", "666Kbps", nullptr));
        comboBox_3->setItemText(12, QCoreApplication::translate("MainWindow", "800Kbps", nullptr));
        comboBox_3->setItemText(13, QCoreApplication::translate("MainWindow", "1000Kbps", nullptr));
        comboBox_3->setItemText(14, QCoreApplication::translate("MainWindow", "33.33Kbps", nullptr));
        comboBox_3->setItemText(15, QCoreApplication::translate("MainWindow", "66.66Kbps", nullptr));
        comboBox_3->setItemText(16, QCoreApplication::translate("MainWindow", "83.33Kbps", nullptr));

        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226CAN", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\256\276\345\244\207", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250CAN", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox_2->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBox_2->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox_2->setItemText(11, QCoreApplication::translate("MainWindow", "11", nullptr));
        comboBox_2->setItemText(12, QCoreApplication::translate("MainWindow", "12", nullptr));
        comboBox_2->setItemText(13, QCoreApplication::translate("MainWindow", "13", nullptr));

        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "USBCAN-2A", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "USBCAN-2C", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "CANalyst-II", nullptr));

        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\345\217\243\346\235\277\344\277\241\346\201\257", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "CAN\351\200\232\351\201\223\346\225\260\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\347\241\254\344\273\266\347\211\210\346\234\254\345\217\267:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\216\245\345\217\243\345\272\223\347\211\210\346\234\254\345\217\267\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\344\270\255\346\226\255\345\217\267:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        pushButton_StartTimer->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        pushButton_Clear_2->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        pushButton_velocityctl_forward->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\346\250\241\345\274\217\346\255\243\350\275\254", nullptr));
        pushButton_motor_disable->setText(QCoreApplication::translate("MainWindow", "\345\244\261\350\203\275", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\346\216\247\345\210\266", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\350\275\256\345\273\223\351\200\237\345\272\246\346\250\241\345\274\217", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\350\275\256\345\273\223\344\275\215\347\275\256\346\250\241\345\274\217", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\350\275\256\345\273\223\345\212\233\347\237\251\346\250\241\345\274\217", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\345\244\261\350\203\275", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\346\200\273\350\247\210", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\345\216\202\345\256\266\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\345\236\213\345\217\267\357\274\232", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("MainWindow", "\351\222\233\350\231\216", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("MainWindow", "\351\233\266\345\267\256\344\272\221\346\216\247", nullptr));
        comboBox_7->setItemText(2, QCoreApplication::translate("MainWindow", "Elmo", nullptr));
        comboBox_7->setItemText(3, QCoreApplication::translate("MainWindow", "\347\253\213\350\277\210\350\203\234", nullptr));

        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\351\222\233\350\231\216\347\224\265\346\234\272\346\226\207\346\241\243", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "\351\233\266\345\267\256\347\224\265\346\234\272\346\226\207\346\241\243", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Elmo\347\224\265\346\234\272\346\226\207\346\241\243", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "\347\253\213\350\277\210\350\203\234\347\224\265\346\234\272\346\226\207\346\241\243", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\350\277\220\347\224\250\347\224\265\346\234\272\345\236\213\345\217\267\346\261\207\346\200\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
