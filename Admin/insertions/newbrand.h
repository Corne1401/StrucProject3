#ifndef NEWBRAND_H
#define NEWBRAND_H

#include <QMainWindow>

namespace Ui {
class newBrand;
}

class newBrand : public QMainWindow
{
    Q_OBJECT

public:
    explicit newBrand(QWidget *parent = nullptr);
    ~newBrand();

private:
    Ui::newBrand *ui;
};

#endif // NEWBRAND_H
