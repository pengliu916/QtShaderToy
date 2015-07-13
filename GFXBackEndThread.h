#pragma once

#include <QThread>

#include "DXGfxCore.h"

class GFXBackEndThread :public QThread
{
	Q_OBJECT
public:
	GFXBackEndThread(HWND _hwnd);
	void stop();
	void run();
private:
	DXGfxCore* _gfxCore;
	volatile bool stopped;
	//volatile bool needResize;
};