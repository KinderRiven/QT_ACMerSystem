#ifndef ACMERSYSTEM_H
#define ACMERSYSTEM_H

#include "kHead.h"
#include <kloginwindow.h>

#include <QtWidgets/QMainWindow>
#include "ui_acmersystem.h"

class ACMerSystem : public QMainWindow
{
	Q_OBJECT

public:
	ACMerSystem(QWidget *parent = 0);
	~ACMerSystem();

public slots:
	void menuExit();
	void menuLogin();
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
};

#endif // ACMERSYSTEM_H
