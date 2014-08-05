#ifndef _OSMAND_CORE_ATLAS_MAP_RENDERER_INTERNAL_STATE_H_
#define _OSMAND_CORE_ATLAS_MAP_RENDERER_INTERNAL_STATE_H_

#include "stdlib_common.h"

#include "QtExtensions.h"

#include "OsmAndCore.h"
#include "CommonTypes.h"
#include "MapRendererInternalState.h"

namespace OsmAnd
{
    struct AtlasMapRendererInternalState : public MapRendererInternalState
    {
        virtual ~AtlasMapRendererInternalState();

        TileId targetTileId;
        PointF targetInTileOffsetN;
        QList<TileId> visibleTiles;
    };
}

#endif // !defined(_OSMAND_CORE_ATLAS_MAP_RENDERER_INTERNAL_STATE_H_)
