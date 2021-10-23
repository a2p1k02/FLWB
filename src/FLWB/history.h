#ifndef HISTORY_H
#define HISTORY_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

class History : public QObject
{
    Q_OBJECT
public:
    explicit History(QObject *parent = nullptr);

private:
    QFile* mHistoryJson;

public:
    void writeHistory(QVariantMap history);

};

#endif // HISTORY_H
