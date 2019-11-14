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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UnloggedMenu
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UnloggedMenu)
    {
        if (UnloggedMenu->objectName().isEmpty())
            UnloggedMenu->setObjectName(QString::fromUtf8("UnloggedMenu"));
        UnloggedMenu->resize(800, 600);
        centralwidget = new QWidget(UnloggedMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 110, 80, 21));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(520, 110, 80, 21));
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
        pushButton->setText(QApplication::translate("UnloggedMenu", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("UnloggedMenu", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UnloggedMenu: public Ui_UnloggedMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNLOGGEDMENU_H
