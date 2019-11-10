#ifndef MODIFICATIONS_H
#define MODIFICATIONS_H

#include <QMainWindow>

namespace Ui {
class Modifications;
}

class Modifications : public QMainWindow
{
    Q_OBJECT

public:
    explicit Modifications(QWidget *parent = nullptr);
    ~Modifications();

private:
    Ui::Modifications *ui;
};

#endif // MODIFICATIONS_H
