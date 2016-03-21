#include "bclass.h"

#include "bobject.h"

// Yes, I'm giving in and using standard C++ :(
#include <typeindex>

/*!
 * \class BClass
 * \brief The BClass class holds Runtime Type Information for a BObject.
 * \inmodule Core
 *
 * The BClass object holds the Runtime Type Information
 * of the BObject and can be used to compare types and cast BObjects.
 *
 * Every BObject instance has a BClass instance that can be acquired with
 * BObject::getClass().
 *
 * Additionally, any classes that inherit from BObject and use the B_OBJECT macro
 * can statically return a BClass instance using the getStaticClass() function.
 *
 * For example, if you define a subclass of BObject like so:
 *
 * \snippet bobject/subclass.h 0
 *
 * Then you can acquire a BClass instance in two different ways:
 *
 * \snippet bobject/subclass_main.cpp 0
 *
 * \sa BObject
 */

/*!
 * \brief Constructs a new BClass instance that holds the class information of \a object.
 */
BClass::BClass(const BObject& object)
    : m_type_info(typeid(object))
{}

/*!
 * \brief Constructs a new BClass instance that holds the same type info as the
 * std::type_index object \a type.
 *
 * This function is used by the B_CLASS_OF() macro to construct a generic
 * BClass instance for a type rather than for an object.
 */
BClass::BClass(const std::__1::type_index& type) :
    m_type_info(type)
{}

/*!
 * \brief Destroys a BClass object.
 */
BClass::~BClass()
{}

/*!
 * \brief Returns the name of the class as a \c {const char*}.
 *
 * \b{Note:} The name that this function returns is implementation dependent and is rarely
 * exactly equivalent to the name of the class.
 */
const char* BClass::name() const
{
    return m_type_info.name();
}

/*!
 * \brief Compares two BClass objects for equality.
 *
 * Returns \c true if this and \a other refer to the same type, \c false otherwise.
 */
bool BClass::operator==(const BClass& other) const
{
    return m_type_info == other.m_type_info;
}

/*!
 * \brief Compares two BClass objects for inequality.
 *
 * Returns \c true if this and \a other refer to different types, \c false otherwise.
 */
bool BClass::operator!=(const BClass& other) const
{
    return m_type_info != other.m_type_info;
}

/*!
 * \brief Used to compare this BClass with \a right.
 */
bool BClass::operator<(const BClass& right) const
{
    return m_type_info < right.m_type_info;
}

/*!
 * \brief Used to compare this BClass with \a right.
 */
bool BClass::operator<=(const BClass& right) const
{
    return m_type_info <= right.m_type_info;
}

/*!
 * \brief Used to compare this BClass with \a right.
 */
bool BClass::operator>(const BClass& right) const
{
    return m_type_info > right.m_type_info;
}

/*!
 * \brief Used to compare this BClass with \a right.
 */
bool BClass::operator>=(const BClass& right) const
{
    return m_type_info >= right.m_type_info;
}
