#pragma once

#include "GFXBackEndThread.h"

GFXBackEndThread::GFXBackEndThread( HWND _hwnd, uint16_t width, uint16_t height )
{
	_stopped = false;
	_needResize = true;

	_width = width;
	_height = height;
	_gfxCore = new DXGfxCore();
	_gfxCore->Init( _hwnd );
	_gfxCore->CreateDevice();
}

void GFXBackEndThread::stop()
{
	_stopped = true;
}

void GFXBackEndThread::run()
{
	while ( !_stopped )
	{
		if ( _needResize )
		{
			_needResize = false;
			_gfxCore->Resize( _width, _height );
		}
		_gfxCore->Update();
		_gfxCore->Render();
	}
	_gfxCore->Release();
	_gfxCore->Destory();
	delete _gfxCore;
}

void GFXBackEndThread::resize( uint16_t width, uint16_t height )
{
	_width = width;
	_height = height;
	_needResize = true;
}