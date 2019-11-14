/********************************************************************************
** Form generated from reading UI file 'brandlist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRANDLIST_H
#define UI_BRANDLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrandList
{
public:
    QWidget *centralwidget;
    QLineEdit *aisleCode;
    QLineEdit *prodCode;
    QLabel *label;
    QLabel *label_2;
    QPushButton *generate;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BrandList)
    {
        if (BrandList->objectName().isEmpty())
            BrandList->setObjectName(QString::fromUtf8("BrandList"));
        BrandList->resize(800, 600);
        centralwidget = new QWidget(BrandList);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(350, 130, 113, 21));
        prodCode = new QLineEdit(centralwidget);
        prodCode->setObjectName(QString::fromUtf8("prodCode"));
        prodCode->setGeometry(QRect(350, 242, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(385, 100, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(375, 210, 71, 16));
        generate = new QPushButton(centralwidget);
        generate->setObjectName(QString::fromUtf8("generate"));
        generate->setGeometry(QRect(359, 360, 91, 21));
        BrandList->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(BrandList);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BrandList->setStatusBar(statusbar);

        retranslateUi(BrandList);

        QMetaObject::connectSlotsByName(BrandList);
    } // setupUi

    void retranslateUi(QMainWindow *BrandList)
    {
        BrandList->setWindowTitle(QApplication::translate("BrandList", "MainWindow", nullptr));
        label->setText(QApplication::translate("BrandList", "Aisle code", nullptr));
        label_2->setText(QApplication::translate("BrandList", "Product code", nullptr));
        generate->setText(QApplication::translate("BrandList", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrandList: public Ui_BrandList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRANDLIST_H
