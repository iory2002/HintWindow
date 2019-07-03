#include "HintWnd.h"
#include <QPropertyAnimation>

HintWnd::HintWnd(QDialog* parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::Window);

	m_closeBut = new QPushButton(this);
	m_closeBut->setText("Hide");

	connect(m_closeBut, SIGNAL(clicked()), this, SLOT(onClose()));


}

HintWnd::~HintWnd()
{
	int a = 0;
}


void HintWnd::showEvent(QShowEvent* event)
{
	QPropertyAnimation* animation = new QPropertyAnimation(this, "windowOpacity");
	animation->setDuration(250);
	animation->setStartValue(0);
	animation->setEndValue(1);
	animation->start();

	QPropertyAnimation* animation2 = new QPropertyAnimation(this, "geometry");
	animation2->setDuration(250);
	QPoint startPoint = m_rect.topRight() + QPoint(5, 0);
	animation2->setStartValue(QRect(startPoint.x(), startPoint.y(), 0, 0));
	animation2->setEndValue(QRect(startPoint.x(), startPoint.y(), 1000, 800));

	animation2->start();
}

void HintWnd::closeEvent(QCloseEvent* event)
{
	close();

}

void HintWnd::onClose()
{
	QPropertyAnimation* animation = new QPropertyAnimation(this, "windowOpacity");
	animation->setDuration(250);
	animation->setStartValue(1);
	animation->setEndValue(0);
	animation->start();

	QPropertyAnimation* animation2 = new QPropertyAnimation(this, "geometry");
	animation2->setDuration(250);
	QPoint startPoint = m_rect.topRight() + QPoint(5, 0);
	animation2->setStartValue(QRect(startPoint.x(), startPoint.y(), 1000, 800));
	animation2->setEndValue(QRect(startPoint.x(), startPoint.y(), 0, 0));

	animation2->start();

}