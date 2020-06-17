import QtQuick 2.0
import Felgo 3.0
import QtMultimedia 5.12

App{

    NavigationStack{

        Page{
            navigationBarHidden: true
            id: player
            title: "Player"
            property int videoItem: 0

            function selectVideo(){

                var videoPath = ["rtmp://192.168.43.125/vod/01.mp4","rtmp://192.168.43.125/vod/05.mp4","rtmp://192.168.43.125/vod/07.mp4","rtmp://192.168.43.125/vod/02.mp4","rtmp://192.168.43.125/vod/03.mp4","rtmp://192.168.43.125/vod/04.mp4"]
                return videoPath[videoItem]
            }

            MediaPlayer {
                id: video
                autoPlay: true
                loops: MediaPlayer.Infinite
                source: "/root/myVideo/01.mp4"
            }

            VideoOutput {
                id: play
                anchors.fill: parent
                width: 30
                height: 50
                fillMode: VideoOutput.PreserveAspectFit
                source: video
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        video.playbackState === MediaPlayer.PlayingState ? video.pause(): video.play()
                    }
                }

            }

            Row{

                anchors.right: parent.right
                anchors.bottom: parent.bottom

                AppButton{
                    text: "pre"
                    onClicked: {
                        if (player.videoItem == 0){
                            player.videoItem = 5
                        } else{
                            var i = player.videoItem
                            player.videoItem = i - 1
                        }
                        video.source = player.selectVideo()
                    }
                }
                AppButton{
                    text: "next"
                    onClicked: {
                        if (player.videoItem == 5){
                            player.videoItem = 0
                        } else{
                            var i = player.videoItem
                            player.videoItem = i + 1
                        }
                        video.source = player.selectVideo()
                    }
                }
            }
        }


    }

}
