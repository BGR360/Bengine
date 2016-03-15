#include "bclass.h"

#include "bobject.h"

// Yes, I'm giving in and using standard C++ :(
#include <typeindex>

/*!
 * \class BClass
 * \brief The BClass class hold Runtime Type Information for a BObject.
 * \inmodule Core
 *
 * Every BObject instance has a BClass instance that can be acquired with
 * BObject::getClass(). The BClass object holds the Runtime Type Information
 * of the BObject and can be used to compare types and cast BObjects.
 *
 * \sa BObject
 */

/*!
 * \brief Constructs a new BClass instance that holds the class information of \a object.
 */
BClass::BClass(const BObject* object)
    : m_type_info(typeid(*object))
{}

/*!
 * \brief Destroys a BClass object.
 */
BClass::~BClass()
{}

/*!
 * \brief Returns the name of the class as a \c {const char*}.
 */
const char* BClass::name() const
{
    return "";
}

/*!
 * \brief Compares two BClass objects for equality.
 *
 * Returns \c true if this and \a other refer to the same type, \c false otherwise.
 */
bool BClass::operator==(const BClass& other) const
{
    return false;
}

/*!
 * \brief Compares two BClass objects for inequality.
 *
 * Returns \c true if this and \a other refer to different types, \c false otherwise.
 */
bool BClass::operator!=(const BClass& other) const
{
    return false;
}
