/********************************************************************************
** Form generated from reading UI file 'restock.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTOCK_H
#define UI_RESTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReStock
{
public:
    QWidget *centralwidget;
    QLineEdit *restockAmount;
    QLabel *label;
    QPushButton *restockButton;
    QPushButton *backButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ReStock)
    {
        if (ReStock->objectName().isEmpty())
            ReStock->setObjectName(QString::fromUtf8("ReStock"));
        ReStock->resize(800, 600);
        centralwidget = new QWidget(ReStock);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        restockAmount = new QLineEdit(centralwidget);
        restockAmount->setObjectName(QString::fromUtf8("restockAmount"));
        restockAmount->setGeometry(QRect(350, 110, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(369, 70, 81, 16));
        restockButton = new QPushButton(centralwidget);
        restockButton->setObjectName(QString::fromUtf8("restockButton"));
        restockButton->setGeometry(QRect(360, 190, 91, 21));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(360, 270, 91, 21));
        ReStock->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ReStock);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ReStock->setStatusBar(statusbar);

        retranslateUi(ReStock);

        QMetaObject::connectSlotsByName(ReStock);
    } // setupUi

    void retranslateUi(QMainWindow *ReStock)
    {
        ReStock->setWindowTitle(QApplication::translate("ReStock", "MainWindow", nullptr));
        label->setText(QApplication::translate("ReStock", "Restock amount", nullptr));
        restockButton->setText(QApplication::translate("ReStock", "Restock", nullptr));
        backButton->setText(QApplication::translate("ReStock", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReStock: public Ui_ReStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTOCK_H
