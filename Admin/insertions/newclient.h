#ifndef NEWCLIENT_H
#define NEWCLIENT_H

#include <QMainWindow>

namespace Ui {
class newClient;
}

class newClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit newClient(QWidget *parent = nullptr);
    ~newClient();

private:
    Ui::newClient *ui;
};

#endif // NEWCLIENT_H
