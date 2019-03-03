#pragma once
#include <QWidget>
#include <QImage>
#include <vector>
#include "IView.h"
#include <map>
#include "IGraph.h"
class QPainter;


//����ģʽ
class XEditView :public IView
{
public:
	~XEditView();
	
	static XEditView* Get()
	{
		static XEditView v;
		return &v;
	}

	//ˢ�µ�out�У�
	virtual void Update(XSubject*data);

	//��ʾĿ��
	virtual void InitDevice(void* d);

	//��ʾ����ͼ
	virtual bool InitBack(const char* url);

	//����out���
	virtual void Paint();

	template<class ViewClass>
	IGraph* RegView(int type) 
	{
		ViewClass *view = new ViewClass();
		views.insert(std::make_pair(type, view));
		return view;
	}

	////������
	//std::vector<XPos> poss;
protected:
	XEditView();
	QWidget * m_device;

	//ԭͼ
	QImage m_src;
	//���ͼ
	QImage m_out;

	//���Ƶ�out
	QPainter*op = 0;

	//ͼԪ��� �ⲿά��
	std::map<int, IGraph*> views;
};

