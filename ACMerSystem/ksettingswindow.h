#ifndef KSETTINGSWINDOW_H
#define KSETTINGSWINDOW_H

#include <QWidget>
#include "kHead.h"
#include "kUserData.h"
#include "kwarningwindow.h"
#include "computerSystem.h"
#include "kMusicData.h"


namespace Ui {
class kSettingsWindow;
}

class kSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit kSettingsWindow(QWidget *parent = 0);
    ~kSettingsWindow();
	void kShow();
public slots:
	void buttonExit();
	void buttonOK();
protected:
	void mousePressEvent(QMouseEvent *event);			//��д������¼�
	void mouseMoveEvent(QMouseEvent *event);			//��д����ƶ��¼�
	void timerEvent(QTimerEvent *event);
private:
    Ui::kSettingsWindow *ui;
	QPoint mousePrepos;
	kWarningWindow warningWindow;
	int timeid;
};

#endif // KSETTINGSWINDOW_H
