#ifndef BASSETMANAGER_H
#define BASSETMANAGER_H

#include <QDir>
#include <QMap>
#include <QString>
#include <QVector>

#include <core/bobject.h>

class BAssetFactory;

class BAssetManager : public BObject
{
    B_OBJECT(BAssetManager)

public:
    BAssetManager();
    virtual ~BAssetManager();

    template<typename T> bool canLoadAsset(const QString& path) const;
    template<typename T> bool canLoadAsset(const QDir& path) const;
    bool canLoadAsset(const QString& path, const BClass& assetClass) const;
    bool canLoadAsset(const QDir& path, const BClass& assetClass) const;

    template<typename T> void requestAsset(const QString& path);
    template<typename T> void requestAsset(const QDir& path);
    void requestAsset(const QString& path, const BClass& assetClass);
    void requestAsset(const QDir& path, const BClass& assetClass);

    QVector<const BAssetFactory*> getAssetFactories() const;
    void registerAssetFactory(const BAssetFactory* factory);

    void loadAllAssets();

    bool isLoaded(const QString& path) const;
    bool isLoaded(const QDir& path) const;

private:
    QMap<BClass, const BAssetFactory*> m_assetFactories;
};

#endif // BASSETMANAGER_H
