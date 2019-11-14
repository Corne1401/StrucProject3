#ifndef DELETEBRAND_H
#define DELETEBRAND_H

#include <QMainWindow>

namespace Ui {
class DeleteBrand;
}

class DeleteBrand : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteBrand(QWidget *parent = nullptr);
    ~DeleteBrand();

private slots:
    void on_deleteBrand_clicked();

private:
    Ui::DeleteBrand *ui;
};

#endif // DELETEBRAND_H
