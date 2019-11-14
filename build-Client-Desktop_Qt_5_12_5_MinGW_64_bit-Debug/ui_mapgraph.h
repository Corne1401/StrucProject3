/********************************************************************************
** Form generated from reading UI file 'mapgraph.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPGRAPH_H
#define UI_MAPGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapGraph
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MapGraph)
    {
        if (MapGraph->objectName().isEmpty())
            MapGraph->setObjectName(QString::fromUtf8("MapGraph"));
        MapGraph->resize(982, 654);
        centralwidget = new QWidget(MapGraph);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -30, 611, 591));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(620, 10, 55, 16));
        MapGraph->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MapGraph);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MapGraph->setStatusBar(statusbar);

        retranslateUi(MapGraph);

        QMetaObject::connectSlotsByName(MapGraph);
    } // setupUi

    void retranslateUi(QMainWindow *MapGraph)
    {
        MapGraph->setWindowTitle(QApplication::translate("MapGraph", "MainWindow", nullptr));
        label->setText(QApplication::translate("MapGraph", "<html><head/><body><p><img src=\":/image/Graph.png\"/></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("MapGraph", "Legend", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapGraph: public Ui_MapGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPGRAPH_H
