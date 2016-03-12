#include "bcomponent.h"

/*!
 * \class BComponent
 * \brief The BComponent class is the interface for all Game Components.
 * \inmodule Core
 *
 * Components are used to customize the functionality of a BObject.
 *
 * \sa BObject
 */

/*!
  \brief Called when the BComponent should start up.

  Override this function in any subclass of BComponent.
*/
void BComponent::start() {}

/*!
  \brief Called every frame to update the BComponent.

  The parameter \a deltaSeconds specifies the number of seconds
    since the last time update() was called.

  Override this function in any subclass of BComponent.
*/
void BComponent::update(float deltaSeconds) {}

/*!
 * \brief Returns the BObject that owns this component.
 * If this component does not have a parent, returns \c null.
 */
BObject*BComponent::getParent() const
{
    return m_parent;
}

/*!
 * \brief Sets the parent BObject of this component to \a parent.
 */
void BComponent::setParent(BObject* parent)
{
    m_parent = parent;
}

