#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    uiKriteria = new kriteria(this);
    uiKriteria->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    uiSubkriteria = new subkriteria(this);
    uiSubkriteria->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    uiKecocokan = new kecocokan(this);
    uiKecocokan->show();
}

