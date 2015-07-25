#pragma once

#include <QObject>



class Communicator : public QObject
{
    Q_OBJECT
public:

    enum MessageType
    {
		MSG_WARNING = 0,
		MSG_ERROR,
        MSG_INFO,

        MESSAGETYPECOUNT,
    };

    struct MsgHead
    {
        MessageType type;
        const QChar* msgHead;
    };

    explicit Communicator(QObject *parent = 0);

    void printMessage(QString, MessageType = MSG_INFO );

signals:
    void emitString(QString);
};

