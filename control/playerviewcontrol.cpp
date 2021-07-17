#include "playerviewcontrol.h"

#include <QMetaType>
#include <QMetaProperty>

#include "players/player.h"

PlayerViewControl::PlayerViewControl(QObject *parent) :
    QObject(parent)
{

}

void PlayerViewControl::setup(const QVariantList &players)
{
    emit clear();

    if (players.isEmpty()) {
        return;
    }

    const QMetaObject *metaObject = QMetaType::metaObjectForType(players[0].userType());

    QVariantList playersMapped;

    for (const auto& player : players) {
        QVariantMap playersMap({});
        for (int i = 0; i < metaObject->propertyCount(); ++i) {
            QMetaProperty metaProperty = metaObject->property(i);
            QVariant read = metaProperty.readOnGadget(player.data());
            playersMap.insert(metaProperty.name(), read);
        }
        playersMapped.append(playersMap);
    }

    emit setRows(playersMapped);
}
