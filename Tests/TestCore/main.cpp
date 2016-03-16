#include <QCoreApplication>

#include <tests_global.h>

#include "bclasstest.h"
#include "bgameobjecttest.h"

int main(int argc, char *argv[])
{
    int failures = 0;

    BClassTest classTest;
    failures += QTest::qExec(&classTest, argc, argv);

    BGameObjectTest gameObjectTest;
    failures += QTest::qExec(&gameObjectTest, argc, argv);

    qDebug() << "Total failures: " << failures;

    return 0;
}
