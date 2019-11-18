#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "reports.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    void on_pushButton_clicked();
    ~Menu();

private slots:


    void on_menuBack_clicked();

    void on_modifyButton_clicked();

    void on_reportButton_clicked();

    void on_checkButton_clicked();

    void on_billingButton_clicked();

    void on_restockButton_clicked();

    void on_insertButton_clicked();

    void on_deleteButton_clicked();

    void on_chainReports_clicked();

    void on_checkInventory_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
