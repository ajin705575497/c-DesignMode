#pragma once
#include <QWidget>
#include <QImage>
#include <vector>
#include "IView.h"
#include <map>
#include "IGraph.h"
class QPainter;


//单例模式
class XEditView :public IView
{
public:
	~XEditView();
	
	static XEditView* Get()
	{
		static XEditView v;
		return &v;
	}

	//刷新到out中，
	virtual void Update(XSubject*data);

	//显示目标
	virtual void InitDevice(void* d);

	//显示背景图
	virtual bool InitBack(const char* url);

	//绘制out结果
	virtual void Paint();

	template<class ViewClass>
	IGraph* RegView(int type) 
	{
		ViewClass *view = new ViewClass();
		views.insert(std::make_pair(type, view));
		return view;
	}

	////点坐标
	//std::vector<XPos> poss;
protected:
	XEditView();
	QWidget * m_device;

	//原图
	QImage m_src;
	//输出图
	QImage m_out;

	//绘制到out
	QPainter*op = 0;

	//图元编号 外部维护
	std::map<int, IGraph*> views;
};

