#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QCloseEvent>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include "finddialog.h"
#include "replacedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setTreeView(QString = "");
    void chooseDir();

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_as_triggered();
    void on_actionExit_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();
    void on_actionFind_triggered();
    void on_actionReplace_triggered();
    void on_actionSelect_All_triggered();
    void on_actionZoom_in_triggered();
    void on_actionZoom_out_triggered();
    void on_actionBold_triggered();
    void on_actionItalic_triggered();
    void on_actionUnderline_triggered();
    void on_actionStrike_triggered();
    void on_actionColor_triggered();
    void on_actionFont_triggered();
    void on_actionHelp_triggered();
    void on_actionAbout_triggered();
    void FileClicked(QModelIndex index);
    void FileDoubleClicked(QModelIndex index);
    void on_textEdit_textChanged();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();

    void on_actionExplorer_triggered();

    void on_actionOpenFolder_triggered();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *m_DirsList { new QFileSystemModel(this) };

    bool m_changed;
    bool m_openFile { false };
    bool m_isExplorerHide { false };
    QString m_path;
    QModelIndex m_modelIndex;

    void newFile();
    void openFile();
    void saveFile(QString path);
    void saveFileAs();
    void checkSave();

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
