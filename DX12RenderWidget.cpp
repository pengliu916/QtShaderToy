#include "DX12RenderWidget.h"
#include "Communicator.h"

DX12RenderWidget::DX12RenderWidget(Communicator* commu,QWidget* parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_PaintOnScreen, true);
    setAttribute(Qt::WA_NativeWindow, true);

	this->setMinimumWidth( 320 );
	this->setMinimumHeight( 240 );

    InitGFXBackEnd(commu);
}

void DX12RenderWidget::InitGFXBackEnd (Communicator* commu)
{
	_gfxBackEndThread = new GFXBackEndThread ( commu, ( HWND ) winId (), this->width(),this->height() );
	_gfxBackEndThread->start ();
}

DX12RenderWidget::~DX12RenderWidget()
{
	_gfxBackEndThread->stop();
	_gfxBackEndThread->wait();
    delete _gfxBackEndThread;
}

QSize DX12RenderWidget::sizeHint() const
{
	return QSize( 800, 600 );
}

void DX12RenderWidget::paintEvent(QPaintEvent* evt)
{
	Q_UNUSED(evt);
}

void DX12RenderWidget::resizeEvent(QResizeEvent* evt)
{
	Q_UNUSED(evt);
	_gfxBackEndThread->resize ( this->width (), this->height () );
}
