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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_checkDataBase
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *checkDataBase)
    {
        if (checkDataBase->objectName().isEmpty())
            checkDataBase->setObjectName(QString::fromUtf8("checkDataBase"));
        checkDataBase->resize(800, 600);
        menubar = new QMenuBar(checkDataBase);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        checkDataBase->setMenuBar(menubar);
        centralwidget = new QWidget(checkDataBase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
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
    } // retranslateUi

};

namespace Ui {
    class checkDataBase: public Ui_checkDataBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKDATABASE_H
