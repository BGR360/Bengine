#include <QCoreApplication>

#include <tests_global.h>

#include "bgameobjecttest.h"

int main(int argc, char *argv[])
{
    int failures = 0;

    BGameObjectTest gameObjectTest;
    failures += QTest::qExec(&gameObjectTest, argc, argv);

    qDebug() << "Total failures: " << failures;

    return 0;
}
