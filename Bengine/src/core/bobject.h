#ifndef BOBJECT_H
#define BOBJECT_H

#include <qvector.h>

#include <bengine_global.h>

class BComponent;

class BENGINESHARED_EXPORT BObject
{
public:
    BObject();
    virtual ~BObject();

    QVector<BComponent*> getComponents() const;
    void addComponent(BComponent* component);
    bool removeComponent(BComponent* component);

private:
    // A BObject has ownership of its BComponents
    QVector<BComponent*> m_components;
};

#endif // BOBJECT_H
