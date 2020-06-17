#ifndef JSONDATA_H
#define JSONDATA_H

#include <QString>
#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

class JsonData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QJsonArray jsontata READ getJsonData WRITE setJsonData NOTIFY dataChanged)
    //Q_PROPERTY(bool isLike WRITE setIsLike)

public:
    JsonData(QObject *parent = nullptr);

    QJsonArray getJsonData();
    void setJsonData(QJsonArray &json);

    bool loadJson();
    bool saveJson();
    void newJson();

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

signals:
    void dataChanged();

public slots:
    void dataUpdate();

private:
    QJsonArray jsondata;
};


#endif // JSONDATA_H
