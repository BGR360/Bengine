#ifndef BCOMPONENT_H
#define BCOMPONENT_H

#include <bengine_global.h>

class BObject;

class BENGINESHARED_EXPORT BComponent
{
public:
    virtual void start();
    virtual void update(float deltaSeconds);

    BObject* getParent() const;
    void setParent(BObject* parent);

private:
    BObject* m_parent;
};

#endif // BCOMPONENT_H
