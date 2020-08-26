#ifndef MAINWINDOW
#define MAINWINDOW


#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMessageBox>

class mainWindow : public QWidget
{
	Q_OBJECT

public:
	mainWindow(QWidget *parent = Q_NULLPTR);
	~mainWindow();

	void InitialUI();
private slots:
	void ReportMsg();
	void ShowLogMsg(const QModelIndex &);

private:
	QTableView *m_tableView;
	QStandardItemModel *model;

};

#endif // !MAINWINDOW