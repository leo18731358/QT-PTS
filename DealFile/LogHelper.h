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
	void SetRootFilePath(QString rootFilePath);
	QString CreateAllTimeFile(QString pathBase);
	void WriteError(QString strName, QString strError);
	static LogHelper *Instance();

private:
	QMutex mt_Log;
	QMutex mt_WriteError;
	QString rootFilePath;
	
public:
	static LogHelper *_instance;

};

extern "C"
{
	QMutex mt_outWriteLog;
	DEALFILE_EXPORT void WriteLogError(QString rootFilePath, QString strName, QString strError);
}


#endif // !LOGHELPER