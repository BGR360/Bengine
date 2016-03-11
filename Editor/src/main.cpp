#include "mainwindow.h"
#include <QApplication>

#include "bengine.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString version = Bengine::getVersion();
    w.setWindowTitle(QString("Bengine version %1").arg(version));
    w.show();

    return a.exec();
}
