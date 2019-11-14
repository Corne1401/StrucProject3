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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reports
{
public:
    QWidget *centralwidget;
    QComboBox *selectReport;
    QPushButton *reportsBack;
    QPushButton *reportsGenerate;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Reports)
    {
        if (Reports->objectName().isEmpty())
            Reports->setObjectName(QString::fromUtf8("Reports"));
        Reports->resize(800, 600);
        centralwidget = new QWidget(Reports);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        selectReport = new QComboBox(centralwidget);
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->addItem(QString());
        selectReport->setObjectName(QString::fromUtf8("selectReport"));
        selectReport->setGeometry(QRect(310, 70, 171, 22));
        reportsBack = new QPushButton(centralwidget);
        reportsBack->setObjectName(QString::fromUtf8("reportsBack"));
        reportsBack->setGeometry(QRect(250, 160, 80, 21));
        reportsGenerate = new QPushButton(centralwidget);
        reportsGenerate->setObjectName(QString::fromUtf8("reportsGenerate"));
        reportsGenerate->setGeometry(QRect(460, 160, 80, 21));
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
        selectReport->setItemText(0, QApplication::translate("Reports", "Most visited aisle", nullptr));
        selectReport->setItemText(1, QApplication::translate("Reports", "Least visited aisle", nullptr));
        selectReport->setItemText(2, QApplication::translate("Reports", "Most sold product per aisle", nullptr));
        selectReport->setItemText(3, QApplication::translate("Reports", "Most sold brand", nullptr));
        selectReport->setItemText(4, QApplication::translate("Reports", "Client who bougth the most", nullptr));
        selectReport->setItemText(5, QApplication::translate("Reports", "Client who bougth the least", nullptr));
        selectReport->setItemText(6, QApplication::translate("Reports", "Client who billed most times", nullptr));
        selectReport->setItemText(7, QApplication::translate("Reports", "Client who billed least times", nullptr));
        selectReport->setItemText(8, QApplication::translate("Reports", "Check aisles", nullptr));
        selectReport->setItemText(9, QApplication::translate("Reports", "Check products", nullptr));
        selectReport->setItemText(10, QApplication::translate("Reports", "Check brands", nullptr));
        selectReport->setItemText(11, QApplication::translate("Reports", "Check clients", nullptr));
        selectReport->setItemText(12, QApplication::translate("Reports", "Check inventory", nullptr));
        selectReport->setItemText(13, QApplication::translate("Reports", "Generate all", nullptr));

        reportsBack->setText(QApplication::translate("Reports", "Back", nullptr));
        reportsGenerate->setText(QApplication::translate("Reports", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reports: public Ui_Reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
