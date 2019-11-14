#ifndef GRAPHRESULTS_H
#define GRAPHRESULTS_H

#include <QMainWindow>

namespace Ui {
class GraphResults;
}

class GraphResults : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphResults(QWidget *parent = nullptr);
    ~GraphResults();

private:
    Ui::GraphResults *ui;
};

#endif // GRAPHRESULTS_H
