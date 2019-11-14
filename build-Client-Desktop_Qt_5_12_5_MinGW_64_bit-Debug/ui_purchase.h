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
#include <QtWidgets/QComboBox>
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
    QComboBox *aisles;
    QComboBox *products;
    QComboBox *brands;
    QLineEdit *amount;
    QPushButton *purchase_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *purchase)
    {
        if (purchase->objectName().isEmpty())
            purchase->setObjectName(QString::fromUtf8("purchase"));
        purchase->resize(800, 600);
        centralwidget = new QWidget(purchase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aisles = new QComboBox(centralwidget);
        aisles->setObjectName(QString::fromUtf8("aisles"));
        aisles->setGeometry(QRect(30, 90, 161, 24));
        products = new QComboBox(centralwidget);
        products->setObjectName(QString::fromUtf8("products"));
        products->setEnabled(false);
        products->setGeometry(QRect(220, 90, 161, 24));
        brands = new QComboBox(centralwidget);
        brands->setObjectName(QString::fromUtf8("brands"));
        brands->setEnabled(false);
        brands->setGeometry(QRect(410, 90, 161, 24));
        amount = new QLineEdit(centralwidget);
        amount->setObjectName(QString::fromUtf8("amount"));
        amount->setGeometry(QRect(30, 190, 151, 21));
        purchase_2 = new QPushButton(centralwidget);
        purchase_2->setObjectName(QString::fromUtf8("purchase_2"));
        purchase_2->setGeometry(QRect(230, 190, 131, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 60, 55, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 60, 55, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(460, 60, 55, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 160, 55, 16));
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
