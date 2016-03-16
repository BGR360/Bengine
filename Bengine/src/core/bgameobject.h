#ifndef BGAMEOBJECT_H
#define BGAMEOBJECT_H

#include <bengine_global.h>

#include <qvector.h>

#include "bobject.h"

class BGameComponent;

class BENGINESHARED_EXPORT BGameObject : public BObject
{
public:
    BGameObject();
    virtual ~BGameObject();

    QVector<BGameComponent*> getComponents() const;
    int numComponents() const;
    void addComponent(BGameComponent* component);
    bool removeComponent(BGameComponent* component);

    BGameObject* getParent() const;
    void setParent(BGameObject* parent);
    bool hasParent() const;

    // TODO: isChildOf()
    // TODO: isDescendentOf()
    // TODO: hasChildren()
    // TODO: numChildren()
    // TODO: addChild()
    // TODO: removeChild()

private:
    BGameObject* m_parent;
    QVector<BGameComponent*> m_components;
};

#endif // BGAMEOBJECT_H
