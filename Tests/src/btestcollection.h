#ifndef BTESTCOLLECTION_H
#define BTESTCOLLECTION_H

#include <qmap.h>
#include <qstring>
#include <qvector.h>

#include <btest.h>

class BTestCollection
{
public:
    BTestCollection();

    void addTest(const QString& moduleName, QObject testCase);

    void runAllTests() const;

private:
    QMap<QString, QVector<BTest> > m_modules;
};

#endif // BTESTCOLLECTION_H
