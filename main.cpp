#include <QApplication>

#include "mainWindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    
	MainWindow *mainWin = new MainWindow();
	mainWin->show();
	
    return app.exec();
}