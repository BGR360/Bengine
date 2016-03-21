#ifndef BASSETCALLBACK_H
#define BASSETCALLBACK_H

#include <bengine_global.h>

class BAsset;

class BENGINESHARED_EXPORT BAssetCallback
{
public:
    virtual void onAssetLoaded(BAsset* asset) const = 0;
};

#endif // BASSETCALLBACK_H
