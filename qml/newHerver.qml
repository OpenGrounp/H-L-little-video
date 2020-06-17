import Felgo 3.0
import QtQuick 2.0

App{

    onInitTheme: {
        Theme.navigationBar.backgroundColor = "blue"
        Theme.navigationBar.titleColor = "black"


        Theme.colors.textColor = "#000080"
    }

    Navigation {
        id: navigation
        navigationMode: navigationModeTabs

        NavigationItem {
            title: "Main"
            icon: IconType.heart

            NavigationStack {

                FlickablePage {
                    navigationBarHidden: true
                    Rectangle {
                        width: parent.width
                        height: parent.height
                        id: myList


                        ListModel {
                            id: model
                            ListElement {
                                name: "Bill Jones"
                                icon: "../assets/felgo-logo.png"
                            }
                            ListElement {
                                name: "Jane Doe"
                                icon: "../assets/felgo-logo.png"
                            }
                            ListElement {
                                name: "John Smith"
                                icon: "../assets/felgo-logo.png"
                            }
                            ListElement {
                                name: "Junwei Ma"
                                icon: "../assets/felgo-logo.png"
                            }
                        }

                        Component {
                            id: delegate
                            Column {
                                id: wrapper
                                opacity: PathView.isCurrentItem ? 1 : 0.5
//                                width: myList.width
//                                height: myList.height
                                Image {
                                    anchors.horizontalCenter: nameText.horizontalCenter
                                    width: 64; height: 64
                                    source: icon
                                }
                                Text {
                                    id: nameText
                                    text: name
                                    font.pointSize: 16
                                }
                            }
                        }

                        PathView {
                            anchors.fill: parent
                            pathItemCount: 3
                            model: model//ContactModel {}
                            delegate: delegate
                            path: Path {
                                startX: 120; startY: 50
                                PathLine { x: 120; y: 500}//; controlX: 260; controlY: 75 }
                                PathLine { x: 120; y: 1000}
                                PathLine { x: 120; y: 500}
                                //; controlX: -20; controlY: 75 }
                            }
                        }
                    }
                }
            }
        }


        NavigationItem {
            title: "Second"
            icon: IconType.thlarge

            NavigationStack {

                Page {
                    title: "Second Page"
                }
            }
        }
    }
}

