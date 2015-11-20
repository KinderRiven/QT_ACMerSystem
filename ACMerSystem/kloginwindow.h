#ifndef KLOGINWINDOW_H
#define KLOGINWINDOW_H

#include <QWidget>
#include <kHead.h>
#include <kMusicData.h>
#include "kUserData.h"
#include "kwarningwindow.h"
#include "computerSystem.h"
/*
	580 X 285
*/
namespace Ui {
class kLoginWindow;
}

class kLoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit kLoginWindow(QWidget *parent = 0);
    ~kLoginWindow();
	void kShow();
public slots:
	void buttonExit();
	void buttonOK();
protected:
	void mousePressEvent(QMouseEvent *event);			//��д������¼�
	void mouseMoveEvent(QMouseEvent *event);			//��д����ƶ��¼�
	void timerEvent(QTimerEvent *event);
private:
    Ui::kLoginWindow *ui;
	QPoint mousePrepos;
	kWarningWindow warningWindow;
	int kHeight;
	int kWidth;
	int timeid;
};

#endif // KLOGINWINDOW_H
