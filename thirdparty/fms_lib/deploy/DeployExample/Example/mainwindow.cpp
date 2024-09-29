#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QThread>
#include "fmsapi.h"

#include <chrono>
#include <vector>
#include <QElapsedTimer>

using namespace std;
using namespace std::chrono;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(FmsManager::Instance(), &FmsManager::sigResponseResult, this, &MainWindow::onResponseResult);
    ui->textEdit->append("ENABLE");

//    QThread::sleep(3);
    processCommand("ENABLE");
    ui->leCommand->setText("MOVE#ABS0,0,0.3,0,0,0");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onResponseResult(QString responseStr)
{
    std::cout << responseStr.toStdString() << std::endl;
    ui->textEdit->append(responseStr);
}

void MainWindow::on_pbEnable_clicked()
{
    processCommand("ENABLE");
}

void MainWindow::on_pbMultiSend_clicked()
{
    QString cmd = ui->leCommand->text().trimmed();
    int quantity = ui->leQuantity->text().toInt();

    auto start = high_resolution_clock::now();
    QElapsedTimer timer;
    timer.start();
    int framerate = 500;
    double timeout = 1000.0/framerate;
    double realTimeInMilliSeconds = 0;
    double elapseTimeinMilliSeconds = 0;
    int counter = 0;
    while (counter < quantity)
    {
        elapseTimeinMilliSeconds = timer.elapsed();

        if (elapseTimeinMilliSeconds < realTimeInMilliSeconds)
        {
            QThread::msleep(1);
            continue;
        }

        processCommand(cmd);

        realTimeInMilliSeconds += timeout;
        counter ++;
    }

//    Get ending timepoint
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count()/1000.0 << " milliseconds" << endl;
}
