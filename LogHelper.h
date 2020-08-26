#ifndef LOGHELPER
#define LOGHELPER

#include <QObject>

class LogHelper : public QObject
{
	Q_OBJECT

public:
	LogHelper(QObject *parent);
	~LogHelper();

private:
	QString CreateDayFile(QString pathBase);        
	QString CreateAllTimeFile(QString pathBase);
	QString CreateHourFile(QString pathBase);
public:
	void WriteError(QString strName, QString strError);

};

#endif // !LOGHELPER