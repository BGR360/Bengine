#include "bgameobject.h"
#include "bgamecomponent.h"

/*!
 * \class BGameObject
 * \brief The BGameObject class is the base class for all Game Objects.
 * \inmodule Core
 *
 * A BGameObject carries a list of BGameComponent objects and is the base class for all game objects.
 *
 * \sa BGameComponent
 */

/*!
 * \brief Constructs a new BGameObject.
 */
BGameObject::BGameObject() {}

/*!
 * \brief Destroys a BGameObject.
 */
BGameObject::~BGameObject()
{
    // Delete all BGameComponents
    QVector<BGameComponent*>::iterator i;
    for (i = m_components.begin(); i != m_components.end(); i++)
    {
        delete *i;
    }
    m_components.clear();
}

/*!
 * Returns the game components that this BGameObject has.
 */
QVector<BGameComponent*> BGameObject::getComponents() const
{
    return m_components;
}

/*!
 * Adds \a component to this object's list of components.
 *
 * Automatically sets the parent of \a component to \c this.
 *
 * \b{Note:} A BGameObject has ownership of its BGameComponent objects and is responsible for deleting them.
 */
void BGameObject::addComponent(BGameComponent* component)
{
    if (component)
    {
        component->setGameObject(this);
        m_components.push_back(component);
    }
}

/*!
 * \brief Removes a BGameComponent from the object.
 *
 * Automatically sets the parent of \a component to \c null if removed.
 *
 * Returns \c true if \a component was owned by this BGameObject and removed; \c false otherwise.
 */
bool BGameObject::removeComponent(BGameComponent* component)
{
    if (component)
    {
        int index = m_components.indexOf(component);
        if (index == -1)
            return false;

        component->setGameObject(NULL);
        m_components.remove(index);
        return true;
    }
}
