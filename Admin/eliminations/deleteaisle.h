#ifndef DELETEAISLE_H
#define DELETEAISLE_H

#include <QMainWindow>

namespace Ui {
class deleteAisle;
}

class deleteAisle : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteAisle(QWidget *parent = nullptr);
    ~deleteAisle();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deleteAisle *ui;
};

#endif // DELETEAISLE_H
