#ifndef MODTAX_H
#define MODTAX_H

#include <QMainWindow>

namespace Ui {
class ModTax;
}

class ModTax : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModTax(QWidget *parent = nullptr);
    ~ModTax();

private slots:
    void on_confirmNewTax_clicked();

private:
    Ui::ModTax *ui;
};

#endif // MODTAX_H
