#ifndef SHOWBRANDS_H
#define SHOWBRANDS_H

#include <QMainWindow>

namespace Ui {
class ShowBrands;
}

class ShowBrands : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowBrands(QWidget *parent = nullptr);
    ~ShowBrands();

private:
    Ui::ShowBrands *ui;
};

#endif // SHOWBRANDS_H
