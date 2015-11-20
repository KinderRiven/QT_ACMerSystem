#ifndef ACMERSYSTEM_H
#define ACMERSYSTEM_H

#include "kHead.h"
#include "ktable.h"
#include <kloginwindow.h>
#include <ksettingswindow.h>

#include <QtWidgets/QMainWindow>
#include "ui_acmersystem.h"
#include "computerSystem.h"
#include "kshowdata.h"

class ACMerSystem : public QMainWindow
{
	Q_OBJECT

public:
	ACMerSystem(QWidget *parent = 0);
	~ACMerSystem();
	void kShow();

public slots:
	void menuExit();
	void menuLogin();
	void menuSetting();
	void startRun();
	void showData();
protected:
	void paintEvent(QPaintEvent*);						//��ͼ
	void mousePressEvent(QMouseEvent *event);			//��д������¼�
	void mouseMoveEvent(QMouseEvent *event);			//��д����ƶ��¼�
	void contextMenuEvent(QContextMenuEvent *event);	//��д�Ҽ��˵�

private:
	Ui::ACMerSystemClass ui;
	QPixmap windowImage;		//����
	QPoint  mousePrepos;		//��¼���֮ǰ��λ��
	QAction *menuAction[10];	//�˵�ָ��

	kLoginWindow loginWindow;
	kSettingsWindow settingsWindow;
	kTable userTable;
};

#endif // ACMERSYSTEM_H
