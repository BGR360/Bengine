#include <asset/bassetcallback.h>
#include <asset/bassetmanager.h>
#include <asset/bmesh.h>

class MonkeyMesh : public BObject, public BAssetCallback
{
public:
    MonkeyMesh(BAssetManager* assetManager)
    {
        //! [requestAsset]
        // 'this' inherits BAssetCallback
        assetManager->requestAsset("content/meshes/monkey.obj",
                                   BMesh::getStaticClass(),
                                   this);
        //! [requestAsset]
    }

    // Overridden from BAssetCallback::onAssetLoaded()
    void onAssetLoaded(BAsset* asset) const Q_DECL_OVERRIDE
    {
        m_mesh = dynamic_cast<BMesh*>(asset);
    }

private:
    BMesh* m_mesh;
};

int main()
{
    //! [canLoadAsset]
    BAssetManager manager;
    qDebug() << manager.canLoadAsset("content/meshes/monkey.obj", BMesh::getStaticClass());
    // ^ should print true
    //! [canLoadAsset]

    return 0;
}
