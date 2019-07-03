#pragma once

#include <QtWidgets/QDialog>
#include "ui_HintWindow.h"

class HintWindow : public QDialog
{
	Q_OBJECT

public:
	HintWindow(QWidget *parent = Q_NULLPTR);

private slots:
	void onHint();

private:
	Ui::HintWindowClass ui;
};
