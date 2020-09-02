#include "mainWindow.h"

#include "DealFile\LogHelper.h"
#include "DealFile\IniHelper.h"

#include <QDateTime>
#include <QLibrary>
#include <QDebug>



mainWindow::mainWindow(QWidget *parent)
	: QWidget(parent)
{
	InitialUI();
}

mainWindow::~mainWindow()
{
}


void mainWindow::InitialUI()
{
	QHBoxLayout *m_mainLayout = new QHBoxLayout();

	QVBoxLayout *leftLaout = new QVBoxLayout();
	QVBoxLayout *rightLaout = new QVBoxLayout();

	m_tableView = new QTableView();
	rightLaout->addWidget(m_tableView);

	//准备数据模型
	model = new QStandardItemModel();
	model->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("时间")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("内容")));

	//利用setModel()方法将数据模型与QTableView绑定
	m_tableView->setModel(model);
	m_tableView->verticalHeader()->hide();
	m_tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	m_tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	m_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);



	QDateTime current_time = QDateTime::currentDateTime();
	QString strTime = current_time.toString("yyyy-MM-dd hh:mm:ss:zzz");
	QString strMsg = QStringLiteral("程序测试中。。。");

	QList<QStandardItem *> m_Standard = QList<QStandardItem *>() << new QStandardItem(strTime) << new QStandardItem(strMsg);
	model->appendRow(m_Standard);

	QPushButton *m_btn1 = new QPushButton();
	m_btn1->setObjectName(QStringLiteral("btn1"));
	m_btn1->setText(QStringLiteral("按钮1"));
	leftLaout->addWidget(m_btn1);
	
	m_mainLayout->addLayout(rightLaout);
	m_mainLayout->addLayout(leftLaout);
	this->setLayout(m_mainLayout);

	connect(m_btn1, SIGNAL(clicked()), this, SLOT(ReportMsg()));
	connect(m_tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(ShowLogMsg(const QModelIndex &)));
}


void mainWindow::ReportMsg()
{
	QDateTime current_time = QDateTime::currentDateTime();
	QString strTime = current_time.toString("yyyy-MM-dd hh:mm:ss:zzz");
	QString strMsg = QStringLiteral("程序测试中。。。");

	QList<QStandardItem *> m_Standard = QList<QStandardItem *>() << new QStandardItem(strTime) << new QStandardItem(strMsg);
	model->appendRow(m_Standard);

	m_tableView->scrollToBottom();

	//int tableViewCount = m_tableView->model()->rowCount();
	//if (tableViewCount > 10)
	//{
	//	m_tableView->model()->removeRow(0);
	//}



	typedef LogHelper* (*LogHelperFun)();
	QLibrary *DealFileDll = new QLibrary("DealFile.dll");
	if (DealFileDll->load())
	{
		LogHelperFun logHelperFun = (LogHelperFun)DealFileDll->resolve("LogInstance");
		if (logHelperFun)
		{
			LogHelper* logHelper = logHelperFun();
			logHelper->SetRootFilePath("D:\\Desktop\\");
			logHelper->WriteError("test111", strMsg);
		}
	}

	typedef IniHelper* (*IniHelperFun)();
	IniHelperFun iniHelperFun = (IniHelperFun)DealFileDll->resolve("IniInstance");
	if (iniHelperFun)
	{
		IniHelper *iniHelper = iniHelperFun();
		iniHelper->WriteIni("section", "key", "12345", "D:\\Desktop\\1.ini");

		QString ss = iniHelper->ReadIniStr("section", "key", "D:\\Desktop\\1.ini");
		qDebug() << ss << endl;

	}


}

void mainWindow::ShowLogMsg(const QModelIndex &Index)
{
	if (Index.isValid())
	{
		QAbstractItemModel* m = (QAbstractItemModel *)Index.model();
		//for (int columnIndex = 0; columnIndex < m->columnCount(); columnIndex++) {
			//QModelIndex x = m->index(Index.row(), columnIndex);
			QModelIndex x = m->index(Index.row(), 0);
			QString s = x.data().toString();
		//}

		QMessageBox::information(this, "111", s);
	}




}