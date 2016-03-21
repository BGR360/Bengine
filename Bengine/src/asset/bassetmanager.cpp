#include "bassetmanager.h"

#include "bassetcallback.h"
#include "bassetfactory.h"

/*!
  \class BAssetManager
  \brief The BAssetManager class is responsible for managing the state of all
         the game assets in a scene.
  \inmodule Assets

  Every BScene has its own BAssetManager instance. The BAssetManager manages all of the game
  assets used in the scene.

  \sa BAsset, BAssetFactory

  \chapter Factories

  A scene's BAssetManager has a list of BAssetFactory objects. The asset factories are
  the classes that do the actual loading, importing, and saving of assets. Each asset factory
  supports a single type of asset, so we have classes like BMeshAssetFactory, BMaterialAssetFactory,
  BImageAssetFactory, etc.

  When the asset manager is asked to load a resource, it is given a file path. From this, it searches
  all of its available BAssetFactories to find one that can load the asset.

  If you want to support loading of your own custom assets, simply create a subclass of
  BAssetFactory and register it with the asset manager.

  \chapter Registering Factories

  In order for the asset manager to be aware of what types of assets it can load, it has to
  be aware of all the asset factories it is able to use. To make your custom asset factory
  known by the asset manager, call registerAssetFactory() on the asset manager.

  For more information, see the section in the BAssetFactory documentation about registering factories.
*/

/*!
 * \brief Creates a new BAssetManager.
 */
BAssetManager::BAssetManager()
{

}

/*!
 * \brief Destroys a BAssetManager.
 */
BAssetManager::~BAssetManager()
{

}

bool BAssetManager::canLoadAsset(const QString& path, const BClass& assetClass) const
{
    return false;
}

/*!
 * \brief Checks if a given file path can be loaded by the asset manager.
 *
 * This is a templated function. To call this function, pass in the type of BAsset
 * that you want to load as the template parameter, and pass in the file \a path to
 * the asset file.
 *
 * \snippet basset/bassetmanager_example.cpp canLoadAsset
 *
 * The function returns \c true if it is able to load the asset at the given file \a path,
 * \c false otherwise.
 */
bool BAssetManager::canLoadAsset(const QDir& path, const BClass& assetClass) const
{
    return false;
}

void BAssetManager::requestAsset(const QString& path, const BClass& assetClass, const BAssetCallback* callback)
{

}

/*!
 * \brief Posts a request for the asset located at the given file \a path.
 *
 * To call this function, the class of the asset being requested must be specified by \a assetClass.
 * The caller must also pass in an instance of BAssetCallback to \a callback so that,
 * when the asset has been loaded, the caller can be notified.
 *
 * Multiple objects can request the same asset. When this happens, the asset manager keeps track
 * of all objects who have requested it and notifies each one when the asset has been loaded.
 *
 * \snippet basset/bassetmanager_example.cpp requestAsset
 *
 * \sa BAssetCallback
 */
void BAssetManager::requestAsset(const QDir& path, const BClass& assetClass, const BAssetCallback* callback)
{

}

QVector<const BAssetFactory*> BAssetManager::getAssetFactories() const
{
    return QVector<const BAssetFactory*>();
}

void BAssetManager::loadAllAssets()
{

}

bool BAssetManager::isAssetLoaded(const QString& path) const
{
    return false;
}

bool BAssetManager::isAssetLoaded(const QDir& path) const
{
    return false;
}

BAsset* BAssetManager::getAsset(const QString& path) const
{
    return NULL;
}

BAsset* BAssetManager::getAsset(const QDir& path) const
{
    return NULL;
}
