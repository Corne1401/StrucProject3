/********************************************************************************
** Form generated from reading UI file 'popup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP_H
#define UI_POPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopUp
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *yesBtn;
    QPushButton *noBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PopUp)
    {
        if (PopUp->objectName().isEmpty())
            PopUp->setObjectName(QString::fromUtf8("PopUp"));
        PopUp->resize(800, 600);
        centralwidget = new QWidget(PopUp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 120, 121, 16));
        yesBtn = new QPushButton(centralwidget);
        yesBtn->setObjectName(QString::fromUtf8("yesBtn"));
        yesBtn->setGeometry(QRect(210, 250, 80, 25));
        noBtn = new QPushButton(centralwidget);
        noBtn->setObjectName(QString::fromUtf8("noBtn"));
        noBtn->setGeometry(QRect(500, 250, 80, 25));
        PopUp->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(PopUp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PopUp->setStatusBar(statusbar);

        retranslateUi(PopUp);

        QMetaObject::connectSlotsByName(PopUp);
    } // setupUi

    void retranslateUi(QMainWindow *PopUp)
    {
        PopUp->setWindowTitle(QApplication::translate("PopUp", "MainWindow", nullptr));
        label->setText(QApplication::translate("PopUp", "Continue shopping?", nullptr));
        yesBtn->setText(QApplication::translate("PopUp", "Yes", nullptr));
        noBtn->setText(QApplication::translate("PopUp", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PopUp: public Ui_PopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP_H
