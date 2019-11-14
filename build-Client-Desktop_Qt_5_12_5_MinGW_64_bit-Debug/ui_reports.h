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
    QPushButton *aislesBtn;
    QPushButton *prodBtn;
    QPushButton *brandsBtn;
    QPushButton *backBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Reports)
    {
        if (Reports->objectName().isEmpty())
            Reports->setObjectName(QString::fromUtf8("Reports"));
        Reports->resize(800, 600);
        centralwidget = new QWidget(Reports);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aislesBtn = new QPushButton(centralwidget);
        aislesBtn->setObjectName(QString::fromUtf8("aislesBtn"));
        aislesBtn->setGeometry(QRect(190, 90, 80, 21));
        prodBtn = new QPushButton(centralwidget);
        prodBtn->setObjectName(QString::fromUtf8("prodBtn"));
        prodBtn->setGeometry(QRect(550, 90, 80, 21));
        brandsBtn = new QPushButton(centralwidget);
        brandsBtn->setObjectName(QString::fromUtf8("brandsBtn"));
        brandsBtn->setGeometry(QRect(370, 220, 80, 21));
        backBtn = new QPushButton(centralwidget);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(370, 340, 80, 21));
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
        aislesBtn->setText(QApplication::translate("Reports", "Check aisles", nullptr));
        prodBtn->setText(QApplication::translate("Reports", "Check products", nullptr));
        brandsBtn->setText(QApplication::translate("Reports", "Check brands", nullptr));
        backBtn->setText(QApplication::translate("Reports", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reports: public Ui_Reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
