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
		//��ȡ��ǰ����
		QDateTime dt = QDateTime::currentDateTime();
		//��ʱ������
		QString Year = dt.date().year();
		QString Month = dt.date().month();
		QString Day = dt.date().day();

		QString path = pathBase + Year + "-" + Month + "-" + Day + "\\";

		//�ж��Ƿ����Ŀ¼��
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