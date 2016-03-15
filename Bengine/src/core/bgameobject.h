#ifndef BOBJECT_H
#define BOBJECT_H

#include <qvector.h>

#include <bengine_global.h>

class BGameComponent;

class BENGINESHARED_EXPORT BGameObject
{
public:
    BGameObject();
    virtual ~BGameObject();

    QVector<BGameComponent*> getComponents() const;
    void addComponent(BGameComponent* component);
    bool removeComponent(BGameComponent* component);

private:
    // A BGameObject has ownership of its BGameComponents
    QVector<BGameComponent*> m_components;
};

#endif // BOBJECT_H
