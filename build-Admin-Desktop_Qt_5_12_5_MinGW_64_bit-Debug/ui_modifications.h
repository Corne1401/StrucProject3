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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *backButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Modifications)
    {
        if (Modifications->objectName().isEmpty())
            Modifications->setObjectName(QString::fromUtf8("Modifications"));
        Modifications->resize(800, 600);
        centralwidget = new QWidget(Modifications);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 70, 80, 21));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 160, 80, 21));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 250, 80, 21));
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
        pushButton->setText(QApplication::translate("Modifications", "Modify price", nullptr));
        pushButton_2->setText(QApplication::translate("Modifications", "Modify tax", nullptr));
        pushButton_3->setText(QApplication::translate("Modifications", "Modify product", nullptr));
        backButton->setText(QApplication::translate("Modifications", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modifications: public Ui_Modifications {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICATIONS_H
