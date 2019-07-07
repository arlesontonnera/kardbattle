import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls 2.5
//import Qml.Cpp_Deck 1.0

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("KardBattle")

    //    Cpp_Deck {
    //        id: cpp_Deck
    //        size: 15
    //    }

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem { text: qsTr("Open game") }
            MenuItem { text: qsTr("Save game") }
            MenuItem {
                text: qsTr("Quit")
                onTriggered: Qt.quit()
            }
        }
        Menu {
            title: qsTr("Edit")
            MenuItem { text: qsTr("Preferences") }
        }
    }
    TabView {
        width: parent.width
        height: parent.height
        visible: true
        SplitView {
            anchors.fill: parent
            orientation: Qt.Horizontal
            Rectangle {
                id: boardArea
                width: 400
                Layout.maximumWidth: 400
                color: "green"
                Grid {
                    anchors.centerIn: parent
                    columns: 4
                    spacing: 3
                    Repeater {
                        id: repeater
                        model: 16
                        Card {
                            id: boardCard
                            Component.onCompleted: { object.getPower(repeater.modelData); }
                            object: cpp_Board
                            sourceSize.width: 100
                            sourceSize.height: 100
                            Text {
                                anchors.horizontalCenter: parent.horizontalCenter
                                text: modelData
                                color: "blue"
                            }
                        }
                    }
                }
            }
            Rectangle {
                id: deckArea
                color: "lightgreen"
                Button {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "New Deck"
                    onClicked: {
                        cpp_Deck.setSize(15)//cpp_Deck.size = 15
                        cpp_Deck.getPower() //
                        cpp_Deck.getElement() //
                        cpp_Deck.getStatus() //
                        cpp_Deck.attackDirectionTop() //
                        cpp_Deck.attackDirectionRight() //
                        cpp_Deck.attackDirectionBottom() //
                        cpp_Deck.attackDirectionLeft() //
                    }
                }
                Card {
                    id: deckCard
                    anchors.centerIn: parent
                    object: cpp_Deck
                }
            }
        }
    }
}

