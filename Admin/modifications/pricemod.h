#ifndef PRICEMOD_H
#define PRICEMOD_H

#include <QMainWindow>

namespace Ui {
class priceMod;
}

class priceMod : public QMainWindow
{
    Q_OBJECT

public:
    explicit priceMod(QWidget *parent = nullptr);
    ~priceMod();

private slots:
    void on_modPriceConfirm_clicked();

private:
    Ui::priceMod *ui;
};

#endif // PRICEMOD_H
