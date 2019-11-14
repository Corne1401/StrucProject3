/********************************************************************************
** Form generated from reading UI file 'unloggedmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNLOGGEDMENU_H
#define UI_UNLOGGEDMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UnloggedMenu
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UnloggedMenu)
    {
        if (UnloggedMenu->objectName().isEmpty())
            UnloggedMenu->setObjectName(QString::fromUtf8("UnloggedMenu"));
        UnloggedMenu->resize(800, 600);
        centralwidget = new QWidget(UnloggedMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        UnloggedMenu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UnloggedMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UnloggedMenu->setStatusBar(statusbar);

        retranslateUi(UnloggedMenu);

        QMetaObject::connectSlotsByName(UnloggedMenu);
    } // setupUi

    void retranslateUi(QMainWindow *UnloggedMenu)
    {
        UnloggedMenu->setWindowTitle(QApplication::translate("UnloggedMenu", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UnloggedMenu: public Ui_UnloggedMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNLOGGEDMENU_H
