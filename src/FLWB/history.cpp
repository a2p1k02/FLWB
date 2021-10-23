#include "history.h"

History::History(QObject *parent) : QObject(parent) {}

void History::writeHistory(QVariantMap history)
{
    QJsonObject historyObj = QJsonObject::fromVariantMap(history);

    mHistoryJson = new QFile("history.json");
    mHistoryJson->open(QIODevice::WriteOnly | QIODevice::Append);

    mHistoryJson->write(QJsonDocument(historyObj).toJson());
    mHistoryJson->close();
}
