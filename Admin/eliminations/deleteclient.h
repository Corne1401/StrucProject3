#ifndef DELETECLIENT_H
#define DELETECLIENT_H

#include <QMainWindow>

namespace Ui {
class DeleteClient;
}

class DeleteClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteClient(QWidget *parent = nullptr);
    ~DeleteClient();

private:
    Ui::DeleteClient *ui;
};

#endif // DELETECLIENT_H
