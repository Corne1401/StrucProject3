/********************************************************************************
** Form generated from reading UI file 'eliminations.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELIMINATIONS_H
#define UI_ELIMINATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eliminations
{
public:
    QWidget *centralwidget;
    QPushButton *deleteAisleButton;
    QPushButton *deleteBrandButton;
    QPushButton *deleteProductButton;
    QPushButton *deleteClientButton;
    QPushButton *deleteBack;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *eliminations)
    {
        if (eliminations->objectName().isEmpty())
            eliminations->setObjectName(QString::fromUtf8("eliminations"));
        eliminations->resize(800, 600);
        centralwidget = new QWidget(eliminations);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        deleteAisleButton = new QPushButton(centralwidget);
        deleteAisleButton->setObjectName(QString::fromUtf8("deleteAisleButton"));
        deleteAisleButton->setGeometry(QRect(180, 80, 80, 21));
        deleteBrandButton = new QPushButton(centralwidget);
        deleteBrandButton->setObjectName(QString::fromUtf8("deleteBrandButton"));
        deleteBrandButton->setGeometry(QRect(520, 80, 80, 21));
        deleteProductButton = new QPushButton(centralwidget);
        deleteProductButton->setObjectName(QString::fromUtf8("deleteProductButton"));
        deleteProductButton->setGeometry(QRect(180, 190, 80, 21));
        deleteClientButton = new QPushButton(centralwidget);
        deleteClientButton->setObjectName(QString::fromUtf8("deleteClientButton"));
        deleteClientButton->setGeometry(QRect(520, 200, 80, 21));
        deleteBack = new QPushButton(centralwidget);
        deleteBack->setObjectName(QString::fromUtf8("deleteBack"));
        deleteBack->setGeometry(QRect(350, 290, 80, 21));
        eliminations->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(eliminations);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        eliminations->setStatusBar(statusbar);

        retranslateUi(eliminations);

        QMetaObject::connectSlotsByName(eliminations);
    } // setupUi

    void retranslateUi(QMainWindow *eliminations)
    {
        eliminations->setWindowTitle(QApplication::translate("eliminations", "MainWindow", nullptr));
        deleteAisleButton->setText(QApplication::translate("eliminations", "Delete aisle", nullptr));
        deleteBrandButton->setText(QApplication::translate("eliminations", "Delete brand", nullptr));
        deleteProductButton->setText(QApplication::translate("eliminations", "Delete product", nullptr));
        deleteClientButton->setText(QApplication::translate("eliminations", "Delete client", nullptr));
        deleteBack->setText(QApplication::translate("eliminations", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class eliminations: public Ui_eliminations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELIMINATIONS_H
