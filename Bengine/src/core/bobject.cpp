#include "bobject.h"

/*!
  \class BObject
  \brief The BObject class is the base class of all classes in the Bengine.
  \inmodule Core

  The BObject class is a lightweight base class for all classes that belong the the engine.
  All BObject subclasses are prefixed with a 'B', just like all Qt classes are prefixed with a 'Q'.

  \chapter Subclassing BObject

  In order to subclass BObject, you must include the \l B_OBJECT macro somewhere in the class declaration:

  \snippet bobject/subclass.h 0

  This macro does some background magic which will allow the engine to supply things like
  static type info (see the \l BClass documentation) through the getStaticClass() function.
*/

/*!
  \macro B_OBJECT(className)
  \relates BObject

  Include this macro in your class definition when subclassing BObject.
  To use this macro, include the name of your class in the \a className parameter, as such:

  \snippet bobject/subclass.h 0
*/

/*!
 * \brief Constructs a new BObject.
 */
BObject::BObject() :
    // Construct our BClass object by passing in ourselves.
    m_class(*this)
{}

/*!
 * \brief Destroys a BObject.
 */
BObject::~BObject() {}

/*!
 * \brief Returns the type of this BObject as a BClass instance.
 */
const BClass& BObject::getClass() const
{
    return m_class;
}
