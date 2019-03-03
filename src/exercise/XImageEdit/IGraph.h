#pragma once

class QPainter;
class QImage;
class XModel;
class IGraph
{
public:



	virtual void Init(QPainter*p, QImage *s)
	{
		m_painter = p;
		m_src = s;
	}

	//»æÖÆÍ¼Ôª
	virtual void Draw(XModel*m) = 0;

protected:
	QPainter* m_painter = 0;
	QImage* m_src = 0;
};

