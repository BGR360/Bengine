#include "btestcollection.h"

BTestCollection::BTestCollection() :
    numFailures(0)
{}

BTestCollection::~BTestCollection()
{
    // Delete all the tests
    for (int i = 0; i < tests.size(); i++)
    {
        delete tests[i];
    }
}

void BTestCollection::addTest(QObject* test)
{
    tests.push_back(test);
}

void BTestCollection::runAllTests(int argc, char** argv)
{
    for (int i = 0; i < tests.size(); i++)
    {
        numFailures += QTest::qExec(tests[i], argc, argv);
    }
    qDebug() << "Total Failures: " << numFailures;
}
