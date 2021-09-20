pragma Singleton
import QtQuick 2.15

/************************************************
 * @brief adjust colors in Main.qml doTheme().
 * QtObject
 * https://doc.qt.io/qt-5/qml-color.html
 ***********************************************/
QtObject
{
    property int textSize: 20
    property color textColor:                   "lightsteelblue"
    property color altTextColor:                "blue"
    property color textEditColor:               "black"
    property color textColorFocus:              "red"
    property color textColorNoFocus:            "green"
    property color textColorError:              "red"
    property color textColorWarning:            "purple"
    property color textColorCaution:            "yellow"
    property color textColorQuestion:           "green"
    property color borderColor:                 "black"
    property color gradientColorStart:          "lightsteelblue"
    property color gradientColorStop:           "blue"
    property color backgroundColor:             "aliceblue"
    property color altBackgroundColor:          "lightsteelblue"
    property color buttonColorForground:        "darkgreen"
    property color buttonColorBackground:       "lightgreen"
    property color comboBoxArrowColorNormal:    "green"
    property color comboBoxArrowColorPressed:   "red"
}
/******************************* End of File *********************************/

