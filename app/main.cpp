#include "./src/mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QtCore>

QString uploadStyles() {
    QFile file(QCoreApplication::applicationDirPath() + "/" + "style.css");
    QString res = "";

    file.open(QFile::ReadWrite);
    if ((res = file.readAll()) != "") {
        file.close();
        return res;
    }

    QFile styles(":/files/settings/style.css");
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
    a.setStyleSheet(uploadStyles());

    MainWindow w(&a);
    w.show();
    return a.exec();
}
