/********************************************************************************
** Form generated from reading UI file 'newproduct.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPRODUCT_H
#define UI_NEWPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newProduct
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *newProdCode;
    QLineEdit *aisleCode;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *newProductConfirm;
    QLineEdit *newName;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newProduct)
    {
        if (newProduct->objectName().isEmpty())
            newProduct->setObjectName(QString::fromUtf8("newProduct"));
        newProduct->resize(800, 600);
        centralwidget = new QWidget(newProduct);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 50, 71, 16));
        newProdCode = new QLineEdit(centralwidget);
        newProdCode->setObjectName(QString::fromUtf8("newProdCode"));
        newProdCode->setGeometry(QRect(320, 160, 131, 21));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(320, 80, 131, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 210, 101, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 130, 91, 16));
        newProductConfirm = new QPushButton(centralwidget);
        newProductConfirm->setObjectName(QString::fromUtf8("newProductConfirm"));
        newProductConfirm->setGeometry(QRect(340, 320, 91, 21));
        newName = new QLineEdit(centralwidget);
        newName->setObjectName(QString::fromUtf8("newName"));
        newName->setGeometry(QRect(320, 240, 131, 21));
        newProduct->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(newProduct);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        newProduct->setStatusBar(statusbar);

        retranslateUi(newProduct);

        QMetaObject::connectSlotsByName(newProduct);
    } // setupUi

    void retranslateUi(QMainWindow *newProduct)
    {
        newProduct->setWindowTitle(QApplication::translate("newProduct", "MainWindow", nullptr));
        label->setText(QApplication::translate("newProduct", "Aisle code", nullptr));
        label_3->setText(QApplication::translate("newProduct", "New product name", nullptr));
        label_2->setText(QApplication::translate("newProduct", "New product code", nullptr));
        newProductConfirm->setText(QApplication::translate("newProduct", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newProduct: public Ui_newProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPRODUCT_H
