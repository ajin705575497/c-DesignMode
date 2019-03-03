#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_XImageEdit.h"
 
class XImageEdit : public QMainWindow
{
	Q_OBJECT

public:
	XImageEdit(QWidget *parent = Q_NULLPTR);
	
public slots:
	void setColor();
private:
	Ui::XImageEditClass ui;
};
