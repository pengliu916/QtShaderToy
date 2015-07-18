#include <QtWidgets>
#include "DX12RenderWidget.h"

#include "mainwindow.h"

MainWindow::MainWindow()
{
	renderWidget = new DX12RenderWidget();
	setCentralWidget( renderWidget );

	createMenus();
	createDockWindows();

	setWindowTitle( tr( "DirectXFrame" ) );
}

void MainWindow::createMenus()
{
	viewMenu = menuBar()->addMenu( tr( "&View" ) );
}

void MainWindow::createDockWindows()
{
	QDockWidget *dock = new QDockWidget( tr( "Output" ), this );
	dock->setAllowedAreas( Qt::BottomDockWidgetArea 
						   | Qt::LeftDockWidgetArea 
						   | Qt::RightDockWidgetArea );

	outputList = new QListWidget( dock );
	outputList->addItems( QStringList()
						  << "Hello"
						  << "This is output debug screen" );
	dock->setWidget( outputList );
	addDockWidget( Qt::BottomDockWidgetArea, dock );
	viewMenu->addAction( dock->toggleViewAction() );
}