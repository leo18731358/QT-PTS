#include "IniHelper.h"

#include<QSettings>

IniHelper *IniHelper::_instance = NULL;
IniHelper *IniHelper::Instance()
{
	if (_instance == NULL)
	{
		_instance = new IniHelper();
	}
	return _instance;
}

void DEALFILE_EXPORT WriteIni(QString section, QString key, QString value, QString filePath)
{
	QSettings setting(filePath, QSettings::IniFormat);
	setting.beginGroup(section);
	setting.setValue(key, value);
	setting.endGroup();
}

std::string DEALFILE_EXPORT ReadIniStr(QString section, QString key, QString filePath)
{
	QSettings setting(filePath, QSettings::IniFormat);
	QString objReturn = setting.value(section + "/" + key).toString();
	std::string objStr = objReturn.toStdString();
	return objStr;
}

double DEALFILE_EXPORT ReadIniDouble(QString section, QString key, QString filePath)
{
	QSettings setting(filePath, QSettings::IniFormat);
	double objReturn = setting.value(section + "/" + key).toDouble();
	return objReturn;
}

int DEALFILE_EXPORT ReadIniInt(QString section, QString key, QString filePath)
{
	QSettings setting(filePath, QSettings::IniFormat);
	double objReturn = setting.value(section + "/" + key).toInt();
	return objReturn;
}