import QtQuick 2.12

Image {
    Connections { //
        target: object
        onPowerChanged : { powerLabel.text = power; }
        onElementChanged : { elementLabel.text = "Element: " + element; }
        onStatusChanged : { statusLabel.text = "Status: " + status; }
        onAttackDirectionTopChanged : { attackDirectionTopLabel.text = attackDirectionTop ? "^" : ""; }
        onAttackDirectionRightChanged : { attackDirectionRightLabel.text = attackDirectionRight ? ">" : ""; }
        onAttackDirectionBottomChanged : { attackDirectionBottomLabel.text = attackDirectionBottom ? "v" : ""; }
        onAttackDirectionLeftChanged : { attackDirectionLeftLabel.text = attackDirectionLeft ? "<" : ""; }
    }
    property var object
    id: card
    //sourceSize.width: 200
    //sourceSize.height: 200
    source: "/images/card_background.png"
    Behavior on width {
        NumberAnimation { duration: 250 }
    }
    Behavior on height {
        NumberAnimation { duration: 250 }
    }
    Text {
        id: attackDirectionTopLabel
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        //text: object.attackDirectionTop ? "^" : ""
    }
    Text {
        id: attackDirectionRightLabel
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        //text: object.attackDirectionRight ? ">" : ""
    }
    Text {
        id: attackDirectionBottomLabel
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        //text: object.attackDirectionBottom ? "v" : ""
    }
    Text {
        id: attackDirectionLeftLabel
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        //text: object.attackDirectionLeft ? "<" : ""
    }
    Text {
        id: powerLabel
        anchors.centerIn: parent
        //text: object.power
        font.pointSize: 28
        color: "red"
    }
    Column {
        anchors.centerIn: parent
        anchors.verticalCenterOffset: 60
        Text {
            id: elementLabel
            //text: "Element: " + object.element
        }
        Text {
            id: statusLabel
            //text: "Status: " + object.status
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            card.width = 20
            card.height = 20
        }
    }
}
