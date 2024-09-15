#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fmsapi.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FmsManager::Instance()->initialize();
    connect(FmsManager::Instance(), &FmsManager::sigResponseResult, this, &MainWindow::onResponseResult);
    processCommand("ENABLE");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onResponseResult(QString responseStr)
{

}
