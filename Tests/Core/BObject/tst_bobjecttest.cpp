#include <QString>
#include <QtTest>

class BObjectTest : public QObject
{
    Q_OBJECT

public:
    BObjectTest();

private Q_SLOTS:
    void testCase1();
};

BObjectTest::BObjectTest()
{
}

void BObjectTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(BObjectTest)

#include "tst_bobjecttest.moc"
