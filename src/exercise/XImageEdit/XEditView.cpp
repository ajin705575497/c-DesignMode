#include "XEditView.h"
#include <QPainter>
#include <QLine>
#include "XModel.h"
#include "XPenGraph.h"

using namespace std;

//XPenGraph xpen;
XEditView::XEditView()
{
	//初始化图像，未打开图像直接画图
	m_out = QImage(1280, 720,QImage::Format_RGB888);
	m_src = QImage(1280, 720, QImage::Format_RGB888);
}


XEditView::~XEditView()
{
}

//显示目标
void XEditView::InitDevice(void * d)
{
	this->m_device = (QWidget*)d;
	if (!op)
		op = new QPainter(&m_out);
	//把上一次的清理掉
	op->end();
	op->begin(&m_out);
	map<int, IGraph*>::iterator iter = views.begin();
	for (; iter != views.end(); iter++)
	{
		iter->second->Init(op, &m_src);
	}
	//xpen.Init(op, &m_src);
}

//显示背景图
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

	//遍历图元并绘制
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


//绘制结果
void XEditView::Paint()
{
	//在m_device窗口绘制
	QPainter p(m_device);
	p.drawImage(0, 0, m_out);
	////绘制图片
	//p.drawImage(0, 0, m_src);

	////绘制线条
	////所有坐标的数量
	//int size = poss.size();
	////从1开始，划线要有两个点
	//for (int i = 1; i < size; i++)
	//{
	//	p.drawLine(QLine(poss[i - 1].x, poss[i - 1].y,poss[i].x, poss[i].y));
	//}
	
}


