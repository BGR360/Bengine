#ifndef BASSETMANAGER_H
#define BASSETMANAGER_H

#include <QDir>
#include <QMap>
#include <QString>
#include <QVector>

#include <core/bobject.h>

class BAsset;
class BAssetCallback;
class BAssetFactory;

class BENGINESHARED_EXPORT BAssetManager : public BObject
{
    B_OBJECT(BAssetManager)

public:
    BAssetManager();
    virtual ~BAssetManager();

    bool canLoadAsset(const QString& path, const BClass& assetClass) const;
    bool canLoadAsset(const QDir& path, const BClass& assetClass) const;

    void requestAsset(const QString& path, const BClass& assetClass, const BAssetCallback* callback);
    void requestAsset(const QDir& path, const BClass& assetClass, const BAssetCallback* callback);

    QVector<const BAssetFactory*> getAssetFactories() const;
    void registerAssetFactory(const BAssetFactory* factory);

    void loadAllAssets();

    bool isAssetLoaded(const QString& path) const;
    bool isAssetLoaded(const QDir& path) const;

    BAsset* getAsset(const QString& path) const;
    BAsset* getAsset(const QDir& path) const;

private:
    QMap<BClass, const BAssetFactory*> m_assetFactories;
};

#endif // BASSETMANAGER_H
