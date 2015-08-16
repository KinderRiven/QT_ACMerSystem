#ifndef KLOGINWINDOW_H
#define KLOGINWINDOW_H

#include <QWidget>
#include <kHead.h>
#include <kMusicData.h>

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
public slots:
	void buttonExit();
protected:
	void mousePressEvent(QMouseEvent *event);			//��д������¼�
	void mouseMoveEvent(QMouseEvent *event);			//��д����ƶ��¼�
private:
    Ui::kLoginWindow *ui;
	QPoint mousePrepos;
};

#endif // KLOGINWINDOW_H
