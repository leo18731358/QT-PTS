#include "LogHelper.h"

#include <QDateTime>
#include <QTime>
#include <Qdir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>


LogHelper *LogHelper::_instance = NULL;
LogHelper* LogHelper::Instance()
{
	if (_instance == NULL)
	{
		_instance = new LogHelper();
	}
	return _instance;
}

void LogHelper::SetRootFilePath(QString rootFilePath)
{
	this->rootFilePath = rootFilePath;
}

QString LogHelper::CreateDayFile(QString pathBase)
{
	mt_Log.lock();
	try
	{
		//获取当前日期
		QDateTime dt = QDateTime::currentDateTime();
		//用时间命名
		QString Year = QString::number(dt.date().year());
		QString Month = QString::number(dt.date().month());
		QString Day = QString::number(dt.date().day());

		QString path = pathBase + Year + "-" + Month + "-" + Day + "\\";

		//判断是否存在目录夹
		QDir dir;

		if (!dir.exists(path))
		{
			dir.mkdir(path);
		}
		mt_Log.unlock();
		return path;
	}
	catch (const std::exception &ex)
	{
		WriteError("LogWrite", ex.what());
		mt_Log.unlock();
		return "";
	}


}

QString LogHelper::CreateHourFile(QString pathBase)
{
	mt_Log.lock();
	try
	{
		//获取当前日期
		QTime dt = QTime::currentTime();
		//用时间命名
		QString Hour = QString::number(dt.hour());
		QString path = pathBase + Hour + "\\";

		//判断是否存在目录夹
		QDir dir;

		if (!dir.exists(path))
		{
			dir.mkdir(path);
		}
		mt_Log.unlock();
		return path;
	}
	catch (const std::exception &ex)
	{
		WriteError("LogWrite", ex.what());
		mt_Log.unlock();
		return "";
	}
	
}

QString LogHelper::CreateAllTimeFile(QString pathBase)
{
	QString dataPath = CreateDayFile(pathBase);
	QString hourPath = CreateHourFile(dataPath);
	return hourPath;
}

void  LogHelper::WriteError(QString strName, QString strError)
{
	try
	{
		//获取当前日期
		QDateTime dt = QDateTime::currentDateTime();
		QString strPath = CreateAllTimeFile(rootFilePath);
		//文件
		QString strFileLog = strPath + "\\" + strName + ".log";
		QFile file;
		QTextStream textStream;
		file.setFileName(strFileLog);
		file.open(QIODevice::WriteOnly | QIODevice::Append);
		textStream.setDevice(&file);
		textStream << dt.toString("yyyy-MM-dd hh:mm:ss:zzz") << "  " << strError << endl;
		file.close();
		mt_WriteError.unlock();
	}
	catch (const std::exception & ex)
	{
		mt_WriteError.unlock();
		return;
	}
}



void DEALFILE_EXPORT WriteLogError(QString rootFilePath, QString strName, QString strError)
{
	LogHelper *logHelper = LogHelper::Instance();
	logHelper->SetRootFilePath(rootFilePath);

	mt_outWriteLog.lock();
	try
	{
		//获取当前日期
		QDateTime dt = QDateTime::currentDateTime();
		QString strPath = logHelper->CreateAllTimeFile(rootFilePath);
		//文件
		QString strFileLog = strPath + "\\" + strName + ".log";	
		QFile file;
		QTextStream textStream;
		file.setFileName(strFileLog);
		file.open(QIODevice::WriteOnly | QIODevice::Append);
		textStream.setDevice(&file);
		textStream << dt.toString("yyyy-MM-dd hh:mm:ss:zzz") << "  " << strError << endl;
		file.close();
		mt_outWriteLog.unlock();
	}
	catch (const std::exception & ex)
	{
		mt_outWriteLog.unlock();
		return;
	}
}
