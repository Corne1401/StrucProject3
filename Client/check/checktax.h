#ifndef CHECKTAX_H
#define CHECKTAX_H

#include <QMainWindow>

namespace Ui {
class CheckTax;
}

class CheckTax : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckTax(QWidget *parent = nullptr);
    ~CheckTax();

private:
    Ui::CheckTax *ui;
};

#endif // CHECKTAX_H
