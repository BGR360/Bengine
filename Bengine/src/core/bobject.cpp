#include "bobject.h"
#include "bcomponent.h"

BObject::BObject()
{

}

BObject::~BObject()
{
    // Delete all BComponents
    QVector<BComponent*>::iterator i;
    for (i = m_components.begin(); i != m_components.end(); i++)
    {
        delete *i;
    }
    m_components.clear();
}

QVector<BComponent*> BObject::getComponents() const
{
    return m_components;
}

void BObject::addComponent(BComponent* component)
{
    m_components.push_back(component);
}

bool BObject::removeComponent(BComponent* component)
{
    int index = m_components.indexOf(component);
    if (index == -1)
        return false;
    m_components.remove(index);
    return true;
}
