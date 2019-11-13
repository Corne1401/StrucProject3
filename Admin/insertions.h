#ifndef INSERTIONS_H
#define INSERTIONS_H

#include <QMainWindow>

namespace Ui {
class insertions;
}

class insertions : public QMainWindow
{
    Q_OBJECT

public:
    explicit insertions(QWidget *parent = nullptr);
    ~insertions();

private slots:
    void on_insertBack_clicked();

private:
    Ui::insertions *ui;
};

#endif // INSERTIONS_H
