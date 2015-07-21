#include <QtWidgets>
#include "DX12RenderWidget.h"

#include "mainwindow.h"
#include "qdebugstream.h"

MainWindow::MainWindow()
{
	createMenus();
	createDockWindows();

	QDebugStream qcout( std::cout, outputList, Qt::black );
	QDebugStream qcerr( std::cerr, outputList, Qt::red );

	std::cout << "std::cout is in Green!" << std::endl;
	std::cerr << "std::cerr is in Red!" << std::endl;

	setWindowTitle( tr( "DirectXFrame" ) );

	renderWidget = new DX12RenderWidget();
	setCentralWidget( renderWidget );
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

	outputList = new QTextEdit( dock );
	outputList->setLineWrapMode( QTextEdit::NoWrap );
	dock->setWidget( outputList );
	addDockWidget( Qt::BottomDockWidgetArea, dock );
	viewMenu->addAction( dock->toggleViewAction() );
}