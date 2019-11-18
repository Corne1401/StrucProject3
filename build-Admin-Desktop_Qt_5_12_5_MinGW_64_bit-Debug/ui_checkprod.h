/********************************************************************************
** Form generated from reading UI file 'checkprod.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKPROD_H
#define UI_CHECKPROD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckProd
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *aisleCode;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CheckProd)
    {
        if (CheckProd->objectName().isEmpty())
            CheckProd->setObjectName(QString::fromUtf8("CheckProd"));
        CheckProd->resize(800, 600);
        centralwidget = new QWidget(CheckProd);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 90, 47, 13));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(350, 120, 113, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 200, 91, 21));
        CheckProd->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(CheckProd);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CheckProd->setStatusBar(statusbar);

        retranslateUi(CheckProd);

        QMetaObject::connectSlotsByName(CheckProd);
    } // setupUi

    void retranslateUi(QMainWindow *CheckProd)
    {
        CheckProd->setWindowTitle(QApplication::translate("CheckProd", "MainWindow", nullptr));
        label->setText(QApplication::translate("CheckProd", "Aisle code", nullptr));
        pushButton->setText(QApplication::translate("CheckProd", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckProd: public Ui_CheckProd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKPROD_H
