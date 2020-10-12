#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QCloseEvent>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    void FileClicked(QModelIndex index);
    void FileDoubleClicked(QModelIndex index);
    void on_textEdit_textChanged();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionExplorer_triggered();
    void on_actionOpenFolder_triggered();
    void on_actionNew_window_triggered();
    void on_CloseFindLine_clicked();
    void on_FindUp_clicked();
    void on_FindDown_clicked();
    void on_ReplacAll_clicked();
    void on_Replace_clicked();
    void on_actionAdd_file_triggered();
    void on_actionAdd_folder_triggered();
    void on_actionRename_triggered();
    void on_actionDelete_triggered();
    void on_actionSettings_triggered();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *m_DirsList { new QFileSystemModel(this) };

    bool m_changed;
    bool m_openFile { false };
    bool m_isExplorerHide { false };
    QString m_path;
    QString m_fileName = "";
    QModelIndex m_modelIndex;
    QModelIndex m_dirModel;
    QModelIndex m_fileModel;

    void setTreeView(QString = "");
    void chooseDir();
    void newFile();
    void openFile();
    void saveFile(QString path);
    void saveFileAs();
    void checkSave();
    void showFind();
    void showReplace();
    void hideFind();
    void hideReplace();
    void renameFile();
    void renameFolder(QDir);
    // QWidget interface

protected:
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
