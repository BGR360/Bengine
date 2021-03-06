#include "bgamecomponent.h"

#include "bgameobject.h"

/*!
 * \class BGameComponent
 * \brief The BGameComponent class is the interface for all Game Components.
 * \inmodule Core
 *
 * Components are used to customize the functionality of a BGameObject.
 *
 * \sa BGameObject
 */

/*!
 * \brief Creates a new BGameComponent.
 */
BGameComponent::BGameComponent() :
    m_gameObject(NULL)
{}

/*!
 * \brief Destroys a BGameComponent.
 */
BGameComponent::~BGameComponent() {}

/*!
  \brief Called when the BGameComponent should start up.

  Override this function in any subclass of BGameComponent.
*/
void BGameComponent::start() {}

/*!
  \brief Called every frame to update the BGameComponent.

  The parameter \a deltaSeconds specifies the number of seconds
    since the last time update() was called.

  Override this function in any subclass of BGameComponent.
*/
void BGameComponent::update(float) {}

/*!
 * \brief Returns the BGameObject that owns this component.
 * If this component does not have a parent, returns \c null.
 */
BGameObject* BGameComponent::getGameObject() const
{
    return m_gameObject;
}

/*!
 * \brief Sets the parent BGameObject of this component to \a gameObject.
 */
void BGameComponent::setGameObject(BGameObject* gameObject)
{
    m_gameObject = gameObject;
}

