/********************************************************************************
** Form generated from reading UI file 'checkdatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKDATABASE_H
#define UI_CHECKDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_checkDataBase
{
public:
    QWidget *centralwidget;
    QPushButton *checkAisles;
    QPushButton *backBtn;
    QPushButton *checkBrands;
    QPushButton *checkProd;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *checkDataBase)
    {
        if (checkDataBase->objectName().isEmpty())
            checkDataBase->setObjectName(QString::fromUtf8("checkDataBase"));
        checkDataBase->resize(800, 600);
        centralwidget = new QWidget(checkDataBase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        checkAisles = new QPushButton(centralwidget);
        checkAisles->setObjectName(QString::fromUtf8("checkAisles"));
        checkAisles->setGeometry(QRect(190, 100, 80, 21));
        backBtn = new QPushButton(centralwidget);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(370, 350, 80, 21));
        checkBrands = new QPushButton(centralwidget);
        checkBrands->setObjectName(QString::fromUtf8("checkBrands"));
        checkBrands->setGeometry(QRect(370, 230, 80, 21));
        checkProd = new QPushButton(centralwidget);
        checkProd->setObjectName(QString::fromUtf8("checkProd"));
        checkProd->setGeometry(QRect(550, 100, 80, 21));
        checkDataBase->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(checkDataBase);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        checkDataBase->setStatusBar(statusbar);

        retranslateUi(checkDataBase);

        QMetaObject::connectSlotsByName(checkDataBase);
    } // setupUi

    void retranslateUi(QMainWindow *checkDataBase)
    {
        checkDataBase->setWindowTitle(QApplication::translate("checkDataBase", "MainWindow", nullptr));
        checkAisles->setText(QApplication::translate("checkDataBase", "Check aisles", nullptr));
        backBtn->setText(QApplication::translate("checkDataBase", "Back", nullptr));
        checkBrands->setText(QApplication::translate("checkDataBase", "Check brands", nullptr));
        checkProd->setText(QApplication::translate("checkDataBase", "Check products", nullptr));
    } // retranslateUi

};

namespace Ui {
    class checkDataBase: public Ui_checkDataBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKDATABASE_H
