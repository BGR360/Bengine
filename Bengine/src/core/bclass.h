#ifndef BCLASS_H
#define BCLASS_H

#include <bengine_global.h>

#include <typeindex>

class BENGINESHARED_EXPORT BObject;

class BClass
{
public:
    BClass(const BObject& object);
    BClass(const std::type_index& type);
    ~BClass();

    const char* name() const;

    bool operator==(const BClass& other) const;
    bool operator!=(const BClass& other) const;

private:
    std::type_index m_type_info;
};

#endif // BCLASS_H
