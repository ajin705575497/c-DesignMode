#include "XEditView.h"
#include <QPainter>
#include <QLine>
#include "XModel.h"
#include "XPenGraph.h"

using namespace std;

//XPenGraph xpen;
XEditView::XEditView()
{
	//��ʼ��ͼ��δ��ͼ��ֱ�ӻ�ͼ
	m_out = QImage(1280, 720,QImage::Format_RGB888);
	m_src = QImage(1280, 720, QImage::Format_RGB888);
}


XEditView::~XEditView()
{
}

//��ʾĿ��
void XEditView::InitDevice(void * d)
{
	this->m_device = (QWidget*)d;
	if (!op)
		op = new QPainter(&m_out);
	//����һ�ε������
	op->end();
	op->begin(&m_out);
	map<int, IGraph*>::iterator iter = views.begin();
	for (; iter != views.end(); iter++)
	{
		iter->second->Init(op, &m_src);
	}
	//xpen.Init(op, &m_src);
}

//��ʾ����ͼ
bool XEditView::InitBack(const char * url)
{
	if(!m_src.load(QString::fromLocal8Bit(url)))
		return false;
	if (op->isActive())
		op->end();
	m_out = m_src.copy();
	op->begin(&m_out);
	return true;

}


void XEditView::Update(XSubject*data)
{
	if (!data)
		return;
	
	//XModel
	XModel *m = static_cast<XModel*>(data);

	views[m->type]->Draw(m);

	//����ͼԪ������
	//map<int, IGraph*>::iterator iter = views.begin();
	//for (; iter != views.end(); iter++)
	//{
	//	iter->second->Draw(m);
	//}
	//xpen.Draw(m);
	//int size = m->poss.size();
	//QPainter p(&m_out);
	//for (int i = 1; i < size; i++)
	//{
	//	p.drawLine(QLine(m->poss[i - 1].x, m->poss[i - 1].y, m->poss[i].x, m->poss[i].y));
	//}
}


//���ƽ��
void XEditView::Paint()
{
	//��m_device���ڻ���
	QPainter p(m_device);
	p.drawImage(0, 0, m_out);
	////����ͼƬ
	//p.drawImage(0, 0, m_src);

	////��������
	////�������������
	//int size = poss.size();
	////��1��ʼ������Ҫ��������
	//for (int i = 1; i < size; i++)
	//{
	//	p.drawLine(QLine(poss[i - 1].x, poss[i - 1].y,poss[i].x, poss[i].y));
	//}
	
}


