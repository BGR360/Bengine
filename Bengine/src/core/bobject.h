#ifndef BOBJECT_H
#define BOBJECT_H

#include <bengine_global.h>

#include "bclass.h"

// Define the macro for declaring a B_OBJECT subclass (similar to how Q_OBJECT works)
#define B_OBJECT(classname) \
public: \
    static BClass getStaticClass() { return BClass(typeid(classname)); } \
private:


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

#endif // BOBJECT_H
