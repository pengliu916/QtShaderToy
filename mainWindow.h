#pragma once
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QTextEdit;
class QMenu;
QT_END_NAMESPACE

class DX12RenderWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();


	void createMenus();
	void createDockWindows();

	DX12RenderWidget* renderWidget;
	QTextEdit *outputList;

	QMenu *viewMenu;
};