#include <QCoreApplication>
#include <qdebug.h>

#include "bengine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Bengine version " << Bengine::getVersion();

    return a.exec();
}
