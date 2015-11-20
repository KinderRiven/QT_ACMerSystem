#include "kwarningwindow.h"
#include "ui_kwarningwindow.h"

kWarningWindow::kWarningWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kWarningWindow)
{
    ui->setupUi(this);

	//����
	setWindowFlags(
		Qt::FramelessWindowHint | 
		Qt::Tool | 
		Qt::WindowStaysOnTopHint | 
		Qt::X11BypassWindowManagerHint
		);
	//͸��
	setAttribute(Qt::WA_TranslucentBackground, true);

}

kWarningWindow::~kWarningWindow()
{
    delete ui;
}

void kWarningWindow::paintEvent(QPaintEvent*){
	QPainter painter(this);
	resize(windowImage.width(), windowImage.height());
	painter.drawPixmap(0, 0, windowImage.width(), windowImage.height(), windowImage);
}

void kWarningWindow::timerEvent(QTimerEvent *event){
	if (event->timerId() == timeid){
		double opa = windowOpacity();
		if (opa > 0){
			opa -= 0.025;
			setWindowOpacity(opa);
		}
		else{
			hide();
			killTimer(timeid);
		}
	}
}

void kWarningWindow::kShow(int type){

	//���ؾ�������
	//0 ok
	//1 error
	if (type == 0){
		kMusicData::successSound();
		windowImage.load("Resources\\image\\warning");
	}
	else if (type == 1){
		kMusicData::errorSound();
		windowImage.load("Resources\\image\\warning2");
	}

	//͸����
	setWindowOpacity(1.0);

	//����
	timeid = startTimer(40);


	update();

	//�ƶ����м�
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - 580) / 2, (desktop->height() - 270) / 2);

	show();
}
