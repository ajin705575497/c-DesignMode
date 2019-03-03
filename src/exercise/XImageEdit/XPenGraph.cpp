#include "XPenGraph.h"
#include <QPainter>
#include <QPen>
#include "XModel.h"
void XPenGraph::Draw(XModel *d)
{
	if (!d || !m_painter)
		return;

	//画笔
	QPen pen;
	pen.setWidth(d->getPara("penSize"));
	pen.setColor(QColor(d->getPara("colorR"), d->getPara("colorG"), d->getPara("colorB"), d->getPara("colorA")));
	//设置连接处
	pen.setCapStyle(Qt::RoundCap);//顶部样式
	pen.setJoinStyle(Qt::RoundJoin);//连接处样式
	//设置抗锯齿
	m_painter->setRenderHint(QPainter::Antialiasing, true);

	m_painter->setPen(pen);

	int size = d->poss.size();
	for (int i = 1; i < size; i++)
	{
		m_painter->drawLine(QLine(d->poss[i - 1].x, d->poss[i - 1].y, d->poss[i].x, d->poss[i].y));
	}
}