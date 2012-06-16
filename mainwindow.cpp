#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set the icons.  the iX means iconX.  Not some sort of Apple reference.
    iFolder.addFile(QString::fromUtf8(":/File System Icons/iFolder"), QSize(), QIcon::Normal, QIcon::Off);
    iFile.addFile(QString::fromUtf8(":/File System Icons/iFile"), QSize(), QIcon::Normal, QIcon::Off);
}

MainWindow::~MainWindow()
{
    delete ui;
}
