#ifndef LOGHELPER_H
#define LOGHELPER_H

#include "dealfile_global.h"
#include <QObject>
#include <QMutex>

class DEALFILE_EXPORT LogHelper
{

private:
	QString CreateDayFile(QString pathBase);        
	QString CreateHourFile(QString pathBase);

public:
	LogHelper(QString rootFilePath);
	virtual QString CreateAllTimeFile(QString pathBase);
	virtual void WriteError(QString strName, QString strError);

private:
	QMutex mt_Log;
	QMutex mt_WriteError;
	QString rootFilePath;

public:
	static LogHelper *_instance;

};

extern "C"
{
	DEALFILE_EXPORT LogHelper *LogInstance(QString rootFilePath);
}


#endif // !LOGHELPER