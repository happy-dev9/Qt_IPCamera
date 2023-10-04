#include "camerawidget.h"
#include "QBuffer"
#include "QVBoxLayout"
#include "QAudioDevice"

CameraWidget::CameraWidget(QWidget *parent)
    : QWidget(parent)
{

    player = new QMediaPlayer;
    player->setSource(QUrl("http://takemotopiano.aa1.netvolante.jp:8190/nphMotionJpeg?Resolution=640x480&Quality=Standard&Framerate=30"));
    //E:/AI_Chatbot_spark_selling/Automate Your Social Media Using These Ai Tools.mp4


    videoWidget = new QVideoWidget;
    networkManager = new QNetworkAccessManager(this);
    audioOutput = new QAudioOutput;
    audioOutput->setVolume(50.0);

    // Set the video widget as the central widget of the QWidget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(videoWidget);
    setLayout(layout);

    // Set the video output for the player to the video widget
    player->setVideoOutput(videoWidget);
    player->setAudioOutput(audioOutput);


    player->play();




}


CameraWidget::~CameraWidget()
{
    //delete ui;
}

