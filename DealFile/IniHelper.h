#ifndef INIHELPER_H
#define INIHELPER_H

#include "dealfile_global.h"
#include <iostream>

class DEALFILE_EXPORT IniHelper
{

public:
	virtual void WriteIni(QString section, QString key, QString value, QString filePath);
	virtual QString ReadIniStr(QString section, QString key, QString filePath);
	virtual double ReadIniDouble(QString section, QString key, QString filePath);
	virtual int ReadIniInt(QString section, QString key, QString filePath);


public:
	static IniHelper *_instance;


};

extern "C"
{


	DEALFILE_EXPORT IniHelper *IniInstance();
}


#endif // !INIHELPER_H