#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QtCore>

void MainWindow::FileClicked(QModelIndex index) {
    qDebug() << index.column();
}
