/********************************************************************************
** Form generated from reading UI file 'modprice.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODPRICE_H
#define UI_MODPRICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_priceMod
{
public:
    QWidget *centralwidget;
    QLineEdit *aisleCode;
    QLineEdit *prodCode;
    QLineEdit *brandCode;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *newPrice;
    QLabel *label_4;
    QPushButton *modPriceConfirm;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *priceMod)
    {
        if (priceMod->objectName().isEmpty())
            priceMod->setObjectName(QString::fromUtf8("priceMod"));
        priceMod->resize(800, 600);
        centralwidget = new QWidget(priceMod);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(330, 70, 113, 21));
        prodCode = new QLineEdit(centralwidget);
        prodCode->setObjectName(QString::fromUtf8("prodCode"));
        prodCode->setGeometry(QRect(330, 180, 113, 21));
        brandCode = new QLineEdit(centralwidget);
        brandCode->setObjectName(QString::fromUtf8("brandCode"));
        brandCode->setGeometry(QRect(330, 280, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 40, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 150, 71, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(360, 250, 61, 16));
        newPrice = new QLineEdit(centralwidget);
        newPrice->setObjectName(QString::fromUtf8("newPrice"));
        newPrice->setGeometry(QRect(330, 370, 113, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(360, 340, 47, 13));
        modPriceConfirm = new QPushButton(centralwidget);
        modPriceConfirm->setObjectName(QString::fromUtf8("modPriceConfirm"));
        modPriceConfirm->setGeometry(QRect(340, 460, 91, 21));
        priceMod->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(priceMod);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        priceMod->setStatusBar(statusbar);

        retranslateUi(priceMod);

        QMetaObject::connectSlotsByName(priceMod);
    } // setupUi

    void retranslateUi(QMainWindow *priceMod)
    {
        priceMod->setWindowTitle(QApplication::translate("priceMod", "MainWindow", nullptr));
        label->setText(QApplication::translate("priceMod", "Aisle code", nullptr));
        label_2->setText(QApplication::translate("priceMod", "Product code", nullptr));
        label_3->setText(QApplication::translate("priceMod", "Brand code", nullptr));
        label_4->setText(QApplication::translate("priceMod", "New price", nullptr));
        modPriceConfirm->setText(QApplication::translate("priceMod", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class priceMod: public Ui_priceMod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODPRICE_H
