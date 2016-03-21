#ifndef BASSETMANAGERTEST_H
#define BASSETMANAGERTEST_H

#include <tests_global.h>

class BAssetManagerTest : public QObject
{
    Q_OBJECT

public:
    BAssetManagerTest();

private slots:
    void automaticConvertStringToDir();
};

#endif // BASSETMANAGERTEST_H
