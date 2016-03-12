#include "btestcollection.h"

#include <QTest>

BTestCollection::BTestCollection() {}

void BTestCollection::addTest(const QString& moduleName, QObject testCase)
{
    if (!m_modules.contains(moduleName))
    {
        m_modules.insert(moduleName, QVector<QObject>());
    }

    m_modules[moduleName].push_back(testCase);
}

void BTestCollection::runAllTests() const
{
    QMap<QString, QVector<QObject
}
