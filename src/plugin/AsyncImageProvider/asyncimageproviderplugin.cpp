#include "asyncimageprovider.h"
#include "asyncimageproviderplugin.h"

void AsyncImageProviderPlugin::initializeEngine(QQmlEngine *engine, const char *url)
{
    Q_UNUSED(url)
    engine->addImageProvider(QLatin1String("AsyncImageProvider"), new AsyncImageProvider);
}

void AsyncImageProviderPlugin::registerTypes(const char *url)
{
    Q_UNUSED(url)
}
