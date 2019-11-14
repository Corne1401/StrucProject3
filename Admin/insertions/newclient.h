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

private slots:
    void on_confirmNewClient_clicked();

private:
    Ui::newClient *ui;
};

#endif // NEWCLIENT_H
