# QtGameAudio
A simple implementation of music and sound effects playback in QT. 

It is light as it only uses QAudioOutput. It does not use the QMediaPlayer class.


Usage is very simple:
/*

    AudioManager* audioMan = new AudioManager();
    
    sample = new AudioSample(this, audioMan.Get(samplePath));

// to play continuesly

    sample.Loop(true); 

// to start playing

    sample.Start()
*/

//* ------------
//the remaining funcionality of the sample

    void Start();
    void Stop();
    
    void Pause();
    void Resume();
    
    bool isPlaying();
    bool isStoped();
    bool isPaused();

    void Loop(bool value);
    bool isLooping() const;

    void    SetVolume(qreal volume);
    qreal   GetVolume();
  ---- */
    
