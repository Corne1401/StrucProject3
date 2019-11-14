/********************************************************************************
** Form generated from reading UI file 'showbrands.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWBRANDS_H
#define UI_SHOWBRANDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowBrands
{
public:
    QWidget *centralwidget;
    QLineEdit *aisleCode;
    QLineEdit *prodCode;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ShowBrands)
    {
        if (ShowBrands->objectName().isEmpty())
            ShowBrands->setObjectName(QString::fromUtf8("ShowBrands"));
        ShowBrands->resize(800, 600);
        centralwidget = new QWidget(ShowBrands);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(350, 100, 113, 21));
        prodCode = new QLineEdit(centralwidget);
        prodCode->setObjectName(QString::fromUtf8("prodCode"));
        prodCode->setGeometry(QRect(350, 220, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(384, 73, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(377, 190, 71, 16));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 320, 91, 21));
        ShowBrands->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ShowBrands);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ShowBrands->setStatusBar(statusbar);

        retranslateUi(ShowBrands);

        QMetaObject::connectSlotsByName(ShowBrands);
    } // setupUi

    void retranslateUi(QMainWindow *ShowBrands)
    {
        ShowBrands->setWindowTitle(QApplication::translate("ShowBrands", "MainWindow", nullptr));
        label->setText(QApplication::translate("ShowBrands", "Aisle code", nullptr));
        label_2->setText(QApplication::translate("ShowBrands", "Product code", nullptr));
        pushButton->setText(QApplication::translate("ShowBrands", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowBrands: public Ui_ShowBrands {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWBRANDS_H
