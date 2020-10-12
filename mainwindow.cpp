#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore>
#include <QStringList>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setTreeView(QDir::homePath());
    m_path = "";
    newFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTreeView(QString path) {
    QStringList splitList = path.split("/");

    ui->DirName->setText(path != QDir::rootPath() ?
                splitList.at(splitList.size() - 1) : path);
    m_DirsList->setRootPath(path);
    ui->treeView->setModel(m_DirsList);
    ui->treeView->setRootIndex(m_DirsList->index(path));
    for (int i = 1; i < m_DirsList->columnCount(); ++i)
        ui->treeView->hideColumn(i);
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(FileClicked(QModelIndex)));
}

void MainWindow::on_textEdit_textChanged() {
    m_changed = true;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    event->accept();
}


