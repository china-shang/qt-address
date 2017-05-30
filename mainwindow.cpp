#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionopen_triggered()
{
}

void MainWindow::on_actionquit_triggered()
{
    QApplication::quit() ;
}

void MainWindow::on_actionnew_triggered()
{
    emit ui->address->addentry();

}
