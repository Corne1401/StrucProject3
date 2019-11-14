/********************************************************************************
** Form generated from reading UI file 'reports.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTS_H
#define UI_REPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reports
{
public:
    QWidget *centralwidget;
    QPushButton *checkAisles;
    QPushButton *checkProd;
    QPushButton *checkBrands;
    QPushButton *backBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Reports)
    {
        if (Reports->objectName().isEmpty())
            Reports->setObjectName(QString::fromUtf8("Reports"));
        Reports->resize(800, 600);
        centralwidget = new QWidget(Reports);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        checkAisles = new QPushButton(centralwidget);
        checkAisles->setObjectName(QString::fromUtf8("checkAisles"));
        checkAisles->setGeometry(QRect(130, 110, 80, 21));
        checkProd = new QPushButton(centralwidget);
        checkProd->setObjectName(QString::fromUtf8("checkProd"));
        checkProd->setGeometry(QRect(570, 110, 80, 21));
        checkBrands = new QPushButton(centralwidget);
        checkBrands->setObjectName(QString::fromUtf8("checkBrands"));
        checkBrands->setGeometry(QRect(360, 200, 80, 21));
        backBtn = new QPushButton(centralwidget);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(360, 340, 80, 21));
        Reports->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Reports);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Reports->setStatusBar(statusbar);

        retranslateUi(Reports);

        QMetaObject::connectSlotsByName(Reports);
    } // setupUi

    void retranslateUi(QMainWindow *Reports)
    {
        Reports->setWindowTitle(QApplication::translate("Reports", "MainWindow", nullptr));
        checkAisles->setText(QApplication::translate("Reports", "Check aisles", nullptr));
        checkProd->setText(QApplication::translate("Reports", "Check products", nullptr));
        checkBrands->setText(QApplication::translate("Reports", "Check brands", nullptr));
        backBtn->setText(QApplication::translate("Reports", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reports: public Ui_Reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
