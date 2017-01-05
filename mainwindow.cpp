#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <qfiledialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowState(Qt::WindowMaximized);
    ui->setupUi(this);

    QAction* pActionExit = new QAction(tr("退出"),this);

    ui->menuBar->addAction(pActionExit);

    connect(pActionExit,SIGNAL(triggered()),this, SLOT(on_exit()));
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

void MainWindow::on_exit()
{

     QMessageBox::StandardButton sb = QMessageBox::information(this,tr("退出"),tr("是否退出程序"),QMessageBox::Ok | QMessageBox::Cancel);
     if(sb == QMessageBox::Ok){
        this->close();
     } else {

     }
}

void MainWindow::on_actionOpen_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Image"),".", tr("Image Files(*.jpg *.png)"));
    if(path.length() == 0) {
           QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    }else {
           QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);
    }

}
