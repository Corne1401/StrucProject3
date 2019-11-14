/********************************************************************************
** Form generated from reading UI file 'showprod.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPROD_H
#define UI_SHOWPROD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowProd
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *aisleCode;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ShowProd)
    {
        if (ShowProd->objectName().isEmpty())
            ShowProd->setObjectName(QString::fromUtf8("ShowProd"));
        ShowProd->resize(800, 600);
        centralwidget = new QWidget(ShowProd);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 240, 91, 21));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(350, 160, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 130, 47, 13));
        ShowProd->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ShowProd);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ShowProd->setStatusBar(statusbar);

        retranslateUi(ShowProd);

        QMetaObject::connectSlotsByName(ShowProd);
    } // setupUi

    void retranslateUi(QMainWindow *ShowProd)
    {
        ShowProd->setWindowTitle(QApplication::translate("ShowProd", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("ShowProd", "Continue", nullptr));
        label->setText(QApplication::translate("ShowProd", "Aisle code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowProd: public Ui_ShowProd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPROD_H
