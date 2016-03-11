#ifndef BOBJECT_H
#define BOBJECT_H

#include <qvector.h>

class BComponent;

class BObject
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
