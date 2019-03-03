#include "XImageGraph.h"


#include <QPainter>


void XImageGraph::Draw(XModel * m)
{
	if (!m_painter || !m)
		return;
	m_painter->drawImage(0, 0, *m_src);
}
