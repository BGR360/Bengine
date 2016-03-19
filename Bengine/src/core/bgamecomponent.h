#ifndef BGAMECOMPONENT_H
#define BGAMECOMPONENT_H

#include <bengine_global.h>

#include "bobject.h"

class BGameObject;

class BENGINESHARED_EXPORT BGameComponent : public BObject
{
    B_OBJECT(BGameComponent)

public:
    BGameComponent();
    virtual ~BGameComponent();

    virtual void start();
    virtual void update(float deltaSeconds);

    BGameObject* getGameObject() const;
    void setGameObject(BGameObject* gameObject);

private:
    BGameObject* m_gameObject;
};

#endif // BGAMECOMPONENT_H
