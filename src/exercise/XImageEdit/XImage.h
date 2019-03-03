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
	//���ػ��Ʒ���  update������
	void paintEvent(QPaintEvent*e);

	//������꺯��
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
	////ԭͼ
	//QImage m_src;
	////���ͼ
	//QImage m_out;
	IController *m_c = 0;
	int m_penSize = 5;
	int r = 255;
	int g = 0;
	int b = 0;
	int a = 255;
};

