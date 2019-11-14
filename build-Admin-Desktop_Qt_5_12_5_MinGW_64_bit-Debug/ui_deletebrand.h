/********************************************************************************
** Form generated from reading UI file 'deletebrand.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEBRAND_H
#define UI_DELETEBRAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteBrand
{
public:
    QWidget *centralwidget;
    QLineEdit *aisleCode;
    QLabel *label_2;
    QLineEdit *productCode;
    QLineEdit *brandCode;
    QLabel *label;
    QLabel *label_3;
    QPushButton *deleteBrand;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DeleteBrand)
    {
        if (DeleteBrand->objectName().isEmpty())
            DeleteBrand->setObjectName(QString::fromUtf8("DeleteBrand"));
        DeleteBrand->resize(800, 600);
        centralwidget = new QWidget(DeleteBrand);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(330, 70, 121, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 120, 71, 16));
        productCode = new QLineEdit(centralwidget);
        productCode->setObjectName(QString::fromUtf8("productCode"));
        productCode->setGeometry(QRect(330, 150, 121, 21));
        brandCode = new QLineEdit(centralwidget);
        brandCode->setObjectName(QString::fromUtf8("brandCode"));
        brandCode->setGeometry(QRect(330, 230, 121, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 40, 47, 13));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(364, 200, 81, 16));
        deleteBrand = new QPushButton(centralwidget);
        deleteBrand->setObjectName(QString::fromUtf8("deleteBrand"));
        deleteBrand->setGeometry(QRect(350, 320, 80, 21));
        DeleteBrand->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(DeleteBrand);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DeleteBrand->setStatusBar(statusbar);

        retranslateUi(DeleteBrand);

        QMetaObject::connectSlotsByName(DeleteBrand);
    } // setupUi

    void retranslateUi(QMainWindow *DeleteBrand)
    {
        DeleteBrand->setWindowTitle(QApplication::translate("DeleteBrand", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("DeleteBrand", "Product code", nullptr));
        label->setText(QApplication::translate("DeleteBrand", "Aisle code", nullptr));
        label_3->setText(QApplication::translate("DeleteBrand", "Brand code", nullptr));
        deleteBrand->setText(QApplication::translate("DeleteBrand", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteBrand: public Ui_DeleteBrand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEBRAND_H
