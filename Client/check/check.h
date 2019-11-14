#ifndef CHECK_H
#define CHECK_H

#include <QMainWindow>

namespace Ui {
class Check;
}

class Check : public QMainWindow
{
    Q_OBJECT

public:
    explicit Check(QWidget *parent = nullptr);
    ~Check();

private:
    Ui::Check *ui;
};

#endif // CHECK_H
