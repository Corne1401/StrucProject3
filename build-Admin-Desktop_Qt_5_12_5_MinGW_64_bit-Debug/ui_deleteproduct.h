/********************************************************************************
** Form generated from reading UI file 'deleteproduct.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEPRODUCT_H
#define UI_DELETEPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteProduct
{
public:
    QWidget *centralwidget;
    QLineEdit *aisleCode;
    QLabel *label_2;
    QLineEdit *productCode;
    QLabel *label;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DeleteProduct)
    {
        if (DeleteProduct->objectName().isEmpty())
            DeleteProduct->setObjectName(QString::fromUtf8("DeleteProduct"));
        DeleteProduct->resize(800, 600);
        centralwidget = new QWidget(DeleteProduct);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(340, 80, 121, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 130, 71, 16));
        productCode = new QLineEdit(centralwidget);
        productCode->setObjectName(QString::fromUtf8("productCode"));
        productCode->setGeometry(QRect(340, 160, 121, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 50, 47, 13));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 240, 80, 21));
        DeleteProduct->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(DeleteProduct);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DeleteProduct->setStatusBar(statusbar);

        retranslateUi(DeleteProduct);

        QMetaObject::connectSlotsByName(DeleteProduct);
    } // setupUi

    void retranslateUi(QMainWindow *DeleteProduct)
    {
        DeleteProduct->setWindowTitle(QApplication::translate("DeleteProduct", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("DeleteProduct", "Product code", nullptr));
        label->setText(QApplication::translate("DeleteProduct", "Aisle code", nullptr));
        pushButton->setText(QApplication::translate("DeleteProduct", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteProduct: public Ui_DeleteProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEPRODUCT_H
