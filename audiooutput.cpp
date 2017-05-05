#include <QAudioDeviceInfo>
#include <QAudioOutput>
#include <QDebug>
#include <QVBoxLayout>

#include "audiooutput.h"
#include "AudioManager.h"

AudioManager audioMan;


AudioTest::AudioTest()
{
    initializeWindow();
}

void AudioTest::initializeWindow()
{
    QScopedPointer<QWidget> window(new QWidget);
    QVBoxLayout* layout = new QVBoxLayout;

    box1 = new SoundBox(layout, "Music"   ,":/Res/music.wav");
    box2 = new SoundBox(layout, "Buzzer"  ,":/Res/buzzer.wav");
    box3 = new SoundBox(layout, "Laugh"   ,":/Res/laugh.wav");
    box4 = new SoundBox(layout, "Paahh"   ,":/Res/paahh.wav");
    box5 = new SoundBox(layout, "Punch"   ,":/Res/punch.wav");
    box6 = new SoundBox(layout, "trumpet" ,":/Res/trumpet.wav");

    QScopedPointer<QVBoxLayout> scopedLayout(layout);
    window->setLayout(scopedLayout.data());
    scopedLayout.take(); // ownership transferred

    setCentralWidget(window.data());
    QWidget *const windowPtr = window.take(); // ownership transferred
    windowPtr->show();
}

AudioTest::~AudioTest()
{
}


SoundBox::SoundBox(QVBoxLayout *parent, QString text, QString samplePath)
{

    button = new QPushButton();
    button->setText(text);
    connect(button, &QPushButton::clicked, this, &SoundBox::PlaySample);
    parent->addWidget(button);

    volumeLabel = new QLabel;
    volumeLabel->setText("Volume");
    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setMinimum(0);
    volumeSlider->setMaximum(100);
    volumeSlider->setSingleStep(10);
    connect(volumeSlider, &QSlider::valueChanged, this, &SoundBox::volumeChanged);

    QHBoxLayout *volumeBox = new QHBoxLayout;
    volumeBox->addWidget(volumeLabel);
    volumeBox->addWidget(volumeSlider);

    parent->addLayout(volumeBox);

    sample = new AudioSample(this, audioMan.Get(samplePath));
    volumeSlider->setValue(int(sample->GetVolume()*100.0f));
}

void SoundBox::PlaySample()
{
    if (!sample->isPlaying())
        sample->Start();

}

void SoundBox::volumeChanged(int vol)
{
    if (sample)
        sample->SetVolume(qreal(vol/100.0f));
}
