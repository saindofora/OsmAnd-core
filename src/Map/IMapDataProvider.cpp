#include "IMapDataProvider.h"

OsmAnd::IMapDataProvider::IMapDataProvider()
{
}

OsmAnd::IMapDataProvider::~IMapDataProvider()
{
}

OsmAnd::IMapDataProvider::RetainableCacheMetadata::~RetainableCacheMetadata()
{
}

OsmAnd::IMapDataProvider::Data::Data(const RetainableCacheMetadata* const pRetainableCacheMetadata /*= nullptr*/)
{
}

OsmAnd::IMapDataProvider::Data::~Data()
{
    release();
}

void OsmAnd::IMapDataProvider::Data::release()
{
    if (!retainableCacheMetadata)
        return;

    retainableCacheMetadata.reset();
}


OsmAnd::IMapDataProvider::Request::Request()
{
}

OsmAnd::IMapDataProvider::Request::Request(const Request& that)
{
    copy(*this, that);
}

OsmAnd::IMapDataProvider::Request::~Request()
{
}

void OsmAnd::IMapDataProvider::Request::copy(Request& dst, const Request& src)
{
    dst.queryController = src.queryController;
}
