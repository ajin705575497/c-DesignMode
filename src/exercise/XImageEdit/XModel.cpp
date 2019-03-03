#include "XModel.h"



void XModel::Add(XPos pos)
{
	this->poss.push_back(pos);
	//通知观察者
	//this->Notify();
}

void XModel::setPara(std::string key, int val)
{
	//如果有值就修改，没有就插入
	if (paras.find(key) == paras.end())
		paras.insert(make_pair(key, val));
	else
		paras[key] = val;
}

int XModel::getPara(std::string key)
{
	if (paras.find(key) == paras.end())
		return 0;
	return paras[key];
}

XModel::XModel()
{
}


XModel::~XModel()
{
}
