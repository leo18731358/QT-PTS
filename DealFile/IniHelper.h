#ifndef INIHELPER_H
#define INIHELPER_H

#include "dealfile_global.h"
#include <iostream>

class DEALFILE_EXPORT IniHelper
{

public:
	static IniHelper *Instance();

private:
	static IniHelper *_instance;


};

extern "C"
{
	DEALFILE_EXPORT void WriteIni(QString section, QString key, QString value, QString filePath);
	DEALFILE_EXPORT std::string ReadIniStr(QString section, QString key,QString filePath);
	DEALFILE_EXPORT double ReadIniDouble(QString section, QString key, QString filePath);
	DEALFILE_EXPORT int ReadIniInt(QString section, QString key, QString filePath);
}


#endif // !INIHELPER_H