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
    QPushButton *checkPrice;
    QPushButton *checkProd;
    QPushButton *checkTask;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UnloggedMenu)
    {
        if (UnloggedMenu->objectName().isEmpty())
            UnloggedMenu->setObjectName(QString::fromUtf8("UnloggedMenu"));
        UnloggedMenu->resize(800, 600);
        centralwidget = new QWidget(UnloggedMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        checkPrice = new QPushButton(centralwidget);
        checkPrice->setObjectName(QString::fromUtf8("checkPrice"));
        checkPrice->setGeometry(QRect(360, 90, 80, 21));
        checkProd = new QPushButton(centralwidget);
        checkProd->setObjectName(QString::fromUtf8("checkProd"));
        checkProd->setGeometry(QRect(360, 220, 80, 21));
        checkTask = new QPushButton(centralwidget);
        checkTask->setObjectName(QString::fromUtf8("checkTask"));
        checkTask->setGeometry(QRect(360, 350, 80, 21));
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
        checkPrice->setText(QApplication::translate("UnloggedMenu", "Check price", nullptr));
        checkProd->setText(QApplication::translate("UnloggedMenu", "Check product", nullptr));
        checkTask->setText(QApplication::translate("UnloggedMenu", "Check Tax", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UnloggedMenu: public Ui_UnloggedMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNLOGGEDMENU_H
