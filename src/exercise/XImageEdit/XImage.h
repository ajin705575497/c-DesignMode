#pragma once
#include <QWidget>
#include <QImage>
class IController;
class XImage : public QWidget
{
	Q_OBJECT
public:
	XImage(QWidget* p = 0);
	~XImage();
	//重载绘制方法  update后会调用
	void paintEvent(QPaintEvent*e);

	//重载鼠标函数
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent*e);
public slots:
	void Open();
	void setPen();
	void setEras();
	void setRect();
	void Undo();
	void Redo();
	void setPenSize(int size);
public:
	void setPenColor(int r, int g, int b, int a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

protected:
	////原图
	//QImage m_src;
	////输出图
	//QImage m_out;
	IController *m_c = 0;
	int m_penSize = 5;
	int r = 255;
	int g = 0;
	int b = 0;
	int a = 255;
};

