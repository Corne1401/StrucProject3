/********************************************************************************
** Form generated from reading UI file 'modbasicproduct.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODBASICPRODUCT_H
#define UI_MODBASICPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modBasicProduct
{
public:
    QWidget *centralwidget;
    QCheckBox *checkBox;
    QLineEdit *brandCode;
    QLineEdit *prodCode;
    QLineEdit *aisleCode;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *modBasicProduct)
    {
        if (modBasicProduct->objectName().isEmpty())
            modBasicProduct->setObjectName(QString::fromUtf8("modBasicProduct"));
        modBasicProduct->resize(800, 600);
        centralwidget = new QWidget(modBasicProduct);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(330, 270, 111, 19));
        brandCode = new QLineEdit(centralwidget);
        brandCode->setObjectName(QString::fromUtf8("brandCode"));
        brandCode->setGeometry(QRect(330, 211, 113, 20));
        prodCode = new QLineEdit(centralwidget);
        prodCode->setObjectName(QString::fromUtf8("prodCode"));
        prodCode->setGeometry(QRect(330, 130, 113, 21));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(330, 60, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 30, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 100, 71, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(360, 180, 71, 16));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 340, 91, 21));
        modBasicProduct->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(modBasicProduct);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        modBasicProduct->setStatusBar(statusbar);

        retranslateUi(modBasicProduct);

        QMetaObject::connectSlotsByName(modBasicProduct);
    } // setupUi

    void retranslateUi(QMainWindow *modBasicProduct)
    {
        modBasicProduct->setWindowTitle(QApplication::translate("modBasicProduct", "MainWindow", nullptr));
        checkBox->setText(QApplication::translate("modBasicProduct", "Is a basic product?", nullptr));
        label->setText(QApplication::translate("modBasicProduct", "Aisle code", nullptr));
        label_2->setText(QApplication::translate("modBasicProduct", "Product code", nullptr));
        label_3->setText(QApplication::translate("modBasicProduct", "Brand code", nullptr));
        pushButton->setText(QApplication::translate("modBasicProduct", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modBasicProduct: public Ui_modBasicProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBASICPRODUCT_H
