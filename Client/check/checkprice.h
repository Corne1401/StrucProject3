#ifndef CHECKPRICE_H
#define CHECKPRICE_H

#include <QMainWindow>

namespace Ui {
class CheckPrice;
}

class CheckPrice : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckPrice(QWidget *parent = nullptr);
    ~CheckPrice();

private:
    Ui::CheckPrice *ui;
};

#endif // CHECKPRICE_H
