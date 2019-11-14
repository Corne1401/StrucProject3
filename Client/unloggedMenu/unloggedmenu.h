#ifndef UNLOGGEDMENU_H
#define UNLOGGEDMENU_H

#include <QMainWindow>

namespace Ui {
class UnloggedMenu;
}

class UnloggedMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit UnloggedMenu(QWidget *parent = nullptr);
    ~UnloggedMenu();

private:
    Ui::UnloggedMenu *ui;
};

#endif // UNLOGGEDMENU_H
