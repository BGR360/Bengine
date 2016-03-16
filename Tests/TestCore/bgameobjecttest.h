#ifndef BGAMEOBJECTTEST_H
#define BGAMEOBJECTTEST_H

#include <tests_global.h>

class BGameObjectTest : public QObject
{
    Q_OBJECT

public:
    BGameObjectTest();

private slots:
    void construct();
    void numComponents();
    void addAndRemoveComponents();
    void addRepeatComponents();
    void addComponentsToOtherObject();
    void removeComponents();
    void hasParent();
    void gameObjectTree();
};

#endif // BGAMEOBJECTTEST_H
