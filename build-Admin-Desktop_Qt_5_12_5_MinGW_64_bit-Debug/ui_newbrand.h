/********************************************************************************
** Form generated from reading UI file 'newbrand.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWBRAND_H
#define UI_NEWBRAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newBrand
{
public:
    QWidget *centralwidget;
    QLineEdit *aisleCode_2;
    QLineEdit *newBrandName;
    QLabel *label_4;
    QLineEdit *productCode;
    QLabel *label_5;
    QPushButton *confirmNewBrand;
    QLineEdit *newBrandCode;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *amount;
    QLabel *label;
    QLineEdit *price;
    QLabel *label_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newBrand)
    {
        if (newBrand->objectName().isEmpty())
            newBrand->setObjectName(QString::fromUtf8("newBrand"));
        newBrand->resize(800, 600);
        centralwidget = new QWidget(newBrand);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aisleCode_2 = new QLineEdit(centralwidget);
        aisleCode_2->setObjectName(QString::fromUtf8("aisleCode_2"));
        aisleCode_2->setGeometry(QRect(340, 60, 121, 21));
        newBrandName = new QLineEdit(centralwidget);
        newBrandName->setObjectName(QString::fromUtf8("newBrandName"));
        newBrandName->setGeometry(QRect(340, 300, 121, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(360, 110, 91, 20));
        productCode = new QLineEdit(centralwidget);
        productCode->setObjectName(QString::fromUtf8("productCode"));
        productCode->setGeometry(QRect(340, 140, 121, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(350, 270, 101, 16));
        confirmNewBrand = new QPushButton(centralwidget);
        confirmNewBrand->setObjectName(QString::fromUtf8("confirmNewBrand"));
        confirmNewBrand->setGeometry(QRect(350, 510, 80, 21));
        newBrandCode = new QLineEdit(centralwidget);
        newBrandCode->setObjectName(QString::fromUtf8("newBrandCode"));
        newBrandCode->setGeometry(QRect(340, 220, 121, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(360, 30, 71, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(350, 190, 111, 16));
        amount = new QLineEdit(centralwidget);
        amount->setObjectName(QString::fromUtf8("amount"));
        amount->setGeometry(QRect(340, 380, 113, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 350, 55, 16));
        price = new QLineEdit(centralwidget);
        price->setObjectName(QString::fromUtf8("price"));
        price->setGeometry(QRect(340, 460, 113, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 430, 55, 16));
        newBrand->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(newBrand);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        newBrand->setStatusBar(statusbar);

        retranslateUi(newBrand);

        QMetaObject::connectSlotsByName(newBrand);
    } // setupUi

    void retranslateUi(QMainWindow *newBrand)
    {
        newBrand->setWindowTitle(QApplication::translate("newBrand", "MainWindow", nullptr));
        label_4->setText(QApplication::translate("newBrand", "Product code", nullptr));
        label_5->setText(QApplication::translate("newBrand", "New brand name", nullptr));
        confirmNewBrand->setText(QApplication::translate("newBrand", "Confirm", nullptr));
        label_6->setText(QApplication::translate("newBrand", "Aisle code", nullptr));
        label_7->setText(QApplication::translate("newBrand", "New brand code", nullptr));
        label->setText(QApplication::translate("newBrand", "Amount", nullptr));
        label_2->setText(QApplication::translate("newBrand", "Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newBrand: public Ui_newBrand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWBRAND_H
