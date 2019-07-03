#include "HintWindow.h"
#include "HintWnd.h"

HintWindow::HintWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	move(QPoint(0, 0));

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onHint()));
}

void HintWindow::onHint()
{
	HintWnd* wnd = new HintWnd(this);

	QRect rect = geometry();
	wnd->setParentGeo(rect);
	wnd->show();
}
