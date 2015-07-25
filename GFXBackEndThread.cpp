#pragma once
#include <iostream>
#include "GFXBackEndThread.h"

GFXBackEndThread::GFXBackEndThread(Communicator* commu, HWND _hwnd, uint16_t width, uint16_t height )
{
	_stopped = false;
	_needResize = true;

	_width = width;
	_height = height;
    _gfxCore = new DXGfxCore(commu);
	_gfxCore->Init( _hwnd );
	_encounteredError = FAILED(_gfxCore->CreateDevice());
}

void GFXBackEndThread::stop()
{
	_stopped = true;
}

void GFXBackEndThread::run()
{
	while ( !_stopped && !_encounteredError )
	{
		static long long framecount = 0;
		if ( _needResize )
		{
			_needResize = false;
			_encounteredError = FAILED( _gfxCore->Resize( _width, _height ) );
		}
		_gfxCore->Update();
		_gfxCore->Render();
		framecount++;
		if ( framecount % 500 == 0 )
		{
			std::cout << "frame: " << framecount << std::endl;
		}
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
