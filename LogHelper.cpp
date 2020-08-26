#include "LogHelper.h"

#include <QDateTime>
#include <Qdir>


LogHelper::LogHelper(QObject *parent)
	: QObject(parent)
{
}

LogHelper::~LogHelper()
{
}


QString LogHelper::CreateDayFile(QString pathBase)
{
	try
	{
		//获取当前日期
		QDateTime dt = QDateTime::currentDateTime();
		//用时间命名
		QString Year = dt.date().year();
		QString Month = dt.date().month();
		QString Day = dt.date().day();

		QString path = pathBase + Year + "-" + Month + "-" + Day + "\\";

		//判断是否存在目录夹
		QDir dir;

		if (!dir.exists(path))
		{
			dir.mkdir(path);
		}
		return path;
	}
	catch (const std::exception&)
	{
		return "";
	}

}

QString LogHelper::CreateHourFile(QString pathBase)
{


	return "";
}

QString LogHelper::CreateAllTimeFile(QString pathBase)
{


	return "";
}

void LogHelper::WriteError(QString strName, QString strError)
{

}