#include "ObfMapSectionReader.h"
#include "ObfMapSectionReader_P.h"

#include "ObfReader.h"

OsmAnd::ObfMapSectionReader::ObfMapSectionReader()
{
}

OsmAnd::ObfMapSectionReader::~ObfMapSectionReader()
{
}

void OsmAnd::ObfMapSectionReader::loadMapObjects(
    const std::shared_ptr<const ObfReader>& reader,
    const std::shared_ptr<const ObfMapSectionInfo>& section,
    const ZoomLevel zoom,
    const AreaI* const bbox31 /*= nullptr*/,
    QList< std::shared_ptr<const OsmAnd::Model::BinaryMapObject> >* resultOut /*= nullptr*/,
    MapFoundationType* foundationOut /*= nullptr*/,
    const FilterMapObjectsByIdFunction filterById /*= nullptr*/,
    const VisitorFunction visitor /*= nullptr*/,
    const IQueryController* const controller /*= nullptr*/,
    ObfMapSectionReader_Metrics::Metric_loadMapObjects* const metric /*= nullptr*/)
{
    ObfMapSectionReader_P::loadMapObjects(*reader->_p, section, zoom, bbox31, resultOut, foundationOut, filterById, visitor, controller, metric);
}
