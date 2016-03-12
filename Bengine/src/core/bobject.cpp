#include "bobject.h"
#include "bcomponent.h"

/*!
 * \class BObject
 * \brief The BObject class is the base class for all Game Objects.
 * \inmodule Core
 *
 * A BObject carries a list of BComponent objects and is the base class for all game objects.
 *
 * \sa BComponent
 */

/*!
 * \brief Constructs a new BObject.
 */
BObject::BObject() :
    m_parent(nullptr)
{}

/*!
 * \brief Destroys a BObject.
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
 * Returns the game components that this BObject has.
 */
QVector<BComponent*> BObject::getComponents() const
{
    return m_components;
}

/*!
 * Adds \a component to this object's list of components.
 *
 * Automatically sets the parent of \a component to \c this.
 *
 * \b{Note:} A BObject has ownership of its BComponent objects and is responsible for deleting them.
 */
void BObject::addComponent(BComponent* component)
{
    if (component)
    {
        component->setParent(this);
        m_components.push_back(component);
    }
}

/*!
 * \brief Removes a BComponent from the object.
 *
 * Automatically sets the parent of \a component to \c null if removed.
 *
 * Returns \c true if \a component was owned by this BObject and removed; \c false otherwise.
 */
bool BObject::removeComponent(BComponent* component)
{
    if (component)
    {
        int index = m_components.indexOf(component);
        if (index == -1)
            return false;

        component->setParent(nullptr);
        m_components.remove(index);
        return true;
    }
}
