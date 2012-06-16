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

    // Set the application slots
    SetSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetSlots( void )
{
    connect(ui->actionOpen_SVOD_Root_Director, SIGNAL(triggered()), this, SLOT(OpenDirectory()));
}

void MainWindow::OpenDirectory( void )
{
    QString s;
    int size = ui.fileSystemTree->selectedItems().size();
    if (size == 0)
        return;
    else if (size == 1 && ui.fileSystemTree->selectedItems().at(0)->text(2).left(6) != QString::fromAscii("Folder"))
    {
        s = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("Select Where to Save File"), ui.fileSystemTree->selectedItems().at(0)->text(0));
    }
    else
    {
        QFileDialog qfd;
        qfd.setFileMode(QFileDialog::Directory);
        qfd.setOption(QFileDialog::ShowDirsOnly);
        s = qfd.getExistingDirectory(this, QString::fromAscii("Select Directory to Save Files"));
    }
}
