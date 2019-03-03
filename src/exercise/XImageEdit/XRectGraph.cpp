#include "XRectGraph.h"
#include "XModel.h"
#include <QPainter>
#include <QPen>


void XRectGraph::Draw(XModel * d)
{
	if (!d || !m_painter)
		return;

	//����
	QPen pen;
	pen.setWidth(d->getPara("penSize"));
	pen.setColor(QColor(d->getPara("colorR"), d->getPara("colorG"), d->getPara("colorB"), d->getPara("colorA")));
	//�������Ӵ�
	pen.setCapStyle(Qt::RoundCap);//������ʽ
	pen.setJoinStyle(Qt::RoundJoin);//���Ӵ���ʽ
	//���ÿ����
	m_painter->setRenderHint(QPainter::Antialiasing, true);

	m_painter->setPen(pen);

	int size = d->poss.size();
	if (size < 2)
		return;
	//����ʼ�㵽��β�㻭����
	int x = d->poss[0].x;
	int y = d->poss[0].y;
	int w = d->poss[size - 1].x - x;
	int h = d->poss[size - 1].y - y;
	m_painter->drawRect(x,y,w,h);

}
