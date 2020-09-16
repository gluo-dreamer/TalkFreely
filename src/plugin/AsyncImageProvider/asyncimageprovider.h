#ifndef ASYNCIMAGEPROVIDER_H
#define ASYNCIMAGEPROVIDER_H

#include <QThreadPool>
#include <QQuickAsyncImageProvider>

class AsyncImageResponse : public QQuickImageResponse, public QRunnable
{
    Q_OBJECT

public:
    explicit AsyncImageResponse(const QString &id, const QSize &requestedSize);

    QQuickTextureFactory *textureFactory() const override;

protected:
    void run() override;

private:
    QString m_qImageId;
    QSize m_qImageSize;
    QImage m_qImage;
};

class AsyncImageProvider : public QQuickAsyncImageProvider
{
public:
    QQuickImageResponse *requestImageResponse(const QString &id, const QSize &requestedSize) override;

private:
    QThreadPool m_qThreadPool;
};

#endif // ASYNCIMAGEPROVIDER_H
