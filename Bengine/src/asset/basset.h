#ifndef BASSET_H
#define BASSET_H

#include <core/bobject.h>

class BAsset : public BObject
{
    B_OBJECT(BAsset)

public:
    BAsset();
    virtual ~BAsset();
};

#endif // BASSET_H
