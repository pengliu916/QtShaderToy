#include <QtWidgets>
#include "DX12RenderWidget.h"

#include "mainwindow.h"
#include "Communicator.h"
#include "TTYTextEdit.h"

MainWindow::MainWindow()
{
    createMenus();
    createDockWindows();

    communicator = new Communicator();

    QObject::connect( communicator, SIGNAL(emitString(QString)), ttyTextEdit, SLOT( appendHtml( QString ) ) );

	renderWidget = new DX12RenderWidget( communicator );

	setWindowTitle( tr( "DirectXFrame" ) );

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

    ttyTextEdit = new TTYTextEdit( dock );
    dock->setWidget( ttyTextEdit );
	addDockWidget( Qt::BottomDockWidgetArea, dock );

	viewMenu->addAction( dock->toggleViewAction() );
}
