/********************************************************************************
** Form generated from reading UI file 'newclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCLIENT_H
#define UI_NEWCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newClient
{
public:
    QWidget *centralwidget;
    QLineEdit *newId;
    QLineEdit *newPhone;
    QLineEdit *newClientCity;
    QLineEdit *newEmail;
    QLineEdit *newClientName;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *confirmNewClient;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newClient)
    {
        if (newClient->objectName().isEmpty())
            newClient->setObjectName(QString::fromUtf8("newClient"));
        newClient->resize(800, 600);
        centralwidget = new QWidget(newClient);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        newId = new QLineEdit(centralwidget);
        newId->setObjectName(QString::fromUtf8("newId"));
        newId->setGeometry(QRect(150, 70, 121, 21));
        newPhone = new QLineEdit(centralwidget);
        newPhone->setObjectName(QString::fromUtf8("newPhone"));
        newPhone->setGeometry(QRect(320, 230, 113, 21));
        newClientCity = new QLineEdit(centralwidget);
        newClientCity->setObjectName(QString::fromUtf8("newClientCity"));
        newClientCity->setGeometry(QRect(470, 150, 121, 21));
        newEmail = new QLineEdit(centralwidget);
        newEmail->setObjectName(QString::fromUtf8("newEmail"));
        newEmail->setGeometry(QRect(150, 150, 121, 21));
        newClientName = new QLineEdit(centralwidget);
        newClientName->setObjectName(QString::fromUtf8("newClientName"));
        newClientName->setGeometry(QRect(470, 70, 121, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 50, 47, 13));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 130, 47, 13));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(510, 50, 47, 13));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(500, 130, 47, 13));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(360, 210, 47, 13));
        confirmNewClient = new QPushButton(centralwidget);
        confirmNewClient->setObjectName(QString::fromUtf8("confirmNewClient"));
        confirmNewClient->setGeometry(QRect(329, 320, 91, 21));
        newClient->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(newClient);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        newClient->setStatusBar(statusbar);

        retranslateUi(newClient);

        QMetaObject::connectSlotsByName(newClient);
    } // setupUi

    void retranslateUi(QMainWindow *newClient)
    {
        newClient->setWindowTitle(QApplication::translate("newClient", "MainWindow", nullptr));
        label->setText(QApplication::translate("newClient", "New ID", nullptr));
        label_3->setText(QApplication::translate("newClient", "Email", nullptr));
        label_4->setText(QApplication::translate("newClient", "Name", nullptr));
        label_5->setText(QApplication::translate("newClient", "City code", nullptr));
        label_6->setText(QApplication::translate("newClient", "Phone", nullptr));
        confirmNewClient->setText(QApplication::translate("newClient", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newClient: public Ui_newClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCLIENT_H
