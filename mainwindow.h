#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./Xbox/stfspackage.h"
#include "./Xbox/gdfxpackage.h"
#include "./Xbox/Structures.h"
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    // Folder icon (used in the treeview)
    QIcon iFolder;
    // File icon (used in the treeview)
    QIcon iFile;
    // Sets the slots for the applications
    void SetSlots( void );
    void LoadGdfxPackage( void );
    void LoadFolderItems( Folder *f, QTreeWidgetItem *parent );

    StfsPackage *stfspackage;
    GdfxPackage *gdfxpackage;
public slots:
    void OpenDirectory( void );
    void Extract( void );
};

#endif // MAINWINDOW_H
