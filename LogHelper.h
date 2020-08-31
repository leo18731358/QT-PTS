#ifndef LOGHELPER
#define LOGHELPER

#include <QObject>
#include <QMutex>

class LogHelper : public QObject
{
	Q_OBJECT

public:
	LogHelper(QObject *parent);
	LogHelper(QString rootFilePath);
	~LogHelper();

private:
	QString CreateDayFile(QString pathBase);        
	QString CreateAllTimeFile(QString pathBase);
	QString CreateHourFile(QString pathBase);
public:
	void WriteError(QString strName, QString strError);

private:
	QMutex mt_Log;
	QMutex mt_WriteError;
	QString rootFilePath;
};

#endif // !LOGHELPER