#ifndef BDEBUGTEST_H
#define BDEBUGTEST_H

#include <tests_global.h>

class BDebugTest : public QObject
{
    Q_OBJECT

public:
    BDebugTest();

private slots:
    void testCase1();
};

#endif // BDEBUGTEST_H
