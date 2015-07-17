#pragma once

#include <QThread>

#include "DXGfxCore.h"

class GFXBackEndThread :public QThread
{
	Q_OBJECT
public:
	GFXBackEndThread(HWND _hwnd, uint16_t width, uint16_t height );
	void stop();
	void run();
	void resize(uint16_t width, uint16_t height);

private:
	DXGfxCore* _gfxCore;
	volatile bool _stopped;
	volatile bool _needResize;
	volatile uint16_t _width;
	volatile uint16_t _height;
};