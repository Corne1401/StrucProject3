/********************************************************************************
** Form generated from reading UI file 'deleteclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETECLIENT_H
#define UI_DELETECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteClient
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *clientID;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DeleteClient)
    {
        if (DeleteClient->objectName().isEmpty())
            DeleteClient->setObjectName(QString::fromUtf8("DeleteClient"));
        DeleteClient->resize(800, 600);
        centralwidget = new QWidget(DeleteClient);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(367, 180, 91, 21));
        clientID = new QLineEdit(centralwidget);
        clientID->setObjectName(QString::fromUtf8("clientID"));
        clientID->setGeometry(QRect(358, 110, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(390, 80, 47, 13));
        DeleteClient->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(DeleteClient);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DeleteClient->setStatusBar(statusbar);

        retranslateUi(DeleteClient);

        QMetaObject::connectSlotsByName(DeleteClient);
    } // setupUi

    void retranslateUi(QMainWindow *DeleteClient)
    {
        DeleteClient->setWindowTitle(QApplication::translate("DeleteClient", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("DeleteClient", "Delete", nullptr));
        label->setText(QApplication::translate("DeleteClient", "Client ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteClient: public Ui_DeleteClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETECLIENT_H
