/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QPushButton *Modify;
    QPushButton *Reports;
    QPushButton *menuBack;
    QPushButton *chainReports;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(800, 600);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Modify = new QPushButton(centralwidget);
        Modify->setObjectName(QString::fromUtf8("Modify"));
        Modify->setGeometry(QRect(350, 80, 80, 21));
        Reports = new QPushButton(centralwidget);
        Reports->setObjectName(QString::fromUtf8("Reports"));
        Reports->setGeometry(QRect(350, 150, 80, 20));
        menuBack = new QPushButton(centralwidget);
        menuBack->setObjectName(QString::fromUtf8("menuBack"));
        menuBack->setGeometry(QRect(350, 280, 80, 20));
        chainReports = new QPushButton(centralwidget);
        chainReports->setObjectName(QString::fromUtf8("chainReports"));
        chainReports->setGeometry(QRect(350, 210, 80, 20));
        Menu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Menu->setStatusBar(statusbar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "MainWindow", nullptr));
        Modify->setText(QApplication::translate("Menu", "Modify", nullptr));
        Reports->setText(QApplication::translate("Menu", "Reports", nullptr));
        menuBack->setText(QApplication::translate("Menu", "Back", nullptr));
        chainReports->setText(QApplication::translate("Menu", "Chain Reports", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
