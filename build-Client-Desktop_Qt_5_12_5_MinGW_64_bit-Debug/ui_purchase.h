/********************************************************************************
** Form generated from reading UI file 'purchase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASE_H
#define UI_PURCHASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_purchase
{
public:
    QWidget *centralwidget;
    QLineEdit *amount;
    QPushButton *purchase_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *products;
    QLineEdit *aisles;
    QLineEdit *brands;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *purchase)
    {
        if (purchase->objectName().isEmpty())
            purchase->setObjectName(QString::fromUtf8("purchase"));
        purchase->resize(800, 600);
        centralwidget = new QWidget(purchase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        amount = new QLineEdit(centralwidget);
        amount->setObjectName(QString::fromUtf8("amount"));
        amount->setGeometry(QRect(30, 450, 151, 21));
        purchase_2 = new QPushButton(centralwidget);
        purchase_2->setObjectName(QString::fromUtf8("purchase_2"));
        purchase_2->setGeometry(QRect(240, 450, 131, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 55, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 170, 55, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 280, 55, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 420, 55, 16));
        products = new QLineEdit(centralwidget);
        products->setObjectName(QString::fromUtf8("products"));
        products->setGeometry(QRect(30, 200, 151, 21));
        aisles = new QLineEdit(centralwidget);
        aisles->setObjectName(QString::fromUtf8("aisles"));
        aisles->setGeometry(QRect(30, 80, 151, 21));
        brands = new QLineEdit(centralwidget);
        brands->setObjectName(QString::fromUtf8("brands"));
        brands->setGeometry(QRect(30, 310, 151, 21));
        purchase->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(purchase);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        purchase->setStatusBar(statusbar);

        retranslateUi(purchase);

        QMetaObject::connectSlotsByName(purchase);
    } // setupUi

    void retranslateUi(QMainWindow *purchase)
    {
        purchase->setWindowTitle(QApplication::translate("purchase", "MainWindow", nullptr));
        purchase_2->setText(QApplication::translate("purchase", "Purchase", nullptr));
        label->setText(QApplication::translate("purchase", "Aisles", nullptr));
        label_2->setText(QApplication::translate("purchase", "Products", nullptr));
        label_3->setText(QApplication::translate("purchase", "Brands", nullptr));
        label_4->setText(QApplication::translate("purchase", "Amount", nullptr));
    } // retranslateUi

};

namespace Ui {
    class purchase: public Ui_purchase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASE_H
