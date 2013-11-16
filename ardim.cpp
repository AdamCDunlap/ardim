#include "ardim.h"
#include "ui_ardim.h"

Ardim::Ardim(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ardim)
{
    ui->setupUi(this);
}

Ardim::~Ardim()
{
    delete ui;
}
