#include <btestcollection.h>

#include "bclasstest.h"
#include "bdebugtest.h"
#include "bgameobjecttest.h"

int main(int argc, char *argv[])
{
    BTestCollection tests;
    tests.addTest(new BClassTest);
    tests.addTest(new BDebugTest);
    tests.addTest(new BGameObjectTest);

    tests.runAllTests(argc, argv);

    return 0;
}
