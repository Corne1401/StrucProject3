/********************************************************************************
** Form generated from reading UI file 'showbrands.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWBRANDS_H
#define UI_SHOWBRANDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowBrands
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ShowBrands)
    {
        if (ShowBrands->objectName().isEmpty())
            ShowBrands->setObjectName(QString::fromUtf8("ShowBrands"));
        ShowBrands->resize(800, 600);
        menubar = new QMenuBar(ShowBrands);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        ShowBrands->setMenuBar(menubar);
        centralwidget = new QWidget(ShowBrands);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ShowBrands->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ShowBrands);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ShowBrands->setStatusBar(statusbar);

        retranslateUi(ShowBrands);

        QMetaObject::connectSlotsByName(ShowBrands);
    } // setupUi

    void retranslateUi(QMainWindow *ShowBrands)
    {
        ShowBrands->setWindowTitle(QApplication::translate("ShowBrands", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowBrands: public Ui_ShowBrands {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWBRANDS_H
