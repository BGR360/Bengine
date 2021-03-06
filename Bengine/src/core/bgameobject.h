#ifndef BGAMEOBJECT_H
#define BGAMEOBJECT_H

#include <qvector.h>

#include "bobject.h"

class BGameComponent;

class BENGINESHARED_EXPORT BGameObject : public BObject
{
    B_OBJECT(BGameObject)

public:
    BGameObject();
    virtual ~BGameObject();

    const QVector<BGameComponent*>& getComponents() const;
    int numComponents() const;
    void addComponent(BGameComponent* component);
    bool removeComponent(BGameComponent* component);

    BGameObject* getParent();
    const BGameObject* getParent() const;
    void setParent(BGameObject* newParent);
    bool hasParent() const;
    bool isParentOf(const BGameObject* other) const;
    bool isAncestorOf(const BGameObject* other) const;

    const QVector<BGameObject*>& getChildren() const;
    bool hasChildren() const;
    int numChildren() const;
    void addChild(BGameObject* child);
    bool removeChild(BGameObject* child);
    bool isChildOf(const BGameObject* other) const;
    bool isDescendentOf(const BGameObject* other) const;

private:
    BGameObject* m_parent;
    QVector<BGameComponent*> m_components;
    QVector<BGameObject*> m_children;
};

#endif // BGAMEOBJECT_H
