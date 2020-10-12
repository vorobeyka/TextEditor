#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore>
#include <QStringList>
#include <QDir>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("uText");
    this->setWindowIcon(QIcon(":/files/images/writing.png"));
    setTreeView(QDir::homePath());
    m_path = "";

    hideFind();
    hideReplace();
    newFile();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setTreeView(QString path) {
    QStringList splitList = path.split("/");

    ui->FileName->setText("Untittled");
    m_DirsList->setRootPath(path);
    m_dirModel = m_DirsList->index(path);
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

void MainWindow::showFind() {
    ui->FindDown->show();
    ui->FindUp->show();
    ui->FindLabel->show();
    ui->FindLine->show();
    ui->CloseFindLine->show();
    ui->FindLine->setText(ui->textEdit->textCursor().selectedText());
    ui->FindLine->setFocus();
}

void MainWindow::showReplace() {
    ui->ReplacAll->show();
    ui->Replace->show();
    ui->ReplaceLabel->show();
    ui->ReplaceLine->show();
}

void MainWindow::hideFind() {
    ui->FindDown->hide();
    ui->FindUp->hide();
    ui->FindLabel->hide();
    ui->FindLine->hide();
    ui->CloseFindLine->hide();
}

void MainWindow::hideReplace() {
    ui->ReplacAll->hide();
    ui->Replace->hide();
    ui->ReplaceLabel->hide();
    ui->ReplaceLine->hide();
}

void MainWindow::on_CloseFindLine_clicked() {
    hideFind();
    hideReplace();
}

void MainWindow::on_FindUp_clicked() {
    QString foundText = ui->FindLine->text();
    if (foundText.isEmpty()) return;

    bool value = ui->textEdit->find(foundText, QTextDocument::FindFlags() | QTextDocument::FindFlag::FindBackward);
    if (!value) QMessageBox::information(this, "Not found", "Not found: " + foundText);
    else ui->textEdit->setFocus();
}

void MainWindow::on_FindDown_clicked() {
    QString foundText = ui->FindLine->text();
    if (foundText.isEmpty()) return;

    bool value = ui->textEdit->find(foundText, QTextDocument::FindFlags());
    if (!value) QMessageBox::information(this, "Not found", "Not found: " + foundText);
    else ui->textEdit->setFocus();
}

void MainWindow::on_ReplacAll_clicked() {
    QString foundText = ui->FindLine->text();
    if (foundText.isEmpty()) return;

    QString text = ui->textEdit->toPlainText();
    text = text.replace(foundText, ui->ReplaceLine->text());
    ui->textEdit->setText(text);
    m_changed = true;
}

void MainWindow::on_Replace_clicked() {
    QString foundText = ui->FindLine->text();
    if (foundText.isEmpty()) return;

    bool value = ui->textEdit->find(foundText);
    if (!value) return;

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText(ui->ReplaceLine->text());
    m_changed = true;
}
