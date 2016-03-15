#include <QString>
#include <QtTest>

class GameObjectGameComponentTest : public QObject
{
    Q_OBJECT

public:
    GameObjectGameComponentTest();

private Q_SLOTS:
    void testCase1();
};

GameObjectGameComponentTest::GameObjectGameComponentTest()
{
}

void GameObjectGameComponentTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(GameObjectGameComponentTest)

#include "tst_gameobjectgamecomponenttest.moc"
