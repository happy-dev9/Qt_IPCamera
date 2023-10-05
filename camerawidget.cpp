#include "camerawidget.h"
#include "QBuffer"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QAudioDevice"
#include "QTableView"
#include "QFileDialog"


CameraWidget::CameraWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(QSize(800, 600));

    // create players
    ipVideoPlayer = new QMediaPlayer;
    localVideoPlayer = new QMediaPlayer;

    // create layout items
    ipCameraVideoWidget = new QVideoWidget;
    localVideoWidget = new QVideoWidget;

    ipCameraVideoBtn = new QPushButton("Camera Play");
    localVideoBtn = new QPushButton("Load Video");

    //set audio for local video audio output
    audioOutput = new QAudioOutput;
    audioOutput->setVolume(50.0);

    // Set UI layout
    QVBoxLayout *vlayout = new QVBoxLayout;

    QHBoxLayout *hVideoLayout = new QHBoxLayout;
    hVideoLayout->addWidget(ipCameraVideoWidget);
    hVideoLayout->addWidget(localVideoWidget);

    QHBoxLayout *hButtonLayout = new QHBoxLayout;
    hButtonLayout->addWidget(ipCameraVideoBtn);
    hButtonLayout->addWidget(localVideoBtn);

    vlayout->addLayout(hVideoLayout);
    vlayout->addLayout(hButtonLayout);

    setLayout(vlayout);


    //connect slots and events
    connect (ipCameraVideoBtn, &QPushButton::clicked, this, &CameraWidget::ipCameraVideoPlay);
    connect (localVideoBtn, &QPushButton::clicked, this, &CameraWidget::localVideoPlay);

}


void CameraWidget::ipCameraVideoPlay(){
    ipVideoPlayer->setSource(QUrl("http://takemotopiano.aa1.netvolante.jp:8190/nphMotionJpeg?Resolution=640x480&Quality=Standard&Framerate=30"));
                                //E:/AI_Chatbot_spark_selling/Automate Your Social Media Using These Ai Tools.mp4
                                //http://takemotopiano.aa1.netvolante.jp:8190/nphMotionJpeg?Resolution=640x480&Quality=Standard&Framerate=30
                                //http://158.58.130.148/mjpg/video.mjpg
    ipVideoPlayer->setVideoOutput(ipCameraVideoWidget);
    ipVideoPlayer->play();
    ipCameraVideoBtn->setDisabled(true);
}


void CameraWidget::localVideoPlay(){

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Videos (*.avi *.mp4 *.mvi)"));
    localVideoPlayer->setSource(fileName);
    localVideoPlayer->setVideoOutput(localVideoWidget);
    localVideoPlayer->play();
    localVideoBtn->setDisabled(true);
}


CameraWidget::~CameraWidget()
{
    //delete ui;
}

