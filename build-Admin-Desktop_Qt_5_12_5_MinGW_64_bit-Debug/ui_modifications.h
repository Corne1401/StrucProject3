/********************************************************************************
** Form generated from reading UI file 'modifications.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICATIONS_H
#define UI_MODIFICATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Modifications
{
public:
    QWidget *centralwidget;
    QPushButton *modPrice;
    QPushButton *modtax;
    QPushButton *modProd;
    QPushButton *backButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Modifications)
    {
        if (Modifications->objectName().isEmpty())
            Modifications->setObjectName(QString::fromUtf8("Modifications"));
        Modifications->resize(800, 600);
        centralwidget = new QWidget(Modifications);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        modPrice = new QPushButton(centralwidget);
        modPrice->setObjectName(QString::fromUtf8("modPrice"));
        modPrice->setGeometry(QRect(360, 70, 80, 21));
        modtax = new QPushButton(centralwidget);
        modtax->setObjectName(QString::fromUtf8("modtax"));
        modtax->setGeometry(QRect(360, 160, 80, 21));
        modProd = new QPushButton(centralwidget);
        modProd->setObjectName(QString::fromUtf8("modProd"));
        modProd->setGeometry(QRect(360, 250, 80, 21));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(360, 330, 80, 21));
        Modifications->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Modifications);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Modifications->setStatusBar(statusbar);

        retranslateUi(Modifications);

        QMetaObject::connectSlotsByName(Modifications);
    } // setupUi

    void retranslateUi(QMainWindow *Modifications)
    {
        Modifications->setWindowTitle(QApplication::translate("Modifications", "MainWindow", nullptr));
        modPrice->setText(QApplication::translate("Modifications", "Modify price", nullptr));
        modtax->setText(QApplication::translate("Modifications", "Modify tax", nullptr));
        modProd->setText(QApplication::translate("Modifications", "Modify product", nullptr));
        backButton->setText(QApplication::translate("Modifications", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modifications: public Ui_Modifications {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICATIONS_H
