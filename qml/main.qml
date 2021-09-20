import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Dialogs 1.3
import "." // QTBUG-34418, singletons require explicit import to load qmldir file

ApplicationWindow
{
    id: myApplicationWindow
    property int myTheme: 1; // Light = 1 or Dark = 0
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Translator")
    /************************************************
     * @brief onCompleted.
     * onCompleted
     * Check theme on start up
     ***********************************************/
    Component.onCompleted:
    {
        switch(myTheme)
        {
        case 0: // "Dark"
            doTheme(0);
            break;
        case 1: // "Light"
        default:
            doTheme(1);
        } // end switch
    } // end onCompleted
    /************************************************
     * @brief doTheme.
     * doTheme
     * https://doc.qt.io/qt-5/qml-color.html
     ***********************************************/
    function doTheme(myTheme)
    {
        switch(myTheme)
        {
        case 0: // Material.Dark
            Material.theme                     = Material.Dark
            Material.accent                    = Material.Blue;
            Style.textColor                    = "black";
            Style.altTextColor                 = "white";
            Style.textEditColor                = "white";
            Style.textColorFocus               = "lightgrey";
            Style.textColorNoFocus             = "darkgrey";
            Style.textColorError               = "red";
            Style.textColorWarning             = "purple";
            Style.textColorCaution             = "gold";
            Style.textColorQuestion            = "green";
            Style.borderColor                  = "black"
            Style.gradientColorStart           = "lightsteelblue"
            Style.gradientColorStop            = "blue"
            Style.backgroundColor              = "grey"
            Style.altBackgroundColor           = "lightgrey"
            Style.buttonColorForground         = "darkgreen"
            Style.buttonColorBackground        = "lightgreen"
            Style.comboBoxArrowColorNormal     = "darkgreen"
            Style.comboBoxArrowColorPressed    = "purple"
            console.debug("Main doTheme theme change = Material.Dark");
            break;
        case 1: // Material.Light
        default:
            Material.theme                     = Material.Light
            Material.accent                    = Material.Purple;
            Style.textColor                    = "blue";
            Style.altTextColor                 = "steelblue";
            Style.textEditColor                = "black";
            Style.textColorFocus               = "lightgoldenrodyellow";
            Style.textColorNoFocus             = "lightskyblue";
            Style.textColorError               = "red";
            Style.textColorWarning             = "purple";
            Style.textColorCaution             = "gold";
            Style.textColorQuestion            = "green";
            Style.borderColor                  = "black"
            Style.gradientColorStart           = "lightsteelblue"
            Style.gradientColorStop            = "blue"
            Style.backgroundColor              = "aliceblue"
            Style.altBackgroundColor           = "lightsteelblue"
            Style.buttonColorForground         = "darkgreen"
            Style.buttonColorBackground        = "lightgreen"
            Style.comboBoxArrowColorNormal     = "green"
            Style.comboBoxArrowColorPressed    = "red"
            console.debug("Main doTheme theme change = Material.Light");
        } // end switch
    } // end doTheme

    menuBar: MenuBar
    {
        id: myMenuBar

        Menu
        {
            id: myMenuQuit
            title: qsTr("&File")
            MenuItem
            {
                text: qsTr("&About")
                onTriggered: messageDialogAbout.visible = true
            }
            MenuItem
            {
                text: qsTr("&Quit")
                onTriggered: Qt.quit()
            }
        } // end myMenuQuit
        Menu
        {
            id: myHelp
            title: qsTr("&Help")
            Menu
            {
                cascade: true  // Nested menu
                title: qsTr("&Theme")
                Action
                {
                    text: qsTr("Light")
                    onTriggered: doTheme(1)
                }
                Action
                {
                    text: qsTr("Dark")
                    onTriggered: doTheme(0)
                }
            }
            Menu
            {
                id: myMenu
                title: qsTr("&Language")
                cascade: true  // Nested menu
                // onTriggered
                function onTriggered(item)
                {
                    console.log(item.text);
                    thisLanguageModel.setLanguage(item.text);
                    comboBoxLanguage.currentIndex = comboBoxLanguage.find(item.text);
                }
                // myMenu.onFillMenu()
                function onFillMenu()
                {
                    var lanugageNames = thisLanguageList;
                    console.debug("onFillMenu=" + lanugageNames);
                    for(var i in lanugageNames)
                    {
                        var item = Qt.createQmlObject('import QtQuick 2.13; import QtQuick.Controls 2.13; MenuItem {}', myMenu)
                        item.text = lanugageNames[i]
                        myMenu.addItem(item)
                        var f = function(it)
                        {
                            it.triggered.connect(function (){ myMenu.onTriggered(it)
                        })}
                        f(item)
                    } // end for(var i in lanugageNames)
                } // end myMenu.onFillMenu()
            } // end myMenu
            MenuItem
            {
                text: qsTr("&About")
                onTriggered: messageDialogAbout.visible = true
            }
            MenuItem
            {
                text: qsTr("&Help")
                onTriggered: messageDialogHelp.visible = true
            }
        } // end myHelp
    } // end myMenuBar
    /************************************************
     * @brief About MessageDialog.
     * messageDialogAbout
     ***********************************************/
    MessageDialog
    {
        id: messageDialogAbout
        title: "About"
        text: "This is an Example of using Qt Translation."
        onAccepted:
        {
            console.log("messageDialogAbout: Ok")
        }
    }
    /************************************************
     * @brief Help MessageDialog.
     * messageDialogHelp
     ***********************************************/
    MessageDialog
    {
        id: messageDialogHelp
        title: "Help"
        text: "This is a QML Example App using Qt Translation."
        onAccepted:
        {
            console.log("messageDialogHelp: Ok")
        }
    }
    /************************************************
     * @brief Rectangle.
     * Rectangle
     ***********************************************/
    Rectangle
    {
        id: pageRectangle
        color: Style.backgroundColor
        anchors.fill: parent
        y: 20
        /************************************************
        * @brief CustomComboBox.
        * Rectangle
        ***********************************************/
        Rectangle
        {
            id: backgroundComboBoxLanguage
            height: 42
            Text
            {
                id: appTextLanguage
                color: Style.textColor
                font.pointSize: Style.textSize
                text: qsTr("Language")
                visible: true
                leftPadding: 16
                wrapMode: Text.NoWrap
            }
            /************************************************
            * @brief comboBox Body.
            * ComboBox comboBoxBody
            ***********************************************/
            ComboBox
            {
                id: comboBoxLanguage
                model: thisLanguageModel
                textRole : "name"
                valueRole: "translation"
                width: 266
                height: 42
                font.pointSize: 16
                x: appTextLanguage.width + 6
                wheelEnabled: true
                currentIndex: 0
                delegate: ItemDelegate
                {
                    id: itemDelegate
                    width: comboBoxLanguage.width + 66
                    text: comboBoxLanguage.textRole ? (Array.isArray(comboBoxLanguage.model) ? modelData[comboBoxLanguage.textRole] + " " + modelData[comboBoxLanguage.valueRole] : model[comboBoxLanguage.textRole]+ " " + model[comboBoxLanguage.valueRole]) : modelData
                    font.weight: comboBoxLanguage.currentIndex === model.index ? Font.DemiBold : Font.Normal
                    highlighted: comboBoxLanguage.highlightedIndex === model.index
                    hoverEnabled: comboBoxLanguage.hoverEnabled

                    contentItem: Label
                    {
                        text: itemDelegate.text
                        font: itemDelegate.font
                        elide: Label.ElideRight
                        verticalAlignment: Label.AlignVCenter
                    }
                }

                indicator: Canvas
                {
                    id: myCanvas
                    x: comboBoxLanguage.width - width - comboBoxLanguage.rightPadding
                    y: comboBoxLanguage.topPadding + (comboBoxLanguage.availableHeight - height) / 2
                    width: 12
                    height: 8
                    contextType: "2d"

                    Connections
                    {
                        target: comboBoxLanguage
                        function onPressedChanged() { myCanvas.requestPaint(); }
                    }

                    onPaint:
                    {
                        context.reset();
                        context.moveTo(0, 0);
                        context.lineTo(width, 0);
                        context.lineTo(width / 2, height);
                        context.closePath();
                        context.fillStyle = comboBoxLanguage.pressed ? Style.comboBoxArrowColorPressed : Style.comboBoxArrowColorNormal;
                        context.fill();
                    }
                }
                onCurrentIndexChanged:
                {
                    console.debug(comboBoxLanguage.textAt(currentIndex));
                    comboBoxLanguage.model.setLanguage(comboBoxLanguage.textAt(currentIndex));
                }
                Component.onCompleted:
                {
                    // FIXME remember
                    comboBoxLanguage.currentIndex = comboBoxLanguage.find(thisDefaultLanguageName);
                    console.debug("Current: " + comboBoxLanguage.currentText + " Default: " + thisDefaultLanguageName + " Current Index: " + comboBoxLanguage.find(thisDefaultLanguageName));
                    myMenu.onFillMenu();
                }
            } // end ComboBox
        } // end backgroundComboBoxLanguage
    } // end pageRectangle
} // end myApplicationWindow
