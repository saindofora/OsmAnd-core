#ifndef _OSMAND_CORE_OBF_MAP_SECTION_READER_H_
#define _OSMAND_CORE_OBF_MAP_SECTION_READER_H_

#include <OsmAndCore/stdlib_common.h>
#include <functional>

#include <OsmAndCore/QtExtensions.h>
#include <QList>

#include <OsmAndCore.h>
#include <OsmAndCore/CommonTypes.h>
#include <OsmAndCore/Data/DataTypes.h>
#include <OsmAndCore/Map/MapTypes.h>

namespace OsmAnd
{
    class ObfReader;
    class ObfMapSectionInfo;
    namespace Model
    {
        class BinaryMapObject;
    }
    class IQueryController;
    namespace ObfMapSectionReader_Metrics
    {
        struct Metric_loadMapObjects;
    }

    class OSMAND_CORE_API ObfMapSectionReader
    {
    public:
        typedef std::function<bool (const std::shared_ptr<const OsmAnd::Model::BinaryMapObject>&)> VisitorFunction;

    private:
        ObfMapSectionReader();
        ~ObfMapSectionReader();
    protected:
    public:
        static void loadMapObjects(
            const std::shared_ptr<const ObfReader>& reader,
            const std::shared_ptr<const ObfMapSectionInfo>& section,
            const ZoomLevel zoom,
            const AreaI* const bbox31 = nullptr,
            QList< std::shared_ptr<const OsmAnd::Model::BinaryMapObject> >* resultOut = nullptr,
            MapFoundationType* foundationOut = nullptr,
            const FilterMapObjectsByIdFunction filterById = nullptr,
            const VisitorFunction visitor = nullptr,
            const IQueryController* const controller = nullptr,
            ObfMapSectionReader_Metrics::Metric_loadMapObjects* const metric = nullptr);
    };
}

#endif // !defined(_OSMAND_CORE_OBF_MAP_SECTION_READER_H_)
