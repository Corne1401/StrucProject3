/********************************************************************************
** Form generated from reading UI file 'prodlist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODLIST_H
#define UI_PRODLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProdList
{
public:
    QWidget *centralwidget;
    QLineEdit *aisleCode;
    QPushButton *generate;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProdList)
    {
        if (ProdList->objectName().isEmpty())
            ProdList->setObjectName(QString::fromUtf8("ProdList"));
        ProdList->resize(800, 600);
        centralwidget = new QWidget(ProdList);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(350, 170, 113, 21));
        generate = new QPushButton(centralwidget);
        generate->setObjectName(QString::fromUtf8("generate"));
        generate->setGeometry(QRect(360, 280, 91, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(383, 138, 51, 16));
        ProdList->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ProdList);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProdList->setStatusBar(statusbar);

        retranslateUi(ProdList);

        QMetaObject::connectSlotsByName(ProdList);
    } // setupUi

    void retranslateUi(QMainWindow *ProdList)
    {
        ProdList->setWindowTitle(QApplication::translate("ProdList", "MainWindow", nullptr));
        generate->setText(QApplication::translate("ProdList", "Generate", nullptr));
        label->setText(QApplication::translate("ProdList", "Aisle code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProdList: public Ui_ProdList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODLIST_H
