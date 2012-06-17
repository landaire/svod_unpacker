#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "Xbox/IO/xFileStream.h"
#include "Xbox/xexception.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //stfspackage = NULL;
    gdfxpackage = NULL;
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

void MainWindow::LoadGdfxPackage( void )
{
    Folder *RootDirectory = gdfxpackage->RootDirectory;
    for (int i = 0; i < RootDirectory->Folders.size(); i++)// fuck apple for this bullshit for ( Folder *f : RootDirectory->Folders )
    {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        LoadFolderItems(RootDirectory->Folders[i], item);
    }
}

void MainWindow::LoadFolderItems(Folder *f, QTreeWidgetItem *parent)
{
    parent->setText(0, QString::fromLocal8Bit(f->Entry.FileName.c_str()));
    parent->setText(1, QString::fromLocal8Bit("Folder"));
    parent->setText(2, QString("0x%1").arg(f->Entry.Offset, 0, 16));
    parent->setText(3, QString("0x%1").arg(f->Entry.Length, 0, 16));
    for (int i = 0; i < f->Folders.size(); i++)// for (Folder *folder : f->Folders)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(parent);
        LoadFolderItems(f->Folders[i], item);
    }
    // Create the file items as well
    for (int i = 0; i < f->Files.size(); i++)// for (Dirent file : f->Files)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(parent);
        item->setText(0, QString::fromLocal8Bit(f->Files[i].FileName.c_str()));
        item->setText(1, QString::fromLocal8Bit("File"));
        item->setText(2, QString("0x%1").arg(f->Files[i].Offset, 0, 16));
        item->setText(3, QString("0x%1").arg(f->Files[i].Length, 0, 16));
    }
}

void MainWindow::OpenDirectory( void )
{
    // This string will hold the path returned from the QFileDialog
    QString svodpath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("Open SVOD Container"));
    if (svodpath == "")
        return;
    QString datapath;
    // Use an OpenFolderDialog
    QFileDialog qfd;
    qfd.setFileMode(QFileDialog::Directory);
    qfd.setOption(QFileDialog::ShowDirsOnly);
    datapath = qfd.getExistingDirectory(this, QString::fromAscii("Open Data File Directory"));
    if (datapath == "")
        return;

    Streams::xFileStream *stream = new Streams::xFileStream(svodpath.toLocal8Bit().data(), Streams::Open);
    stfspackage = new StfsPackage(stream);
    std::vector<std::string> DataPaths;
    for (int i = 0; i < 1000; i++)
    {
        std::ostringstream stringStream;
        stringStream << datapath.toLocal8Bit().data();
        stringStream << "/Data";
        if (i < 10)
            stringStream << "000" << i;
        else if (i < 100)
            stringStream << "00" << i;
        else if (i < 1000)
            stringStream << "0" << i;
        else
            stringStream << i;
        try
        {
            Streams::xFileStream fs(stringStream.str(), Streams::Open);
            fs.Close();
            DataPaths.push_back(stringStream.str());
        }
        catch(xException& e)
        {
            break;
        }
    }
    gdfxpackage = new GdfxPackage(DataPaths, stfspackage);
    LoadGdfxPackage();
}

void MainWindow::Extract( void )
{
    // This string will hold the path returned from the QFileDialog
    QString path;
    // Get the number of selected items
    int size = ui->treeWidget->selectedItems().size();
    if (size == 0)
        return;
    // If the size is 1 and the dirent type is not a folder (file)
    else if (size == 1 && ui->treeWidget->selectedItems().at(0)->text(1).left(6) != QString::fromAscii("Folder"))
    {
        // Use a SaveFileDialog
        path = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("Select Where to Save File"), ui->treeWidget->selectedItems().at(0)->text(0));
    }
    else
    {
        // Use an OpenFolderDialog
        QFileDialog qfd;
        qfd.setFileMode(QFileDialog::Directory);
        qfd.setOption(QFileDialog::ShowDirsOnly);
        path = qfd.getExistingDirectory(this, QString::fromAscii("Select Directory to Save Files"));
    }
}
