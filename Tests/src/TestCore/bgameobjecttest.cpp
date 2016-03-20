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
    QCOMPARE(gameObject.hasChildren(), false);
    QCOMPARE(gameObject.numChildren(), 0);
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

void BGameObjectTest::setParent()
{
    // This tests to make sure the proper stuff happens when you reassign the parent of a game object
    // Tests getParent(), hasChildren(), addChild(), isChildOf()
    BGameObject* parent0 = new BGameObject;
    BGameObject* parent1 = new BGameObject;
    BGameObject* child = new BGameObject;

    QVERIFY(!child->hasParent());

    parent0->addChild(child);
    QVERIFY2(parent0->hasChildren(),
             "parent0->hasChildren() should return true. We added child to it.");
    QVERIFY2(child->getParent() == parent0,
             "child's parent should be parent0. We called addChild()");

    // Reassign child to be a child of parent1
    child->setParent(parent1);

    QVERIFY2(child->getParent() == parent1,
             "child's parent should now be parent1.");
    QVERIFY2(!parent0->hasChildren(),
             "parent0 should no longer have any children");

    child->setParent(NULL);
    QVERIFY2(!parent1->hasChildren(),
             "parent1 should no longer have any children. We set parent to NULL.");

    delete parent0;
    delete parent1;
    delete child;
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

void BGameObjectTest::gameObjectFamilyTree()
{
    // Constructs a simple GameObject tree and tests the following functions:
    // isChildOf(), isParentOf(), isDescendentOf(), isAncestorOf()
    BGameObject* parent = new BGameObject;
    BGameObject* son = new BGameObject;
    BGameObject* daughter = new BGameObject;
    BGameObject* granddaughter = new BGameObject;
    BGameObject* grandson = new BGameObject;

    // Set up the family tree
    son->addChild(grandson);
    daughter->addChild(granddaughter);
    parent->addChild(son);
    parent->addChild(daughter);

    // Test ancestors and shit
    QVERIFY(parent->isParentOf(son));
    QVERIFY(parent->isParentOf(daughter));
    QVERIFY(parent->isAncestorOf(son));
    QVERIFY(parent->isAncestorOf(daughter));
    QVERIFY(!parent->isParentOf(grandson));
    QVERIFY(!parent->isParentOf(granddaughter));
    QVERIFY(parent->isAncestorOf(granddaughter));
    QVERIFY(parent->isAncestorOf(grandson));

    QVERIFY(son->isChildOf(parent));
    QVERIFY(son->isDescendentOf(parent));
    QVERIFY(son->isParentOf(grandson));
    QVERIFY(son->isAncestorOf(grandson));
    QVERIFY(!son->isParentOf(granddaughter));

    QVERIFY(daughter->isChildOf(parent));
    QVERIFY(daughter->isDescendentOf(parent));
    QVERIFY(daughter->isParentOf(granddaughter));
    QVERIFY(daughter->isAncestorOf(granddaughter));
    QVERIFY(!daughter->isParentOf(grandson));

    QVERIFY(grandson->isDescendentOf(parent));
    QVERIFY(grandson->isDescendentOf(son));
    QVERIFY(grandson->isChildOf(son));
    QVERIFY(!grandson->isChildOf(parent));

    QVERIFY(granddaughter->isDescendentOf(parent));
    QVERIFY(granddaughter->isDescendentOf(daughter));
    QVERIFY(granddaughter->isChildOf(daughter));
    QVERIFY(!granddaughter->isChildOf(parent));
}

void BGameObjectTest::addAndRemoveChildren()
{
    // Tests addChild(), removeChild(), and numChildren(), and isChildOf()
    BGameObject* parent = new BGameObject;
    BGameObject* child0 = new BGameObject;
    BGameObject* child1 = new BGameObject;
    BGameObject* child2 = new BGameObject;
    BGameObject* estrangedChild = new BGameObject;

    QCOMPARE(parent->numChildren(), 0);

    parent->addChild(child0);
    parent->addChild(child1);
    parent->addChild(child2);

    QCOMPARE(parent->numChildren(), 3);

    QVERIFY(child0->isChildOf(parent));
    QVERIFY(child1->isChildOf(parent));
    QVERIFY(child2->isChildOf(parent));
    QVERIFY(!estrangedChild->isChildOf(parent));

    // Test removing children
    QVERIFY2(parent->removeChild(child1), "removeChild() should return true on success");
    QVERIFY2(parent->removeChild(child2), "removeChild() should return true on success");

    QCOMPARE(parent->numChildren(), 1);

    // Removing a non-child shouldnt change the number of children
    QVERIFY2(!parent->removeChild(estrangedChild), "removeChild() should return false on failure");

    delete parent;
    delete estrangedChild;
    delete child1;
    delete child2;
}

void BGameObjectTest::addRepeatChildren()
{
    // Tests to make sure that we can't add a child to an object twice.
    BGameObject* parent = new BGameObject;
    BGameObject* repeatChild = new BGameObject;

    parent->addChild(repeatChild);
    QCOMPARE(parent->numChildren(), 1);
    parent->addChild(repeatChild);
    QCOMPARE(parent->numChildren(), 1);

    delete parent;
}

void BGameObjectTest::reassignChildren()
{
    // Tests to make sure that we can't add a child to a game object if it's already the child
    // of another game object.
    // Tests to make sure that we CAN reassign an object's parent by using setParent() instead
    BGameObject* parent0 = new BGameObject;
    BGameObject* parent1 = new BGameObject;
    BGameObject* child0 = new BGameObject;
    BGameObject* child1 = new BGameObject;

    parent0->addChild(child0);
    parent1->addChild(child1);

    QCOMPARE(parent0->numChildren(), 1);
    QCOMPARE(parent1->numChildren(), 1);

    // Cannot add a game object that's already another one's child
    parent0->addChild(child1);
    QCOMPARE(parent0->numChildren(), 1);

    // But we can reassign it using setParent()
    child1->setParent(parent0);
    QCOMPARE(parent0->numChildren(), 2);
    QCOMPARE(parent1->numChildren(), 0);
    QVERIFY(child1->isChildOf(parent0));
    QVERIFY(parent0->isParentOf(child1));

    delete parent0;
    delete parent1;
}

void BGameObjectTest::passNullStuff()
{
    BGameObject* parent = new BGameObject;
    BGameObject* child = new BGameObject;
    BGameComponent* comp = new BGameComponent;

    parent->addChild(child);
    parent->addComponent(comp);

    parent->addChild(NULL);
    parent->addComponent(NULL);
    QVERIFY(!parent->isAncestorOf(NULL));
    QVERIFY(!parent->isParentOf(NULL));
    QVERIFY(!child->isDescendentOf(NULL));
    QVERIFY(!child->isChildOf(NULL));
    QVERIFY(!parent->removeChild(NULL));
    QVERIFY(!parent->removeComponent(NULL));
    child->setParent(NULL);

    delete parent;
}


