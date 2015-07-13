#include "DX12RenderWidget.h"

DX12RenderWidget::DX12RenderWidget(QWidget* parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_PaintOnScreen, true);
    setAttribute(Qt::WA_NativeWindow, true);
    
	_gfxBackEndThread = new GFXBackEndThread((HWND)winId());
	_gfxBackEndThread->start();
}

DX12RenderWidget::~DX12RenderWidget()
{
	_gfxBackEndThread->stop();
	_gfxBackEndThread->wait();
    delete _gfxBackEndThread;
}

void DX12RenderWidget::paintEvent(QPaintEvent* evt)
{
	Q_UNUSED(evt);
}

void DX12RenderWidget::resizeEvent(QResizeEvent* evt)
{
	Q_UNUSED(evt);
}