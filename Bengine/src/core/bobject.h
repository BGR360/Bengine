#ifndef BOBJECT_H
#define BOBJECT_H

#include <bengine_global.h>

#include "bclass.h"

// Define the macro for declaring a B_OBJECT subclass (similar to how Q_OBJECT works)
#define B_OBJECT(classname) \
public: \
    static BClass getStaticClass() { return BClass(typeid(classname)); } \
private:


//B_CLASS(BObject)
class BENGINESHARED_EXPORT BObject
{
    B_OBJECT(BObject)

public:
    BObject();
    virtual ~BObject();

    const BClass& getClass() const;

protected:
    BClass m_class;
};


// Here is a macro for specifying documentation for BObject subclasses
#define B_OBJECT_DOC(classname) \
    /*! \
    \fn static BClass classname::getStaticClass() \
    */

#endif // BOBJECT_H
