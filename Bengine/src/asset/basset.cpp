#include "basset.h"

/*!
  \class BAsset
  \brief The BAsset class is the base class for all game assets (textures, materials, 3D models, etc.).
  \inmodule Assets

  The BAsset class represents a game asset. Assets should not be instantiated on their own. Instead,
  you use the BAssetManager's request system to retrieve a pointer to an asset.
*/

/*!
 * \brief Creates a new BAsset. You should not call this function. Use BAssetManager instead.
 */
BAsset::BAsset()
{

}

/*!
 * \brief Destroys a BAsset by calling release() if necessary.
 */
BAsset::~BAsset()
{

}
