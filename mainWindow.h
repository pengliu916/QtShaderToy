#pragma once
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QMenu;
QT_END_NAMESPACE

class Communicator;
class TTYTextEdit;
class DX12RenderWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();


	void createMenus();
	void createDockWindows();

    QMenu* viewMenu;

	DX12RenderWidget*   renderWidget;
    TTYTextEdit*        ttyTextEdit;
    Communicator*       communicator;
};
