
#pragma once

///
/// ::: SamplePlayer | Interface :::
///

#include <QtMultimedia/QMediaPlayer>
#include <QtQml>

class SamplePlayer : public QMediaPlayer {

  Q_OBJECT

  QML_ELEMENT

  public:
    SamplePlayer(QObject* parent = nullptr);
   ~SamplePlayer( );
};

