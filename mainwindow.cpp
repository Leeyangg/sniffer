// =====================================================================================
// 
//       Filename:  mainwindow.cpp
//
//    Description:  主窗口的类实现文件
//
//        Version:  1.0
//        Created:  2013年01月20日 17时06分16秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow()		
{
	createActions();
	createMenus();
	createContextMenu();
	createToolBars();
	createStatusBar();

	setWindowIcon(QIcon(":/res/ico/main.png"));
	setWindowTitle(tr("Sniffer -- 测试版"));
}

MainWindow::~MainWindow()		
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	if (isToContinue()) {
		//writeSettings();
		event->accept();
	} else {
		event->ignore();
	}
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("关于 Sniffer"),
            tr("<h2>Sniffer 测试版</h2>"
               "<p>Copyright (C) 2013 Class 1107 of Computer Science and Technology"
               "<p>一个跨平台的网络数据嗅探&抓包程序，基于Qt 4.x 以及 libpcap 库"
               "（Linux下）和 Winpcap库（Windows 下）。"));
}

void MainWindow::createActions()
{
	newAction = new QAction(tr("新建"), this);
	newAction->setIcon(QIcon(":/res/images/new.png"));
	newAction->setShortcut(QKeySequence::New);
	newAction->setStatusTip(tr("创建一个新的捕获（清空历史）"));
	connect(newAction, SIGNAL(triggered()), this, SLOT(about()));

	openAction = new QAction(tr("打开"), this);
	openAction->setIcon(QIcon(":/res/images/open.png"));
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr("打开历史的一个捕获记录"));
	connect(openAction, SIGNAL(triggered()), this, SLOT(about()));

	saveAction = new QAction(tr("保存"), this);
	saveAction->setIcon(QIcon(":/res/images/save.png"));
	saveAction->setShortcut(QKeySequence::Save);
	saveAction->setStatusTip(tr("保存本次捕获信息到文件"));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(about()));

	printAction = new QAction(tr("打印"), this);
	printAction->setIcon(QIcon(":/res/images/print.png"));
	printAction->setShortcut(tr("Ctrl+P"));
	printAction->setStatusTip(tr("打印当前捕获的数据"));
	connect(printAction, SIGNAL(triggered()), this, SLOT(about()));

	exitAction = new QAction(tr("退出"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("退出程序"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

	beginAction = new QAction(tr("开始捕获"), this);
	beginAction->setIcon(QIcon(":/res/images/begin.png"));
	beginAction->setShortcut(tr("Ctrl+B"));
	beginAction->setStatusTip(tr("开始捕获数据包"));
	connect(beginAction, SIGNAL(triggered()), this, SLOT(about()));

	endAction = new QAction(tr("停止捕获"), this);
	endAction->setIcon(QIcon(":/res/images/end.png"));
	endAction->setShortcut(tr("Ctrl+E"));
	endAction->setStatusTip(tr("停止捕获数据包"));
	connect(endAction, SIGNAL(triggered()), this, SLOT(about()));

	filterAction = new QAction(tr("过滤器设置"), this);
	filterAction->setIcon(QIcon(":/res/images/filter.png"));
	filterAction->setStatusTip(tr("使用过滤器来过滤捕获到的数据"));
	connect(filterAction, SIGNAL(triggered()), this, SLOT(about()));

	findQQAction = new QAction(tr("捕获QQ号码"), this);
	findQQAction->setIcon(QIcon(":/res/images/findqq.png"));
	findQQAction->setStatusTip(tr("捕获数据包包含的QQ号码"));
	connect(findQQAction, SIGNAL(triggered()), this, SLOT(about()));

	setAction = new QAction(tr("程序设置"), this);
	setAction->setIcon(QIcon(":/res/images/setting.png"));
	setAction->setStatusTip(tr("本程序设置"));
	connect(setAction, SIGNAL(triggered()), this, SLOT(about()));

	aboutAction = new QAction(tr("关于"), this);
	aboutAction->setIcon(QIcon(":/res/images/about.png"));
	aboutAction->setStatusTip(tr("关于信息"));
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

	aboutQtAction = new QAction(tr("关于Qt"), this);
	aboutQtAction->setIcon(QIcon(":/res/images/aboutqt.png"));
	aboutQtAction->setStatusTip(tr("关于Qt信息"));
	connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
	fileMenu = this->menuBar()->addMenu(tr("文件"));
	fileMenu->addAction(newAction);
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);

	fileMenu->addSeparator();
	fileMenu->addAction(printAction);

	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	toolsMenu = this->menuBar()->addMenu(tr("工具"));
	toolsMenu->addAction(beginAction);
	toolsMenu->addAction(endAction);
	toolsMenu->addSeparator();
	toolsMenu->addAction(findQQAction);

	optionsMenu = this->menuBar()->addMenu(tr("选项"));
	optionsMenu->addAction(filterAction);
	optionsMenu->addAction(setAction);

	this->menuBar()->addSeparator();

	helpMenu = this->menuBar()->addMenu(tr("帮助"));
	helpMenu->addAction(aboutAction);
	helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu()
{
	
}

void MainWindow::createToolBars()
{
	fileToolBar = addToolBar(tr("文件"));
	fileToolBar->addAction(newAction);
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(saveAction);
	fileToolBar->addSeparator();
	fileToolBar->addAction(printAction);

	workToolBar = addToolBar(tr("工具"));
	workToolBar->addAction(beginAction);
	workToolBar->addAction(endAction);
	workToolBar->addSeparator();
	workToolBar->addAction(findQQAction);

	setToolBar = addToolBar(tr("选项"));
	setToolBar->addAction(filterAction);
	setToolBar->addAction(setAction);

	infoToolBar = addToolBar(tr("帮助"));
	infoToolBar->addAction(aboutAction);
	infoToolBar->addAction(aboutQtAction);
}

void MainWindow::createStatusBar()
{
    statusLabel = new QLabel("Sniffer 测试版");
    statusLabel->setAlignment(Qt::AlignHCenter);
    statusLabel->setMinimumSize(statusLabel->sizeHint());

    this->statusBar()->addWidget(statusLabel);
}

bool MainWindow::isToContinue()
{
	if (isWindowModified()) {
		int result = QMessageBox::warning(this, tr("Sniffer"),
						tr("需要保存捕获的数据吗?"),
						QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		if (result == QMessageBox::Yes) {
			return true;
		} else if (result == QMessageBox::Cancel) {
			return false;
		}
	}
	return true;
}

void MainWindow::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < dieTime ) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
