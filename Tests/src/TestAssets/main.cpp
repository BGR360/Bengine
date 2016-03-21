#include <btestcollection.h>

#include "bassetmanagertest.h"

int main(int argc, char *argv[])
{
    BTestCollection tests;
    tests.addTest(new BAssetManagerTest);

    tests.runAllTests(argc, argv);

    return 0;
}
