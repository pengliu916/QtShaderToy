#pragma once
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QListWidget;
class QMenu;
QT_END_NAMESPACE

class DX12RenderWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();

private:
	void createMenus();
	void createDockWindows();

	DX12RenderWidget* renderWidget;
	QListWidget *outputList;

	QMenu *viewMenu;
};