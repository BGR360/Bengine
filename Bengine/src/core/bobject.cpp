#include "bobject.h"
#include "bcomponent.h"

/*!
 * \class BObject
 * \brief The BObject class is the base class for all Game Objects
 * \inmodule core
 *
 * A BObject carries a list of BComponent objects and is the base class for all game objects.
 *
 * \sa BComponent
 */

/*!
 * \brief Constructs a new BObject
 */
BObject::BObject()
{

}

/*!
 * \brief Destroys a BObject
 */
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

/*!
 * \brief BObject::getComponents
 * Returns the game components that this BObject has
 */
QVector<BComponent*> BObject::getComponents() const
{
    return m_components;
}

/*!
 * \brief Adds a BComponent to the object
 * Adds \a component to this object's list of components
 * A BObject has ownership of its BObjects and is responsible for deleting them.
 */
void BObject::addComponent(BComponent* component)
{
    m_components.push_back(component);
}

/*!
 * \brief Removes a BComponent from the object
 * Returns \c true if \a component was owned by this BObject and removed; \c false otherwise
 */
bool BObject::removeComponent(BComponent* component)
{
    int index = m_components.indexOf(component);
    if (index == -1)
        return false;
    m_components.remove(index);
    return true;
}
