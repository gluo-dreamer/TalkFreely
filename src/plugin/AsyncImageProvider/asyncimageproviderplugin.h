#ifndef ASYNCIMAGEPROVIDERPLUGIN_H
#define ASYNCIMAGEPROVIDERPLUGIN_H

#include <QQmlExtensionPlugin>

class AsyncImageProviderPlugin : public QQmlExtensionPlugin
{
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void initializeEngine(QQmlEngine *engine, const char *url) override;
    void registerTypes(const char *url) override;
};

#endif // ASYNCIMAGEPROVIDERPLUGIN_H
