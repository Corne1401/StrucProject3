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
    ~Menu();

private slots:
    void on_Reports_2_clicked();

    void on_Reports_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
