/********************************************
 * 本模块实现了json文件的读取，如果是第一次打开文件则会新建一个json文件，在后续使用过程中则会打开已经创建的json文件
 * 本模块读取的是视频资源的文件，以及保存视频的状态，包括视频路径，点赞人数，是否喜欢等
 * 时间：2019-06-24
 * 开发人员：
 *********************************************
 *********************************************/

#include "jsondata.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

JsonData::JsonData(QObject *parent) : QObject (parent){
}

void JsonData::newJson()
{
    QJsonObject video1;
    QJsonObject video2;
    QJsonObject video3;
    QJsonObject video4;
    QJsonObject video5;

    video1.insert("id",1);
    video1.insert("image_source" , "/root/01.png");
    video1.insert("video_source" , "rtmp://127.0.0.1/vod/01.mp4");
    video1.insert("isLike", false);
    video1.insert("heart_num", "20");
    video2.insert("id",2);
    video2.insert("video_source" , "rtmp://127.0.0.1/vod/02.mp4");
    video2.insert("image_source" , "/root/02.png");
    video2.insert("isLike", false);
    video2.insert("heart_num", "35");
    video3.insert("id",3);
    video3.insert("video_source" , "rtmp://127.0.0.1/vod/03.mp4");
    video3.insert("image_source" , "/root/03.png");
    video3.insert("isLike", false);
    video3.insert("heart_num", "10");
    video4.insert("id",4);
    video4.insert("video_source" , "rtmp://127.0.0.1/vod/04.mp4");
    video4.insert("image_source" , "/root/04.png");
    video4.insert("isLike", false);
    video4.insert("heart_num", "17");
    video5.insert("id",5);
    video5.insert("video_source" , "rtmp://127.0.0.1/vod/05.mp4");
    video5.insert("image_source" , "/root/05.png");
    video5.insert("isLike", false);
    video5.insert("heart_num", "19");

    jsondata.append(video1);
    jsondata.append(video2);
    jsondata.append(video3);
    jsondata.append(video4);
    jsondata.append(video5);
    if(!saveJson()){
        qDebug() << "save error";
    }
}

bool JsonData::loadJson()
{

    QFile loadFile(QStringLiteral("02.json"));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    read(loadDoc.object());

    QTextStream(stdout) << "Loaded save for "
                        << loadDoc["video"][1]["heart_num"].toInt()
                        << " using "
                        << "JSON...\n";
    return true;

}

bool JsonData::saveJson(){
    QFile saveFile(QStringLiteral("02.json"));

    if(!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.....");
        return false;
    }

    QJsonObject testObject;
    write(testObject);
    QJsonDocument saveDoc(testObject);
    saveFile.write(saveDoc.toJson());

    QTextStream(stdout) << "Loaded save for "
                        //<< saveDoc["video"][0]["isLike"].toBool()
                        <<" using JSON ... END1\n";

    return true;
}

void JsonData::read(const QJsonObject &json)
{
    if(json.contains("video") && json["video"].isArray()){
        jsondata = json["video"].toArray();
        qDebug() << "This Video is array";
    }
}


QJsonArray JsonData::getJsonData()
{
    if(!loadJson()){
        newJson();
        if(loadJson()){
            qDebug() << "getMyNewData()";
            return jsondata;
        }
    }else {
        qDebug() << "getMyOldData()";
        return jsondata;
    }
    QTextStream(stdout) << "Here is error\n";
    QJsonArray my;
    return my;
}

void JsonData::setJsonData(QJsonArray &json)
{
    jsondata = json;
    if(!saveJson()){
        qDebug() << "save error";
    }
    //emit dataChanged();
}

void JsonData::write(QJsonObject &json) const
{
    QJsonArray jsonarray;
    for (int index = 0; index < jsondata.size(); index++) {
        QJsonObject onevideo;
        onevideo = jsondata[index].toObject();
         //qDebug() << jsonData[index]["isLike"];
        jsonarray.append(onevideo);
    }
    json["video"] = jsonarray;
}

void JsonData::dataUpdate()
{
    if(!saveJson()){
        qDebug() << "save error";
    }
}

