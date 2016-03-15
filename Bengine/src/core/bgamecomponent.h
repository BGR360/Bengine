#ifndef BCOMPONENT_H
#define BCOMPONENT_H

#include <bengine_global.h>

class BGameObject;

class BENGINESHARED_EXPORT BGameComponent
{
public:
    virtual ~BGameComponent();

    virtual void start();
    virtual void update(float deltaSeconds);

    BGameObject* getGameObject() const;
    void setGameObject(BGameObject* parent);

private:
    BGameComponent();
    BGameObject* m_parent;
};

#endif // BCOMPONENT_H
