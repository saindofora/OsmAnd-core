#ifndef _OSMAND_CORE_ATLAS_MAP_RENDERER_H_
#define _OSMAND_CORE_ATLAS_MAP_RENDERER_H_

#include "stdlib_common.h"

#include "QtExtensions.h"

#include "OsmAndCore.h"
#include "CommonTypes.h"
#include "MapRenderer.h"
#include "IAtlasMapRenderer.h"
#include "MapRendererResourcesManager.h"

namespace OsmAnd
{
    class AtlasMapRenderer
        : public MapRenderer
        , public IAtlasMapRenderer
    {
        Q_DISABLE_COPY(AtlasMapRenderer);

    private:
        // General:
        QSet<TileId> _uniqueTiles;
    protected:
        AtlasMapRenderer(GPUAPI* const gpuAPI);

        // Configuration-related:
        virtual std::shared_ptr<MapRendererConfiguration> allocateConfiguration() const;
        enum class ConfigurationChange
        {
            ReferenceTileSize = (MapRenderer::RegisteredConfigurationChangesCount),

            __LAST
        };
        enum {
            RegisteredConfigurationChangesCount = static_cast<unsigned int>(ConfigurationChange::__LAST)
        };
        virtual uint32_t getConfigurationChangeMask(
            const std::shared_ptr<const MapRendererConfiguration>& current,
            const std::shared_ptr<const MapRendererConfiguration>& updated) const;
        virtual void invalidateCurrentConfiguration(const uint32_t changesMask);

        // State-related:
        virtual bool updateInternalState(
            MapRendererInternalState& outInternalState,
            const MapRendererState& state,
            const MapRendererConfiguration& configuration);

        // Customization points:
        virtual bool prePrepareFrame();
        virtual bool postPrepareFrame();
    public:
        virtual ~AtlasMapRenderer();

        virtual QList<TileId> getVisibleTiles() const;
        virtual unsigned int getVisibleTilesCount() const;
    };
}

#endif // !defined(_OSMAND_CORE_ATLAS_MAP_RENDERER_H_)