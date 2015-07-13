#pragma once

#include "GFXBackEndThread.h"

GFXBackEndThread::GFXBackEndThread(HWND _hwnd)
{
	stopped = false;
	//needResize = true;

	_gfxCore = new DXGfxCore();
	_gfxCore->Init(_hwnd);
	_gfxCore->CreateDevice();
}

void GFXBackEndThread::stop()
{
	stopped = true;
}

void GFXBackEndThread::run()
{
	while (!stopped)
	{
		_gfxCore->Update();
		_gfxCore->Render();
	}
	_gfxCore->Release();
	_gfxCore->Destory();
	delete _gfxCore;
}

