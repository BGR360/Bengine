#include "bobject.h"

/*!
  \class BObject
  \brief The BObject class is the base class of all classes in the Bengine.
  \inmodule Core
*/

/*!
 * \brief Constructs a new BObject.
 */
BObject::BObject() :
    // Construct our BClass object by passing in ourselves.
    m_class(this)
{}

/*!
 * \brief Destroys a BObject.
 */
BObject::~BObject() {}

/*!
 * \brief Returns the type of this BObject as a BClass instance.
 * \sa BClass
 */
const BClass& BObject::getClass() const
{
    return m_class;
}
