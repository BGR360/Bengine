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

    // Delete all children
    QVector<BGameObject*>::iterator e;
    for (e = m_children.begin(); e != m_children.end(); e++)
    {
        delete *e;
    }
}

/*!
 * Returns the game components that this BGameObject has.
 */
const QVector<BGameComponent*>& BGameObject::getComponents() const
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
 * If \a component already belongs to this object, it will not be added again.
 * Also, if \a component already belongs to another BGameObject, it will not be added to this.
 * If the component is added, it automatically sets the owner of \a component to \c this.
 *
 * \b{Note:} A BGameObject has ownership of its BGameComponent objects and is responsible for deleting them.
 */
void BGameObject::addComponent(BGameComponent* component)
{
    if (component && component->getGameObject() == NULL)
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
 * \brief Returns the parent BGameObject of this object.
 *
 * If the BGameObject has no parent, returns \c null.
 */
BGameObject* BGameObject::getParent()
{
    return m_parent;
}

/*!
 * \brief Returns the parent BGameObject of this object.
 *
 * If the BGameObject has no parent, returns \c null.
 */
const BGameObject* BGameObject::getParent() const
{
    return m_parent;
}

/*!
 * \brief Sets the parent BGameObject of this game object to \a parent.
 *
 * If this object was previously the child of another game object, it will notify
 * the other game object that it's about to peace out.
 */
void BGameObject::setParent(BGameObject* newParent)
{
    // If this object is already a child of another, reassign its parenthood.
    // Otherwise, it's safe to simply set the value of m_parent
    BGameObject* previousParent = m_parent;
    if (previousParent && newParent != previousParent)
    {
        previousParent->removeChild(this);
    }

    if (newParent)
    {
        newParent->addChild(this);
    }
    else
    {
        m_parent = NULL;
    }
}

/*!
 * \brief Returns \c true if this game object has a parent, \c false if it is the root object.
 */
bool BGameObject::hasParent() const
{
    return m_parent != NULL;
}

/*!
 * \brief Returns \c true if this object is a \b{direct} parent of \a other, \c false otherwise.
 */
bool BGameObject::isParentOf(const BGameObject* other) const
{
    return other && other->isChildOf(this);
}

/*!
 * \brief Returns \c true if there is a chain of children which connects this
 * game object to \a other, \c false otherwise.
 */
bool BGameObject::isAncestorOf(const BGameObject* other) const
{
    return other && other->isDescendentOf(this);
}

/*!
 * \brief Returns a list of this object's child game objects.
 */
const QVector<BGameObject*>& BGameObject::getChildren() const
{
    return m_children;
}

/*!
 * \brief Returns \c true if this object is a \b{direct} child of \a other, \c false otherwise.
 */
bool BGameObject::isChildOf(const BGameObject* other) const
{
    return other && other == m_parent;
}

/*!
 * \brief Returns \c true if there is a chain of parent game objects that connect this object
 * to \a other, \c false otherwise.
 */
bool BGameObject::isDescendentOf(const BGameObject* other) const
{
    if (this->isChildOf(other))
        return true;

    if (!m_parent)
        return false;

    return m_parent->isDescendentOf(other);
}

/*!
 * \brief Returns \c true if this game object has any child game objects, \c false otherwise.
 */
bool BGameObject::hasChildren() const
{
    return this->numChildren() > 0;
}

/*!
 * \brief Returns the number of child game objects that this object has.
 */
int BGameObject::numChildren() const
{
    return m_children.size();
}

/*!
 * \brief Designates \a child as a child of this game object.
 *
 * If \a child is already a child of this or any other game object,
 * it will not be added as a child to this.
 */
void BGameObject::addChild(BGameObject* child)
{
    if (child && !child->hasParent())
    {
        child->m_parent = this;
        m_children.push_back(child);
    }
}

/*!
 * \brief Designates that \a child should no longer be a child of this game object.
 *
 * Returns \c true if \a child was initially a child of this game object and if it
 * was removed, \c false otherwise.
 */
bool BGameObject::removeChild(BGameObject* child)
{
    if (child)
    {
        if (child->getParent() == this)
        {
            child->m_parent = NULL;
        }

        int index = m_children.indexOf(child);
        if (index == -1)
            return false;

        m_children.remove(index);
        return true;
    }
    return false;
}
