#ifndef PLAYERVIEWCONTROL_H
#define PLAYERVIEWCONTROL_H

#include <QObject>
#include <QMap>
#include <QVariant>

class PlayerViewControl : public QObject
{
    Q_OBJECT
public:
    explicit PlayerViewControl(QObject *parent = nullptr);

public slots:
    void setup(const QVariantList& players);

signals:
    void clear();
    void setRows(QVariantList players);

};

#endif // PLAYERVIEWCONTROL_H
