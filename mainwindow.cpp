#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>

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

void MainWindow::on_actionNew_triggered()
{
    QMessageBox::information(this,tr("新建"),tr("新建什么呢"),QMessageBox::Ok | QMessageBox::Cancel);
}

void MainWindow::on_actionSave_triggered()
{
    QMessageBox::information(this,tr("保存"),tr("保存到哪里"),QMessageBox::Ok | QMessageBox::Cancel);
}
