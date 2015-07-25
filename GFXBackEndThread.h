#pragma once

#include <QThread>

#include "DXGfxCore.h"
class Communicator;
class GFXBackEndThread :public QThread
{
	Q_OBJECT
public:
    GFXBackEndThread(Communicator* commu, HWND _hwnd, uint16_t width, uint16_t height );
	void stop();
	void run();
	void resize(uint16_t width, uint16_t height);
	DXGfxCore* _gfxCore;

private:
	volatile bool _stopped;
	volatile bool _needResize;
	volatile bool _encounteredError;
	volatile uint16_t _width;
	volatile uint16_t _height;
};
