#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    comand = "Shutdown";
    ui->comboBox->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return ||
            event->key() == Qt::Key_Enter)
    {
        ui->pushButtonOk->click();
    }
    else if (event->key() == Qt::Key_Escape)
    {
        ui->pushButtonCancel->click();
    }
}

void MainWindow::on_pushButtonOk_clicked()
{
    if (comand == "Shutdown")
    {
        system(qPrintable("shutdown now"));
    }
    else if (comand == "Restart")
    {
        system(qPrintable("shutdown --reboot now"));
    }

    this->close();
}

void MainWindow::on_pushButtonCancel_clicked()
{
    this->close();
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    comand = arg1;
}

