#include "acmersystem.h"

ACMerSystem::ACMerSystem(QWidget *parent)
	: QMainWindow(parent){
	//ui.setupUi(this);
	//����
	setWindowFlags(Qt::FramelessWindowHint);
	
	//͸��
	setAttribute(Qt::WA_TranslucentBackground,true);
	
	//����
	windowImage.load("Resources\\image\\blackRock");
}

/*
	Draw window;
*/

void ACMerSystem::paintEvent(QPaintEvent*){
	
	QPainter painter(this);
	resize(windowImage.width(), windowImage.height());
	painter.drawPixmap(0, 0, windowImage.width(), windowImage.height(), windowImage);
}

/*
	MouseAction;
*/

void ACMerSystem::mousePressEvent(QMouseEvent *event){
	
	if (event->buttons() == Qt::LeftButton){
		mousePrepos = cursor().pos();
		update();
	}
}

void ACMerSystem::mouseMoveEvent(QMouseEvent *event){
	
	if (event->buttons() == Qt::LeftButton){
		QPoint mousePos = cursor().pos();

		//�����ƶ���ʽ
		int posX = pos().x() + mousePos.x() - mousePrepos.x();
		int posY = pos().y() + mousePos.y() - mousePrepos.y();

		move(QPoint(posX, posY));

		mousePrepos = mousePos;
	}
}

/*
	delete;
*/

ACMerSystem::~ACMerSystem(){

}

/*
	Menu
*/
void ACMerSystem::contextMenuEvent(QContextMenuEvent *event){

	QMenu *menu = new QMenu(this);

	//��������
	QFont menuFont;
	menuFont.setFamily(QStringLiteral("SAO UI"));
	menuFont.setPointSize(12);

	//�û���Ϣ
	menuAction[1] = new QAction(QIcon("Resources\\image\\user"), tr("Login"), this);
	menuAction[1]->setFont(menuFont);
	connect(menuAction[1], SIGNAL(triggered()), this, SLOT(menuLogin()));
	menu->addAction(menuAction[1]);

	//�˳�
	menuAction[0] = new QAction(QIcon("Resources\\image\\exit"), tr("Exit"), this);
	menuAction[0]->setFont(menuFont);
	connect(menuAction[0], SIGNAL(triggered()), this, SLOT(menuExit()));
	menu->addAction(menuAction[0]);

	//����λ��
	menu->exec(cursor().pos());
}
/*
	Exit;
*/
void ACMerSystem::menuExit(){

	exit(0);
}
/*
	Login
*/
void ACMerSystem::menuLogin(){
	loginWindow.show();
}