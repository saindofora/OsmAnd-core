#ifndef _OSMAND_CORE_DATA_TYPES_H_
#define _OSMAND_CORE_DATA_TYPES_H_

#include <OsmAndCore/stdlib_common.h>
#include <functional>

#include <OsmAndCore/QtExtensions.h>

#include <OsmAndCore.h>
#include <OsmAndCore/CommonTypes.h>

namespace OsmAnd
{
    class ObfMapSectionInfo;

    enum class ObfAddressBlockType
    {
        CitiesOrTowns = 1,
        Villages = 3,
        Postcodes = 2,
    };

    typedef std::function<bool (
        const std::shared_ptr<const ObfMapSectionInfo>& section,
        const uint64_t mapObjectId,
        const AreaI& bbox,
        const ZoomLevel firstZoomLevel,
        const ZoomLevel lasttZoomLevel)> FilterMapObjectsByIdFunction;
}

#endif // !defined(_OSMAND_CORE_DATA_TYPES_H_)
