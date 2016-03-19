#include "bclasstest.h"

#include <core/bobject.h>

#include <typeindex>

BClassTest::BClassTest()
{

}

void BClassTest::constructFromInstance()
{
    // Tests to make sure we can construct a BClass with a BObject*
    BObject object;
    BClass bclass(object);
    QVERIFY(bclass.name());
}

void BClassTest::constructFromType()
{
    // Tests to make sure we can construct a BClass with a type like 'BObject'
    BClass bclass(typeid(BObject));
    QVERIFY(bclass.name());
}

class ClassA : public BObject
{
    B_OBJECT(ClassA)

public:
    ClassA()
    {
        m_class = BClass(*this);
    }
};

class ClassB : public BObject
{
    B_OBJECT(ClassB)

public:
    ClassB()
    {
        m_class = BClass(*this);
    }
};

void BClassTest::compareEqual()
{
    BObject* a0 = new ClassA;
    BObject* a1 = new ClassA;
    BObject* b0 = new ClassB;
    BObject* b1 = new ClassB;

    QVERIFY(a0->getClass() == a1->getClass());
    QVERIFY(b0->getClass() == b1->getClass());

    delete a0;
    delete a1;
    delete b0;
    delete b1;
}

void BClassTest::compareInequal()
{
    BObject* a0 = new ClassA;
    BObject* a1 = new ClassA;
    BObject* b0 = new ClassB;
    BObject* b1 = new ClassB;

    QVERIFY(a0->getClass() != b0->getClass());
    QVERIFY(a1->getClass() != b1->getClass());

    delete a0;
    delete a1;
    delete b0;
    delete b1;
}

void BClassTest::testName()
{
    BObject* a = new ClassA;
    BObject* b = new ClassB;

    QVERIFY(QString(a->getClass().name()).contains("ClassA"));
    QVERIFY(QString(b->getClass().name()).contains("ClassB"));

    delete a;
    delete b;
}

void BClassTest::getStaticClass()
{
    BObject object;
    BClass instanceClass = object.getClass();
    BClass staticClass = BObject::getStaticClass();

    QVERIFY(instanceClass == staticClass);
}

void BClassTest::getStaticClassForSubclass()
{
    ClassA a;
    BClass instanceClass = a.getClass();
    BClass staticClass = ClassA::getStaticClass();

    QVERIFY(instanceClass == staticClass);
}
