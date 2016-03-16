#ifndef BOBJECT_H
#define BOBJECT_H

#include <bengine_global.h>

#include "bclass.h"

class BENGINESHARED_EXPORT BObject
{
public:
    BObject();
    virtual ~BObject();

    const BClass& getClass() const;

protected:
    BClass m_class;
};

#endif // BOBJECT_H
