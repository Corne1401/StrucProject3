#ifndef BRANDLIST_H
#define BRANDLIST_H

#include <QMainWindow>

namespace Ui {
class BrandList;
}

class BrandList : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrandList(QWidget *parent = nullptr);
    ~BrandList();

private slots:
    void on_generate_clicked();

private:
    Ui::BrandList *ui;
};

#endif // BRANDLIST_H
