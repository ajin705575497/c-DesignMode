#include "XImage.h"
#include <QDebug>
#include <QFileDialog>
#include <QPainter>
#include "XEditView.h"
#include <QMouseEvent>
#include "XModel.h"
#include "IController.h"
#include "XControllerFactory.h"
//XModel m;
XImage::XImage(QWidget* p):QWidget(p)
{
	m_c = IController::Create(XControllerFactory::Get());
	m_c->Init(this);
	XEditView::Get()->InitDevice(this);
	//��ͼ�۲�ģ��
	//m.Attach(XEditView::Get());
}


XImage::~XImage()
{
}



void XImage::Open() 
{
	qDebug() << "open image";
	QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("��ͼƬ"), "", QStringLiteral("*.png *.jpg *.bmp"));
	if (filename.isEmpty())
		return;
	//����ͼƬ
	//if (!m_src.load(filename))
	//if(!XEditView::Get()->InitBack(filename.toLocal8Bit().data()))
	if (!m_c->InitBack(filename.toLocal8Bit().data()))
	{
		qDebug() << "src load image failed";
		return;
	}
	//ˢ����ʾ
	update();
}


void XImage::mousePressEvent(QMouseEvent *e)
{
	//XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
	//m.Add(XPos(e->x(), e->y()));

	//����һ��ģ��
	m_c->AddModel();
	m_c->setPara("penSize", m_penSize);
	m_c->setPara("colorR", r);
	m_c->setPara("colorG", g);
	m_c->setPara("colorB", b);
	m_c->setPara("colorA", a);
	m_c->Add(e->x(), e->y());
}

//Ĭ������ƶ��¼������²Ŵ���
void XImage::mouseMoveEvent(QMouseEvent*e)
{
	
	//XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
//	m.Add(XPos(e->x(), e->y()));

	//�޸�ģ������
	m_c->Add(e->x(), e->y());
	update();
}

void XImage::setPen()
{
	m_c->SetStatus(XPEN);
}

void XImage::setEras()
{
	m_c->SetStatus(XERASER);
}

void XImage::setRect()
{
	m_c->SetStatus(XRECT);
}

void XImage::Undo()
{
	m_c->Undo();
	update();
}

void XImage::Redo()
{
	m_c->Redo();
	update();
}

void XImage::setPenSize(int size)
{
	m_penSize = size;
}

void XImage::paintEvent(QPaintEvent * e)
{
	m_c->Paint();
	//XEditView::Get()->Paint();
	////�ڵ�ǰ����(this)����
	//QPainter p(this);
	////����ͼƬ
	//p.drawImage(0, 0, m_src);

}

