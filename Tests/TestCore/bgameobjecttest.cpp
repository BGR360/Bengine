#include "bgameobjecttest.h"

#include <core/bgameobject.h>
#include <core/bgamecomponent.h>

BGameObjectTest::BGameObjectTest()
{

}

void BGameObjectTest::construct()
{
    // Tests to make sure we can properly construct a BGameObject
    BGameObject gameObject;
    QCOMPARE(gameObject.hasParent(), false);
    QCOMPARE(gameObject.numComponents(), 0);
    BGameObject* expectedParent = NULL;
    QCOMPARE(gameObject.getParent(), expectedParent);
}

void BGameObjectTest::numComponents()
{
    // Tests to make sure that adding a GameComponent properly updates the numComponents() property
    BGameObject* gameObject = new BGameObject;

    gameObject->addComponent(new BGameComponent);
    gameObject->addComponent(new BGameComponent);

    QCOMPARE(gameObject->numComponents(), 2);

    // Should free all of the memory from the GameComponents
    delete gameObject;
}

void BGameObjectTest::addAndRemoveComponents()
{
    // This test will test to see if adding/removing components properly sets the owner of each component
    BGameObject* gameObject = new BGameObject;
    BGameComponent* comp = new BGameComponent;

    QVERIFY2(comp->getGameObject() == NULL,
             "Component should not have an owner yet. It has not been added");

    gameObject->addComponent(comp);

    QVERIFY2(comp->getGameObject() != NULL,
             "Component should have an owner. It has been added.");
    QVERIFY2(comp->getGameObject() == gameObject,
             "Component's parent should be gameObject.");

    gameObject->removeComponent(comp);

    QVERIFY2(comp->getGameObject() == NULL,
            "Component should not have an owner. It has been removed.");

    delete gameObject;
    delete comp;
}

void BGameObjectTest::addRepeatComponents()
{
    // This test will test to make sure we can't add the same component twice
    BGameObject* gameObject = new BGameObject;
    BGameComponent* comp0 = new BGameComponent;
    BGameComponent* comp1 = new BGameComponent;
    BGameComponent* comp2 = new BGameComponent;

    gameObject->addComponent(comp0);
    gameObject->addComponent(comp1);
    gameObject->addComponent(comp2);

    QCOMPARE(gameObject->numComponents(), 3);

    // A component should not be added if it's already part of the GameObject
    gameObject->addComponent(comp1);
    gameObject->addComponent(comp2);

    QCOMPARE(gameObject->numComponents(), 3);

    delete gameObject;
}

void BGameObjectTest::addComponentsToOtherObject()
{
    // This test will test to make sure we can't add a component to another object
    // once it is already owned by one
    BGameObject* gameObject0 = new BGameObject;
    BGameObject* gameObject1 = new BGameObject;
    BGameComponent* comp = new BGameComponent;

    gameObject0->addComponent(comp);

    QCOMPARE(gameObject0->numComponents(), 1);
    QCOMPARE(gameObject1->numComponents(), 0);

    // A component should not be added to another GameObject if it already belongs to one
    gameObject1->addComponent(comp);

    QCOMPARE(gameObject0->numComponents(), 1);
    QCOMPARE(gameObject1->numComponents(), 0);

    delete gameObject0;
    delete gameObject1;
}

void BGameObjectTest::removeComponents()
{
    // This test tests to see if we can remove a GameComponent by pointer
    BGameObject* gameObject = new BGameObject;
    BGameComponent* comp0 = new BGameComponent;
    BGameComponent* comp1 = new BGameComponent;
    BGameComponent* comp2 = new BGameComponent;

    // Only add the first two
    gameObject->addComponent(comp0);
    gameObject->addComponent(comp1);

    QCOMPARE(gameObject->numComponents(), 2);

    // Should not remove a component if it's not owned by the object
    QVERIFY2(!gameObject->removeComponent(comp2),
             "Remove did not return false when passed foreign component");
    QCOMPARE(gameObject->numComponents(), 2);

    // Should remove a component by pointer
    QVERIFY2(gameObject->removeComponent(comp0),
             "Remove did not return true when passed a valid component");
    QCOMPARE(gameObject->numComponents(), 1);

    // Should not remove the same component twice
    QVERIFY2(!gameObject->removeComponent(comp0),
             "Remove did not return false when passed a valid component twice");

    delete gameObject;
    delete comp0;
    delete comp2;
}

void BGameObjectTest::hasParent()
{
    // Tests to make sure that setParent() properly updates the value of the hasParent() property
    BGameObject* parent = new BGameObject;
    BGameObject* child = new BGameObject;

    QVERIFY2(!parent->hasParent(),
             "parent should not have a parent.");
    QVERIFY2(!child->hasParent(),
             "child should not have a parent yet.");

    child->setParent(parent);

    QVERIFY2(!parent->hasParent(),
             "parent should not have a parent.");
    QVERIFY2(child->hasParent(),
             "child should have a parent. It has been set.");
    QVERIFY2(child->getParent() == parent,
             "child's parent should be parent.");

    child->setParent(NULL);

    QVERIFY2(!parent->hasParent(),
             "parent should not have a parent.");
    QVERIFY2(!child->hasParent(),
             "child should not have a parent anymore.");

    delete parent;
    delete child;
}

void BGameObjectTest::gameObjectTree()
{
    // Constructs a simple GameObject tree and tests everybody's hasParent() properties for correctness
    QFAIL("Need to implement this functionality");
}


