#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QFile file(":/files/images/style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());

    MainWindow w;
    w.show();
    return a.exec();
}
