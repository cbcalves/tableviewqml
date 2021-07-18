import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: "PlayerView"

    property var playersLoaded: undefined

    PlayerView {
        id: playerView
    }

    Component.onCompleted: {
        playerView.show(playersLoaded);
    }
}
