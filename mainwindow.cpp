#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore>
#include <QStringList>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("uText");
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

    ui->FileName->setText("Untittled");
    m_DirsList->setRootPath(path);
    ui->treeView->setModel(m_DirsList);
    ui->treeView->setRootIndex(m_DirsList->index(path));
    for (int i = 1; i < m_DirsList->columnCount(); ++i)
        ui->treeView->hideColumn(i);

    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(FileClicked(QModelIndex)));
    connect(ui->treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(FileDoubleClicked(QModelIndex)));
}

void MainWindow::on_textEdit_textChanged() {
    if (!m_changed) ui->FileName->setText(ui->FileName->text() + "*");
    m_changed = true;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (m_changed) checkSave();

    event->accept();
}

void MainWindow::on_actionNew_window_triggered() {
    MainWindow* newWindow = new MainWindow();
    newWindow->show();
}
