#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class CameraWidget; }
QT_END_NAMESPACE

class CameraWidget : public QWidget
{
    Q_OBJECT

public:
    CameraWidget(QWidget *parent = nullptr);
    ~CameraWidget();

private:
    Ui::CameraWidget *ui;

public:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QAudioOutput *audioOutput;
    QNetworkAccessManager *networkManager;




};
#endif // CAMERAWIDGET_H
