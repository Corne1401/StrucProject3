/********************************************************************************
** Form generated from reading UI file 'check.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECK_H
#define UI_CHECK_H

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

class Ui_Check
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QLineEdit *aisleCode;
    QLineEdit *prodCode;
    QLineEdit *brandCode;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *checkButton;
    QPushButton *backButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Check)
    {
        if (Check->objectName().isEmpty())
            Check->setObjectName(QString::fromUtf8("Check"));
        Check->resize(800, 600);
        centralwidget = new QWidget(Check);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(320, 50, 151, 22));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(330, 111, 121, 20));
        prodCode = new QLineEdit(centralwidget);
        prodCode->setObjectName(QString::fromUtf8("prodCode"));
        prodCode->setGeometry(QRect(330, 180, 121, 21));
        brandCode = new QLineEdit(centralwidget);
        brandCode->setObjectName(QString::fromUtf8("brandCode"));
        brandCode->setGeometry(QRect(330, 250, 121, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(368, 90, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 154, 71, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(367, 227, 61, 16));
        checkButton = new QPushButton(centralwidget);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));
        checkButton->setGeometry(QRect(345, 330, 91, 21));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(350, 400, 80, 21));
        Check->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Check);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Check->setStatusBar(statusbar);

        retranslateUi(Check);

        QMetaObject::connectSlotsByName(Check);
    } // setupUi

    void retranslateUi(QMainWindow *Check)
    {
        Check->setWindowTitle(QApplication::translate("Check", "MainWindow", nullptr));
        comboBox->setItemText(0, QApplication::translate("Check", "Check price", nullptr));
        comboBox->setItemText(1, QApplication::translate("Check", "Check basic product", nullptr));
        comboBox->setItemText(2, QApplication::translate("Check", "Check tax of a product", nullptr));

        label->setText(QApplication::translate("Check", "Aisle code", nullptr));
        label_2->setText(QApplication::translate("Check", "Product code", nullptr));
        label_3->setText(QApplication::translate("Check", "Brand code", nullptr));
        checkButton->setText(QApplication::translate("Check", "Check", nullptr));
        backButton->setText(QApplication::translate("Check", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Check: public Ui_Check {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECK_H
