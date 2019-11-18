/********************************************************************************
** Form generated from reading UI file 'checkbrand.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKBRAND_H
#define UI_CHECKBRAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckBrand
{
public:
    QWidget *centralwidget;
    QLineEdit *prodCode;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *aisleCode;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CheckBrand)
    {
        if (CheckBrand->objectName().isEmpty())
            CheckBrand->setObjectName(QString::fromUtf8("CheckBrand"));
        CheckBrand->resize(800, 600);
        centralwidget = new QWidget(CheckBrand);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        prodCode = new QLineEdit(centralwidget);
        prodCode->setObjectName(QString::fromUtf8("prodCode"));
        prodCode->setGeometry(QRect(340, 230, 113, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(367, 200, 71, 16));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(374, 83, 47, 13));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 330, 91, 21));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(340, 110, 113, 21));
        CheckBrand->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(CheckBrand);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CheckBrand->setStatusBar(statusbar);

        retranslateUi(CheckBrand);

        QMetaObject::connectSlotsByName(CheckBrand);
    } // setupUi

    void retranslateUi(QMainWindow *CheckBrand)
    {
        CheckBrand->setWindowTitle(QApplication::translate("CheckBrand", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("CheckBrand", "Product code", nullptr));
        label->setText(QApplication::translate("CheckBrand", "Aisle code", nullptr));
        pushButton->setText(QApplication::translate("CheckBrand", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckBrand: public Ui_CheckBrand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKBRAND_H
