#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "asyncimageprovider.h"

AsyncImageResponse::AsyncImageResponse(const QString &id, const QSize &requestedSize)
    : m_qImageId(id)
    , m_qImageSize(requestedSize)
{
    setAutoDelete(false);
}

QQuickTextureFactory *AsyncImageResponse::textureFactory() const
{
    return QQuickTextureFactory::textureFactoryForImage(m_qImage);
}

void AsyncImageResponse::run()
{
    emit finished();
}

QQuickImageResponse *AsyncImageProvider::requestImageResponse(const QString &id, const QSize &requestedSize)
{
    AsyncImageResponse *responseRunable = new AsyncImageResponse(id, requestedSize);
    m_qThreadPool.start(responseRunable);
    return responseRunable;
}
