#include "XErasGraph.h"
#include <QPainter>
#include <QPen>
#include "XModel.h"


void XErasGraph::Draw(XModel *d)
{
	if (!d || !m_painter)
		return;

	//����
	QPen pen;
	pen.setWidth(d->getPara("penSize"));
	//�������Ӵ�
	pen.setCapStyle(Qt::RoundCap);//������ʽ
	pen.setJoinStyle(Qt::RoundJoin);//���Ӵ���ʽ
	//��ԭͼ��ˢ��
	pen.setBrush(*m_src);

	//���ÿ����
	m_painter->setRenderHint(QPainter::Antialiasing, true);

	m_painter->setPen(pen);

	int size = d->poss.size();
	for (int i = 1; i < size; i++)
	{
		m_painter->drawLine(QLine(d->poss[i - 1].x, d->poss[i - 1].y, d->poss[i].x, d->poss[i].y));
	}
}