#ifndef BCLASSTEST_H
#define BCLASSTEST_H

#include <tests_global.h>

class BClassTest : public QObject
{
    Q_OBJECT

public:
    BClassTest();

private slots:
    void construct();
    void compareEqual();
    void compareInequal();
    void testName();
};

#endif // BCLASSTEST_H
