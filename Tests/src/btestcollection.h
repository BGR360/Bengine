#ifndef BTESTCOLLECTION_H
#define BTESTCOLLECTION_H

#include <tests_global.h>
#include <QVector>

class BTestCollection
{
public:
    BTestCollection();
    ~BTestCollection();

    void addTest(QObject* test);
    void runAllTests(int argc, char** argv);

private:
    int numFailures;
    QVector<QObject*> tests;
};

#endif // BTESTCOLLECTION_H
