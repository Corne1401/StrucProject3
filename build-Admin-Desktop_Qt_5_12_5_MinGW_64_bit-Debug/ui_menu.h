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
    QPushButton *modifyButton;
    QPushButton *reportButton;
    QPushButton *menuBack;
    QPushButton *chainReports;
    QPushButton *insertButton;
    QPushButton *deleteButton;
    QPushButton *checkButton;
    QPushButton *billingButton;
    QPushButton *restockButton;
    QPushButton *checkInventory;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(800, 600);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        modifyButton = new QPushButton(centralwidget);
        modifyButton->setObjectName(QString::fromUtf8("modifyButton"));
        modifyButton->setGeometry(QRect(90, 90, 80, 21));
        reportButton = new QPushButton(centralwidget);
        reportButton->setObjectName(QString::fromUtf8("reportButton"));
        reportButton->setGeometry(QRect(90, 180, 80, 20));
        menuBack = new QPushButton(centralwidget);
        menuBack->setObjectName(QString::fromUtf8("menuBack"));
        menuBack->setGeometry(QRect(340, 380, 80, 20));
        chainReports = new QPushButton(centralwidget);
        chainReports->setObjectName(QString::fromUtf8("chainReports"));
        chainReports->setGeometry(QRect(570, 270, 80, 20));
        insertButton = new QPushButton(centralwidget);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setGeometry(QRect(570, 90, 80, 21));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(570, 180, 80, 21));
        checkButton = new QPushButton(centralwidget);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));
        checkButton->setGeometry(QRect(90, 270, 80, 21));
        billingButton = new QPushButton(centralwidget);
        billingButton->setObjectName(QString::fromUtf8("billingButton"));
        billingButton->setGeometry(QRect(340, 90, 80, 21));
        restockButton = new QPushButton(centralwidget);
        restockButton->setObjectName(QString::fromUtf8("restockButton"));
        restockButton->setGeometry(QRect(340, 180, 80, 21));
        checkInventory = new QPushButton(centralwidget);
        checkInventory->setObjectName(QString::fromUtf8("checkInventory"));
        checkInventory->setGeometry(QRect(340, 270, 80, 21));
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
        modifyButton->setText(QApplication::translate("Menu", "Modify", nullptr));
        reportButton->setText(QApplication::translate("Menu", "Reports", nullptr));
        menuBack->setText(QApplication::translate("Menu", "Back", nullptr));
        chainReports->setText(QApplication::translate("Menu", "Chain Reports", nullptr));
        insertButton->setText(QApplication::translate("Menu", "Insertions", nullptr));
        deleteButton->setText(QApplication::translate("Menu", "Eliminations", nullptr));
        checkButton->setText(QApplication::translate("Menu", "Check", nullptr));
        billingButton->setText(QApplication::translate("Menu", "Billing", nullptr));
        restockButton->setText(QApplication::translate("Menu", "Restock", nullptr));
        checkInventory->setText(QApplication::translate("Menu", "Check inventory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
