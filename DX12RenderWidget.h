#pragma once
#include <QtWidgets>
#include "GFXBackEndThread.h"

class Communicator;
class DX12RenderWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(DX12RenderWidget)
public:
    DX12RenderWidget(Communicator*, QWidget* parent = NULL);
    virtual ~DX12RenderWidget();
    void InitGFXBackEnd (Communicator*);

	virtual QSize sizeHint() const;

protected:
	QPaintEngine *paintEngine() const { return 0; }
    virtual void resizeEvent(QResizeEvent* evt);
    virtual void paintEvent(QPaintEvent* evt);

private:
	GFXBackEndThread* _gfxBackEndThread;
};
