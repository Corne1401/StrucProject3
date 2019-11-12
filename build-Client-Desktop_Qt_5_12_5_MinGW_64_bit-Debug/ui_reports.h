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
    QPushButton *aisles;
    QPushButton *products;
    QPushButton *brands;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Reports)
    {
        if (Reports->objectName().isEmpty())
            Reports->setObjectName(QString::fromUtf8("Reports"));
        Reports->resize(800, 600);
        centralwidget = new QWidget(Reports);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aisles = new QPushButton(centralwidget);
        aisles->setObjectName(QString::fromUtf8("aisles"));
        aisles->setGeometry(QRect(330, 70, 80, 21));
        products = new QPushButton(centralwidget);
        products->setObjectName(QString::fromUtf8("products"));
        products->setGeometry(QRect(330, 180, 80, 21));
        brands = new QPushButton(centralwidget);
        brands->setObjectName(QString::fromUtf8("brands"));
        brands->setGeometry(QRect(330, 290, 80, 21));
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
        aisles->setText(QApplication::translate("Reports", "Aisles", nullptr));
        products->setText(QApplication::translate("Reports", "Products", nullptr));
        brands->setText(QApplication::translate("Reports", "Brands", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reports: public Ui_Reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
