#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QtCore>
#include <QInputDialog>
#include <fstream>

QString MainWindow::setCSSColor(QString color) {
    (void) color;
    QString res = "QMenuBar,QLabel,QTreeView,QDialog,QPushButton,QLineEdit,QMenu{background-color: #474747; color: " + color + ";}";
    res += "QTextEdit {background-color: #474747;color: #ecf0f1;}";
    res += "QToolBar {border: none;background-color: " + color + ";}";
    res += "QMenu {border: none;}";
    res += "QLineEdit {border: 1px solid " + color + ";}";
    return res;
}

void MainWindow::on_actionSettings_triggered() {
    SettingsDialog* dlg = new SettingsDialog(this);
    if (!dlg->exec()) return;
    if (dlg->Accepted) {
        QFile file("./style.css");

        if (!file.open(QIODevice::ReadWrite)) {
            QMessageBox::critical(this, "Error", file.errorString());
            return;
        }

        QTextStream stream(&file);
        stream << setCSSColor(dlg->color());
        m_app->setStyleSheet(file.readAll());
        file.close();
    }
}

void MainWindow::on_actionExplorer_triggered() {
    if (m_isExplorerHide) {
        ui->treeView->show();
        ui->toolBarActions->show();
        m_isExplorerHide = false;
    } else {
        ui->treeView->hide();
        ui->toolBarActions->hide();
        m_isExplorerHide = true;
    }
}

void MainWindow::on_actionAdd_file_triggered() {
    QString path = m_DirsList->filePath(m_dirModel);
    if (!QDir(path).exists()) return;

    QString fileName = QInputDialog::getText(this, "Input text", "File name: ");
    QFile file(path + "/" + fileName);
    if (file.open(QFile::ReadWrite | QFile::Text)) file.close();
}

void MainWindow::on_actionAdd_folder_triggered() {
    QString path = m_DirsList->filePath(m_dirModel) + "/";
    if (!QDir(path).exists()) return;

    QString dirName = QInputDialog::getText(this, "Input text", "Folder name: ");
    QDir dir(path);
    dir.mkdir(dirName);
}

void MainWindow::renameFile() {
    QFile file(m_DirsList->filePath(m_fileModel));
    if (!file.exists()) return;

    QString newName = QInputDialog::getText(this, "Rename", "New name: ");
    if (newName.isEmpty()) {
        file.close();
        return;
    }

    QString path = m_DirsList->filePath(m_dirModel) + "/";
    file.rename(path + newName);
    if (m_fileModel == m_modelIndex) {
        m_path = path + newName;
        m_fileName = newName;
        ui->FileName->setText(newName);
    }
    file.close();
    registerFileType();
}

void MainWindow::renameFolder(QDir dir) {
    QString newName = QInputDialog::getText(this, "Rename", "New name: ");
    if (newName.isEmpty()) return;

    QString path = m_DirsList->filePath(m_fileModel.parent()) + "/";
    dir.rename(dir.path(), path + newName);
}

void MainWindow::on_actionRename_triggered() {
    QDir dir(m_DirsList->filePath(m_fileModel));
    if (dir.exists()) renameFolder(dir);
    else renameFile();
    m_fileModel = m_DirsList->index(m_DirsList->rootPath());
    m_dirModel = m_DirsList->index(m_DirsList->rootPath());
}

void MainWindow::on_actionDelete_triggered() {
    QString path = m_DirsList->filePath(m_fileModel);
    QMessageBox msgBox;
    msgBox.setText("You wanna delete " + path + " ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    if (msgBox.exec() == QMessageBox::No) return;

    QFile file(path);
    QFileInfo fInfo(path);
    if (fInfo.isFile()) file.remove();
    else if (fInfo.isDir()) QDir(path).removeRecursively();
    m_fileModel = m_DirsList->index(m_DirsList->rootPath());
    m_dirModel = m_DirsList->index(m_DirsList->rootPath());
}

void MainWindow::on_actionNew_triggered() {
    checkSave();
    newFile();
}

void MainWindow::on_actionOpen_triggered() {
    checkSave();
    openFile();
}

void MainWindow::on_actionSave_triggered() {
    saveFile(m_path);
}

void MainWindow::on_actionSave_as_triggered() {
    saveFileAs();
}

void MainWindow::on_actionExit_triggered() {
    close();
}

void MainWindow::on_actionCopy_triggered() {
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered() {
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered() {
    ui->textEdit->paste();
}

void MainWindow::on_actionFind_triggered() {
    showFind();
}

void MainWindow::on_actionReplace_triggered() {
    showFind();
    showReplace();
}

void MainWindow::on_actionUndo_triggered() {
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered() {
    ui->textEdit->redo();
}

void MainWindow::on_actionSelect_All_triggered() {
    ui->textEdit->selectAll();
}

void MainWindow::on_actionZoom_in_triggered() {
    ui->textEdit->zoomIn(2);
}

void MainWindow::on_actionZoom_out_triggered() {
    ui->textEdit->zoomOut(2);
}

void MainWindow::on_actionBold_triggered() {
    QFont font = ui->textEdit->currentFont();
    font.bold() ? font.setBold(false) : font.setBold(true);
    ui->textEdit->setCurrentFont(font);
    m_changed = true;
}

void MainWindow::on_actionItalic_triggered() {
    QFont font = ui->textEdit->currentFont();
    font.italic() ? font.setItalic(false) : font.setItalic(true);
    ui->textEdit->setCurrentFont(font);
    m_changed = true;
}

void MainWindow::on_actionUnderline_triggered() {
    QFont font = ui->textEdit->currentFont();
    font.underline() ? font.setUnderline(false) : font.setUnderline(true);
    ui->textEdit->setCurrentFont(font);
    m_changed = true;
}

void MainWindow::on_actionStrike_triggered() {
    QFont font = ui->textEdit->currentFont();
    font.strikeOut() ? font.setStrikeOut(false) : font.setStrikeOut(true);
    ui->textEdit->setCurrentFont(font);
    m_changed = true;
}

void MainWindow::on_actionColor_triggered() {
    QColor current = ui->textEdit->currentCharFormat().foreground().color();
    QColor color = QColorDialog::getColor(current, this, "Color selector");
    ui->textEdit->setTextColor(color);
    m_changed = true;
}

void MainWindow::on_actionFont_triggered() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, ui->textEdit->currentFont(), this, "Choose a font");
    if (!ok) return;

    ui->textEdit->setCurrentFont(font);
    m_changed = true;
}
