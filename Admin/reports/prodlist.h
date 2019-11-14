#ifndef PRODLIST_H
#define PRODLIST_H

#include <QMainWindow>

namespace Ui {
class ProdList;
}

class ProdList : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProdList(QWidget *parent = nullptr);
    ~ProdList();

private slots:
    void on_generate_clicked();

private:
    Ui::ProdList *ui;
};

#endif // PRODLIST_H
