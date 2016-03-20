#ifndef BASSETFACTORY_H
#define BASSETFACTORY_H

#include <QVector>

#include <core/bobject.h>

class BAsset;

class BAssetFactory : public BObject
{
    B_OBJECT(BAssetFactory)

public:
    virtual BAsset* loadAsset(const QString& path) const = 0;
    virtual BClass supportedClass() const = 0;
    virtual QVector<const char*> supportedExtensions() const = 0;
};

#endif // BASSETFACTORY_H
