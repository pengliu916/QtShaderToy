#include <QApplication>

#include "DX12RenderWidget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    
	QMainWindow *mainWin = new QMainWindow;
    DX12RenderWidget * DXWidget = new DX12RenderWidget();
	mainWin->setCentralWidget(DXWidget);
	DXWidget->InitGFXBackEnd ();
	mainWin->show();
    
    return app.exec();
}