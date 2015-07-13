#pragma once
#include <QtWidgets>
#include "GFXBackEndThread.h"

class DX12RenderWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(DX12RenderWidget)
public:
    DX12RenderWidget(QWidget* parent = NULL);
    virtual ~DX12RenderWidget();

protected:
	QPaintEngine *paintEngine() const { return 0; }
    virtual void resizeEvent(QResizeEvent* evt);
    virtual void paintEvent(QPaintEvent* evt);
private:
	GFXBackEndThread* _gfxBackEndThread;
};