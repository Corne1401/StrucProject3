/********************************************************************************
** Form generated from reading UI file 'modtax.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODTAX_H
#define UI_MODTAX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModTax
{
public:
    QWidget *centralwidget;
    QRadioButton *isBasic;
    QRadioButton *isNormal;
    QLineEdit *newTax;
    QLabel *label;
    QPushButton *confirmNewTax;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ModTax)
    {
        if (ModTax->objectName().isEmpty())
            ModTax->setObjectName(QString::fromUtf8("ModTax"));
        ModTax->resize(800, 600);
        centralwidget = new QWidget(ModTax);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        isBasic = new QRadioButton(centralwidget);
        isBasic->setObjectName(QString::fromUtf8("isBasic"));
        isBasic->setGeometry(QRect(230, 60, 84, 19));
        isNormal = new QRadioButton(centralwidget);
        isNormal->setObjectName(QString::fromUtf8("isNormal"));
        isNormal->setGeometry(QRect(520, 60, 101, 19));
        newTax = new QLineEdit(centralwidget);
        newTax->setObjectName(QString::fromUtf8("newTax"));
        newTax->setGeometry(QRect(340, 180, 121, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 150, 47, 13));
        confirmNewTax = new QPushButton(centralwidget);
        confirmNewTax->setObjectName(QString::fromUtf8("confirmNewTax"));
        confirmNewTax->setGeometry(QRect(360, 270, 80, 21));
        ModTax->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ModTax);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        ModTax->setMenuBar(menubar);
        statusbar = new QStatusBar(ModTax);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ModTax->setStatusBar(statusbar);

        retranslateUi(ModTax);

        QMetaObject::connectSlotsByName(ModTax);
    } // setupUi

    void retranslateUi(QMainWindow *ModTax)
    {
        ModTax->setWindowTitle(QApplication::translate("ModTax", "MainWindow", nullptr));
        isBasic->setText(QApplication::translate("ModTax", "Basic product", nullptr));
        isNormal->setText(QApplication::translate("ModTax", "Normal product", nullptr));
        label->setText(QApplication::translate("ModTax", "New tax", nullptr));
        confirmNewTax->setText(QApplication::translate("ModTax", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModTax: public Ui_ModTax {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODTAX_H
