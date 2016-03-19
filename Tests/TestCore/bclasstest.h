#ifndef BCLASSTEST_H
#define BCLASSTEST_H

#include <tests_global.h>

class BClassTest : public QObject
{
    Q_OBJECT

public:
    BClassTest();

private slots:
    void constructFromInstance();
    void constructFromTypeIndex();
    void compareEqual();
    void compareInequal();
    void testName();
    void getStaticClass();
    void getStaticClassForSubclass();
};

#endif // BCLASSTEST_H
