#include "ardim.h"
#include "ui_ardim.h"

Ardim::Ardim(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ardim)
{
    ui->setupUi(this);

    vim = new QProcess(this);
    QString vimpath = "/usr/bin/vim";
    QStringList vimargs;

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("TERM", "basic"); // Add an environment variable
    env.insert("PATH", "/usr/bin/");
    env.insert("COLUMNS", "10");
    vim->setProcessEnvironment(env);

    vim->start(vimpath, vimargs);
    //connect(vim, SIGNAL(readyReadStandardOutput()), SLOT(refreshTextbox()));
    connect(vim, SIGNAL(readyRead()), SLOT(refreshTextbox()));
    connect(vim, SIGNAL(finished(int)), SLOT(close()));
}

Ardim::~Ardim()
{
    vim->close();
    delete ui;
}

void Ardim::keyPressEvent(QKeyEvent * e) {
    //char buf[32];
    //sprintf(buf, "%d", e->text().toStdString().c_str()[0]);
    vim->write(e->text().toStdString().c_str());
}

void Ardim::refreshTextbox() {
    //ui->CodeBox->insertPlainText(vim->readAllStandardOutput());

    QByteArray chars = vim->readAll();
    for (int i=0; i<chars.length(); i++) {
        char buf[32];
        sprintf(buf, "%d\n", (int)chars[i]);
        ui->output->insertPlainText(buf);
    }

    ui->CodeBox->insertPlainText(chars);
}
