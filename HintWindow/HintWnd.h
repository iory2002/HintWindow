#pragma once

#include <QDialog>
#include <QPushButton>

class HintWnd : public QDialog
{
	Q_OBJECT

public:
	HintWnd(QDialog *parent);
	~HintWnd();

	void setParentGeo(const QRect& rect) { m_rect = rect; }
protected:
	virtual void showEvent(QShowEvent* event);
	virtual void closeEvent(QCloseEvent* event);

private slots:
	void onClose();

private:
	QPushButton* m_closeBut;
	QRect	m_rect;
};
