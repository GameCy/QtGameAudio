TEMPLATE = app
TARGET = audiooutput

QT += multimedia widgets

HEADERS       = audiooutput.h \
    WavBuffer.h \
    AudioManager.h \
    AudioSample.h

SOURCES       = audiooutput.cpp \
                main.cpp \
    WavBuffer.cpp \
    AudioManager.cpp \
    AudioSample.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/multimedia/audiooutput
INSTALLS += target

RESOURCES += \
    resources.qrc
