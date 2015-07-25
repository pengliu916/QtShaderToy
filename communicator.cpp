#include "Communicator.h"

Communicator::Communicator(QObject *parent) : QObject(parent)
{

}

void Communicator::printMessage(QString str, MessageType msgType)
{
	switch ( msgType )
	{
	case Communicator::MSG_WARNING:
	emit emitString( "<FONT COLOR = yellow>[ WARNING ]: " + str + "</FONT>" );
	break;
	case Communicator::MSG_ERROR:
	emit emitString( "<FONT COLOR = red>[ ERROR   ]: " + str + "</FONT>");
	break;
	case Communicator::MSG_INFO:
	default:
	emit emitString( "<FONT COLOR = green>[ INFO    ]: " + str + "</FONT>" );
	}

}
