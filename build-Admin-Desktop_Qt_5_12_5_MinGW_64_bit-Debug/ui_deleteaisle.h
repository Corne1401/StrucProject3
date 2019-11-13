/********************************************************************************
** Form generated from reading UI file 'deleteaisle.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEAISLE_H
#define UI_DELETEAISLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteAisle
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *aisleToDelete;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *deleteAisle)
    {
        if (deleteAisle->objectName().isEmpty())
            deleteAisle->setObjectName(QString::fromUtf8("deleteAisle"));
        deleteAisle->resize(800, 600);
        centralwidget = new QWidget(deleteAisle);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 50, 71, 16));
        aisleToDelete = new QLineEdit(centralwidget);
        aisleToDelete->setObjectName(QString::fromUtf8("aisleToDelete"));
        aisleToDelete->setGeometry(QRect(320, 110, 131, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 180, 91, 21));
        deleteAisle->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(deleteAisle);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        deleteAisle->setStatusBar(statusbar);

        retranslateUi(deleteAisle);

        QMetaObject::connectSlotsByName(deleteAisle);
    } // setupUi

    void retranslateUi(QMainWindow *deleteAisle)
    {
        deleteAisle->setWindowTitle(QApplication::translate("deleteAisle", "MainWindow", nullptr));
        label->setText(QApplication::translate("deleteAisle", "Aisle code", nullptr));
        pushButton->setText(QApplication::translate("deleteAisle", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteAisle: public Ui_deleteAisle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEAISLE_H
