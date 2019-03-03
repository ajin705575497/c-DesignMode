#include "XErasGraph.h"
#include <QPainter>
#include <QPen>
#include "XModel.h"


void XErasGraph::Draw(XModel *d)
{
	if (!d || !m_painter)
		return;

	//画笔
	QPen pen;
	pen.setWidth(d->getPara("penSize"));
	//设置连接处
	pen.setCapStyle(Qt::RoundCap);//顶部样式
	pen.setJoinStyle(Qt::RoundJoin);//连接处样式
	//用原图做刷子
	pen.setBrush(*m_src);

	//设置抗锯齿
	m_painter->setRenderHint(QPainter::Antialiasing, true);

	m_painter->setPen(pen);

	int size = d->poss.size();
	for (int i = 1; i < size; i++)
	{
		m_painter->drawLine(QLine(d->poss[i - 1].x, d->poss[i - 1].y, d->poss[i].x, d->poss[i].y));
	}
}