#include "mainwindow.h"

#include <QApplication>
#include <QFile>

QString uploadStyles() {
    QFile file("style.css");
    QString res = "";

    file.open(QFile::ReadWrite);
    if ((res = file.readAll()) != "") {
        file.close();
        return res;
    }

    QFile styles(":/files/images/style.css");
    QTextStream stream(&file);
    styles.open(QFile::ReadOnly);
    res = styles.readAll();
    stream << res;
    file.close();
    styles.close();
    return res;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    QFile file("../utext/images/styles.css");
//    QFile file(":/files/images/style.css");
//    file.open(QFile::ReadOnly);
    a.setStyleSheet(uploadStyles());
//    file.close();

    MainWindow w(&a);
    w.show();
    return a.exec();
}
