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
    FindDialog* dlg = new FindDialog(ui->textEdit->textCursor().selectedText(), this);
    if (!dlg->exec()) return;

    QTextDocument::FindFlags flags;
    if (dlg->caseSensitive()) flags = flags | QTextDocument::FindFlag::FindCaseSensitively;
    if (dlg->wholeWords()) flags = flags | QTextDocument::FindFlag::FindWholeWords;
    if (dlg->backwards()) flags = flags | QTextDocument::FindFlag::FindBackward;

    bool value = ui->textEdit->find(dlg->text(), flags);
    if (!value) QMessageBox::information(this, "Not found", "Not found: " + dlg->text());
}

void MainWindow::on_actionReplace_triggered() {
    ReplaceDialog* dlg = new ReplaceDialog(ui->textEdit->textCursor().selectedText(), this);
    if (!dlg->exec()) return;

    if (dlg->all()) {
        QString text = ui->textEdit->toPlainText();
        text = text.replace(dlg->text(), dlg->replaceText());
        ui->textEdit->setText(text);
    } else {
        bool value = ui->textEdit->find(dlg->text());
        if (!value) {
            QMessageBox::information(this, "Not found", "Not found: " + dlg->text());
            return;
        }
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.insertText(dlg->replaceText());
    }
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
    ui->textEdit->zoomIn(5);
}

void MainWindow::on_actionZoom_out_triggered() {
    ui->textEdit->zoomOut(5);
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
