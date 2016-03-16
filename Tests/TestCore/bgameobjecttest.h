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
    void setParent();
    void hasParent();
    void gameObjectFamilyTree();

    void addAndRemoveChildren();
    void addRepeatChildren();
    void reassignChildren();
    void removeIllegalChildren();
};

#endif // BGAMEOBJECTTEST_H
