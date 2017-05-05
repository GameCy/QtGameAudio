#ifndef AUDIOOUTPUT_H
#define AUDIOOUTPUT_H
#include <math.h>
#include <QByteArray>
#include <QComboBox>
#include <QIODevice>
#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QSlider>
#include <QTimer>
#include "AudioSample.h"
#include <QVBoxLayout>

class SoundBox : public QObject
{
    Q_OBJECT
public:
    SoundBox(QVBoxLayout *parent, QString text, QString samplePath);

    QPushButton *button;
    QLabel      *volumeLabel;
    QSlider     *volumeSlider;

    AudioSample* sample;

private slots:
    void PlaySample();
    void volumeChanged(int vol);
};


class AudioTest : public QMainWindow
{
    Q_OBJECT

public:
    AudioTest();
    ~AudioTest();

private:
    void initializeWindow();

    SoundBox*  box1;
    SoundBox*  box2;
    SoundBox*  box3;
    SoundBox*  box4;
    SoundBox*  box5;
    SoundBox*  box6;
};

#endif // AUDIOOUTPUT_H
