/********************************************************************************
** Form generated from reading UI file 'newaisle.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWAISLE_H
#define UI_NEWAISLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newAisle
{
public:
    QWidget *centralwidget;
    QLineEdit *newCode;
    QLineEdit *newName;
    QLabel *label;
    QLabel *label_2;
    QPushButton *newAisleConfirm;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newAisle)
    {
        if (newAisle->objectName().isEmpty())
            newAisle->setObjectName(QString::fromUtf8("newAisle"));
        newAisle->resize(800, 600);
        centralwidget = new QWidget(newAisle);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        newCode = new QLineEdit(centralwidget);
        newCode->setObjectName(QString::fromUtf8("newCode"));
        newCode->setGeometry(QRect(332, 70, 131, 21));
        newName = new QLineEdit(centralwidget);
        newName->setObjectName(QString::fromUtf8("newName"));
        newName->setGeometry(QRect(332, 170, 131, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 40, 71, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 140, 81, 16));
        newAisleConfirm = new QPushButton(centralwidget);
        newAisleConfirm->setObjectName(QString::fromUtf8("newAisleConfirm"));
        newAisleConfirm->setGeometry(QRect(350, 270, 91, 21));
        newAisle->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(newAisle);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        newAisle->setStatusBar(statusbar);

        retranslateUi(newAisle);

        QMetaObject::connectSlotsByName(newAisle);
    } // setupUi

    void retranslateUi(QMainWindow *newAisle)
    {
        newAisle->setWindowTitle(QApplication::translate("newAisle", "MainWindow", nullptr));
        label->setText(QApplication::translate("newAisle", "New aisle code", nullptr));
        label_2->setText(QApplication::translate("newAisle", "New aisle name", nullptr));
        newAisleConfirm->setText(QApplication::translate("newAisle", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newAisle: public Ui_newAisle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWAISLE_H
