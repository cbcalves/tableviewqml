import QtQuick 2.15
import Qt.labs.qmlmodels 1.0

import PlayerViewControl 1.0

Item {
    id: root
    anchors.fill: parent

    function show( players ) {
        control.setup( players );
    }

    PlayerViewControl {
        id: control

        onClear: tableModel.clear();

        onSetRows: function ( players ) {
            console.error(JSON.stringify(players));
            tableModel.rows = players;
        }

    }

    TableView {
          anchors.fill: parent
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
              implicitWidth: 100
              implicitHeight: 50

              Text {
                  text: model.display

                  anchors.centerIn: parent
              }
          }
    }
}
