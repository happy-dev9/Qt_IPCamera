#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QNetworkAccessManager>
#include <QPushButton>


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
    QMediaPlayer *ipVideoPlayer;
    QMediaPlayer *localVideoPlayer;
    QAudioOutput *audioOutput;

    QVideoWidget *ipCameraVideoWidget;
    QVideoWidget *localVideoWidget;

    QPushButton *ipCameraVideoBtn;
    QPushButton *localVideoBtn;

public slots:
    void ipCameraVideoPlay();
    void localVideoPlay();

};
#endif // CAMERAWIDGET_H
