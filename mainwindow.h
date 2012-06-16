#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
public slots:
    void OpenDirectory( void );
};

#endif // MAINWINDOW_H
