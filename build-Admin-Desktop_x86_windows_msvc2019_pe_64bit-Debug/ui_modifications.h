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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Modifications
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Modifications)
    {
        if (Modifications->objectName().isEmpty())
            Modifications->setObjectName(QString::fromUtf8("Modifications"));
        Modifications->resize(800, 600);
        centralwidget = new QWidget(Modifications);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
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
    } // retranslateUi

};

namespace Ui {
    class Modifications: public Ui_Modifications {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICATIONS_H
