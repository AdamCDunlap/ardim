#ifndef ARDIM_H
#define ARDIM_H

#include <QMainWindow>

namespace Ui {
class Ardim;
}

class Ardim : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ardim(QWidget *parent = 0);
    ~Ardim();

private:
    Ui::Ardim *ui;
};

#endif // ARDIM_H
