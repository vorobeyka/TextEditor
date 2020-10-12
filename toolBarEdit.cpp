#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QtCore>

void MainWindow::on_actionExplorer_triggered() {
    if (m_isExplorerHide) {
        ui->treeView->show();
        m_isExplorerHide = false;
    } else {
        ui->treeView->hide();
        m_isExplorerHide = true;
    }
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
    ui->textEdit->font().bold();
}

void MainWindow::on_actionItalic_triggered() {

}

void MainWindow::on_actionUnderline_triggered() {

}

void MainWindow::on_actionStrike_triggered() {

}

void MainWindow::on_actionColor_triggered() {

}

void MainWindow::on_actionFont_triggered() {

}

void MainWindow::on_actionHelp_triggered() {

}

void MainWindow::on_actionAbout_triggered() {

}
