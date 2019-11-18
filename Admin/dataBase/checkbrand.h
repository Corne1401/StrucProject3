#ifndef CHECKBRAND_H
#define CHECKBRAND_H

#include <QMainWindow>

namespace Ui {
class CheckBrand;
}

class CheckBrand : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckBrand(QWidget *parent = nullptr);
    ~CheckBrand();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CheckBrand *ui;
};

#endif // CHECKBRAND_H
