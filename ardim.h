#ifndef ARDIM_H
#define ARDIM_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
    class Ardim;
}

class Ardim : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ardim(QWidget *parent = 0);
    ~Ardim();

    void keyPressEvent(QKeyEvent*);

public slots:
    void refreshTextbox();

private:
    Ui::Ardim *ui;

    QProcess *vim;
};

#endif // ARDIM_H
