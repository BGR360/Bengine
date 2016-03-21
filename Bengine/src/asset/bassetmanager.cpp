#include "bassetmanager.h"

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
  be aware of all the asset factories it is able to use. To make your custom

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

template<typename T>
bool BAssetManager::canLoadAsset(const QString& path) const
{
    return false;
}

template<typename T>
bool BAssetManager::canLoadAsset(const QDir& path) const
{
    return false;
}

bool BAssetManager::canLoadAsset(const QString& path, const BClass& assetClass) const
{
    return false;
}

bool BAssetManager::canLoadAsset(const QDir& path, const BClass& assetClass) const
{
    return false;
}

template<typename T>
void BAssetManager::requestAsset(const QString& path)
{

}

void BAssetManager::requestAsset(const QString& path, const BClass& assetClass)
{

}
