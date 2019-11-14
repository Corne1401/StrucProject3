/********************************************************************************
** Form generated from reading UI file 'graphresults.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHRESULTS_H
#define UI_GRAPHRESULTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphResults
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *graphResults)
    {
        if (graphResults->objectName().isEmpty())
            graphResults->setObjectName(QString::fromUtf8("graphResults"));
        graphResults->resize(800, 600);
        centralwidget = new QWidget(graphResults);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 10, 751, 531));
        textEdit->setReadOnly(true);
        graphResults->setCentralWidget(centralwidget);
        menubar = new QMenuBar(graphResults);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        graphResults->setMenuBar(menubar);
        statusbar = new QStatusBar(graphResults);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        graphResults->setStatusBar(statusbar);

        retranslateUi(graphResults);

        QMetaObject::connectSlotsByName(graphResults);
    } // setupUi

    void retranslateUi(QMainWindow *graphResults)
    {
        graphResults->setWindowTitle(QApplication::translate("graphResults", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphResults: public Ui_graphResults {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHRESULTS_H
