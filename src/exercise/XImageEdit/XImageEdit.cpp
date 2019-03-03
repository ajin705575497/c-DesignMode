#include "XImageEdit.h"
#include <QColorDialog>
#include <QString>
XImageEdit::XImageEdit(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.openImageButton, SIGNAL(clicked()),
		ui.image, SLOT(Open()));

	connect(ui.penButton, SIGNAL(clicked()),
		ui.image, SLOT(setPen()));

	connect(ui.erasButton, SIGNAL(clicked()),
		ui.image, SLOT(setEras()));
	
	connect(ui.rectButton, SIGNAL(clicked()),
		ui.image, SLOT(setRect()));

	connect(ui.undoButton, SIGNAL(clicked()),
		ui.image, SLOT(Undo()));

	connect(ui.redoButton, SIGNAL(clicked()),
		ui.image, SLOT(Redo()));
	connect(ui.penSizeSlider, SIGNAL(valueChanged(int)),
		ui.image, SLOT(setPenSize(int)));

	connect(ui.colorButton, SIGNAL(clicked()),
		this, SLOT(setColor()));
}


void XImageEdit::setColor()
{
	QColor col = QColorDialog::getColor(Qt::red, this);
	QString sty = QString("background-color:rgba(%1,%2,%3,%4);")
		.arg(col.red()).arg(col.green()).arg(col.blue()).arg(col.alpha());
	ui.colorButton->setStyleSheet(sty);
	ui.image->setPenColor(col.red(),col.green(), col.blue(), col.alpha());
}