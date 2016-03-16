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
BGameObject::BGameObject() :
    m_parent(NULL)
{}

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
 * \brief Returns the number of BGameComponent objects owned by this object.
 */
int BGameObject::numComponents() const
{
    return m_components.size();
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
 *
 * \b{Note:} If you remove a BGameComponent from a BGameObject, it is \b{your} responsibility
 * to free its memory to avoid a memory leak.
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
    return false;
}

/*!
 * \brief Sets the parent BGameObject of this game object to \a parent.
 */
void BGameObject::setParent(BGameObject* parent)
{
    m_parent = parent;
}

/*!
 * \brief Returns \c true if this game object has a parent, \c false if it is the root object.
 */
bool BGameObject::hasParent() const
{
    return m_parent != NULL;
}

/*!
 * \brief Returns the parent BGameObject of this object.
 *
 * If the BGameObject has no parent, returns \c null.
 */
BGameObject*BGameObject::getParent() const
{
    return m_parent;
}
