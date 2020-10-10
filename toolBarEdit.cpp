#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QtCore>

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

}

void MainWindow::on_actionCut_triggered() {

}

void MainWindow::on_actionPaste_triggered() {

}

void MainWindow::on_actionFind_triggered() {

}

void MainWindow::on_actionReplace_triggered() {

}

void MainWindow::on_actionSelect_All_triggered() {

}

void MainWindow::on_actionZoom_in_triggered() {

}

void MainWindow::on_actionZoom_out_triggered() {

}

void MainWindow::on_actionBold_triggered() {

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
