
///
/// ::: Sample media player | Main component :::
///

import QtQuick
import QtQuick.Window
import QtMultimedia

import SamplePlayer

Window {

  width: 1280
  height: 720

  title: "SamplePlayer"

  visible: true

  VideoOutput {
    id: sampleOutput
    anchors.fill: parent
  }

  SamplePlayer {
    id: samplePlayer
    source: 'file:///home/sample_media_player/sample.mp4'
    videoOutput: sampleOutput
  }

  Component.onCompleted: {
    samplePlayer.play()
  }

  Shortcut {
    sequence: "P"
    onActivated: samplePlayer.play()
  }

  Shortcut {
    sequence: "S"
    onActivated: samplePlayer.stop()
  }

  Shortcut {
    sequence: "Q"
    onActivated: Qt.exit(0)
  }
}

