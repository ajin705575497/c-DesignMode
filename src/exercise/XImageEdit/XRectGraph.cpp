#include "XRectGraph.h"
#include "XModel.h"
#include <QPainter>
#include <QPen>


void XRectGraph::Draw(XModel * d)
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
	if (size < 2)
		return;
	//从起始点到结尾点画矩形
	int x = d->poss[0].x;
	int y = d->poss[0].y;
	int w = d->poss[size - 1].x - x;
	int h = d->poss[size - 1].y - y;
	m_painter->drawRect(x,y,w,h);

}
