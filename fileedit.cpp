#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QtCore>

void MainWindow::FileClicked(QModelIndex index) {
    qDebug() << "clicked - " << m_DirsList->filePath(index);
}

void MainWindow::FileDoubleClicked(QModelIndex index) {
    m_openFile = true;
    m_modelIndex = index;
    openFile();
    m_openFile = false;
}

void MainWindow::newFile() {
    ui->textEdit->clear();
    ui->statusbar->showMessage("New File");
    m_path = "";
    m_changed = false;
}

void MainWindow::openFile() {
    QString path = m_openFile ?
                m_DirsList->filePath(m_modelIndex) : QFileDialog::getOpenFileName(this, "Open File");
    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->textEdit->setText(stream.readAll());
    file.close();

    m_path = path;
    ui->statusbar->showMessage(m_path);
    m_changed = false;
}

void MainWindow::on_actionOpenFolder_triggered(){
    QString path = QFileDialog::getExistingDirectory(this, "Open Folder");

    if (path.isEmpty()) return;

    QDir dir(path);
    if (!dir.exists()) {
        QMessageBox::critical(this, "Error", "Error to open folder");
        return;
    }

    setTreeView(path);
}

void MainWindow::saveFile(QString path) {
    if (path.isEmpty()) {
        saveFileAs();
        return;
    }

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", file.errorString());
        ui->statusbar->showMessage("Error could not save file!");
        saveFileAs();
        return;
    }

    QTextStream stream(&file);
    stream << ui->textEdit->toPlainText();
    file.close();

    m_path = path;
    ui->statusbar->showMessage(m_path);
    m_changed = false;
}

void MainWindow::saveFileAs() {
    QString path = QFileDialog::getSaveFileName(this, "Save file");
    if (path.isEmpty()) return;
    saveFile(path);
}

void MainWindow::checkSave() {
    if (!m_changed) return;

    QMessageBox::StandardButton value = QMessageBox::question(this, "Save File?", "You have un-saved changes. Would you like to save them?");

    if (value != QMessageBox::StandardButton::Yes) return;

    if (m_path.isEmpty()) {
        saveFileAs();
    } else {
        saveFile(m_path);
    }
}
