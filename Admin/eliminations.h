#ifndef ELIMINATIONS_H
#define ELIMINATIONS_H

#include <QMainWindow>

namespace Ui {
class eliminations;
}

class eliminations : public QMainWindow
{
    Q_OBJECT

public:
    explicit eliminations(QWidget *parent = nullptr);
    ~eliminations();

private:
    Ui::eliminations *ui;
};

#endif // ELIMINATIONS_H
