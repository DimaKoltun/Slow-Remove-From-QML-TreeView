import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4

Window {
    id: wind
    width: 320
    height: 240
    visible: true
    title: qsTr("Hello Tree View")

    ColumnLayout {
        TreeView {
            id: view
            model: assetModel

            TableViewColumn {
                    id: nameColumn
                    resizable: true
                    horizontalAlignment: Text.AlignLeft
                    title: "Name"
                    role: "display"
            }
        }

//        ListView {
//            id: view

//            width: 200
//            height: 175

//            model: assetModel

//            delegate: Text {
//                text: display
//            }
//        }

        Button {
            implicitWidth: 200
            text: "Remove 500 items from begin"
            onClicked: assetModel.removeFromBegin()
        }
    }
}
