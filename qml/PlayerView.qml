import QtQuick 2.15
import Qt.labs.qmlmodels 1.0

import PlayerViewControl 1.0

Item {
    id: root
    anchors.fill: parent

    function show( players ) {
        control.setup( players );
    }

    onWidthChanged: {
        tableView.forceLayout();
    }

    PlayerViewControl {
        id: control

        onClear: tableModel.clear();

        onSetRows: function ( players ) {
            tableModel.rows = players;
        }

    }

    Rectangle {
        id: header
        anchors.top: parent.top
        width: parent.width
        height: 40

        Row {
            anchors.fill: parent

            Repeater {
                id: repeater
                model: ["Type", "Speed", "Ammunition", "Active", "Coordinates" ]
                Rectangle {
                    height: parent.height
                    width: parent.width / 5
                    border.width: 1
                    border.color: "#bdc3c7"
                    color: "#ecf0f1"
                    Text {
                        anchors.centerIn: parent
                        text: modelData
                    }
                }
            }
        }
    }

    TableView {
          id: tableView
          anchors.top: header.bottom
          anchors.bottom: root.bottom
          width: parent.width
          columnSpacing: 1
          rowSpacing: 1

          model: TableModel {
              id: tableModel

              TableModelColumn { display: "playerType" }
              TableModelColumn { display: "speed" }
              TableModelColumn { display: "ammunition" }
              TableModelColumn { display: "active" }
              TableModelColumn { display: "numberOfCoordinates" }
          }

          delegate: Rectangle {
              implicitWidth: root.width / 5
              implicitHeight: 40

              Text {
                  text: model.display

                  anchors.centerIn: parent
              }
          }
    }
}
