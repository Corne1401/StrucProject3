/********************************************************************************
** Form generated from reading UI file 'generateall.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEALL_H
#define UI_GENERATEALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GenerateAll
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *prodCode;
    QLineEdit *aisleCode;
    QLabel *label;
    QLabel *label_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GenerateAll)
    {
        if (GenerateAll->objectName().isEmpty())
            GenerateAll->setObjectName(QString::fromUtf8("GenerateAll"));
        GenerateAll->resize(800, 600);
        centralwidget = new QWidget(GenerateAll);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 270, 80, 21));
        prodCode = new QLineEdit(centralwidget);
        prodCode->setObjectName(QString::fromUtf8("prodCode"));
        prodCode->setGeometry(QRect(320, 210, 121, 21));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(320, 110, 121, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(354, 80, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 180, 71, 16));
        GenerateAll->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(GenerateAll);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GenerateAll->setStatusBar(statusbar);

        retranslateUi(GenerateAll);

        QMetaObject::connectSlotsByName(GenerateAll);
    } // setupUi

    void retranslateUi(QMainWindow *GenerateAll)
    {
        GenerateAll->setWindowTitle(QApplication::translate("GenerateAll", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("GenerateAll", "Generate", nullptr));
        label->setText(QApplication::translate("GenerateAll", "Aisle code", nullptr));
        label_2->setText(QApplication::translate("GenerateAll", "Product code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GenerateAll: public Ui_GenerateAll {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEALL_H
