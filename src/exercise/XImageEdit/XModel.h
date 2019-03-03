#pragma once
#include "XSubject.h"
#include <map>
struct XPos
{
	XPos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x = 0;
	int y = 0;
};

//被观察者
class XModel :
	public XSubject
{
public:
	//点坐标
	std::vector<XPos> poss;
	void Add(XPos pos);
	void setPara(std::string key,int val);
	int getPara(std::string key);
	XModel();
	~XModel();

private:
	std::map<std::string , int > paras;
};

