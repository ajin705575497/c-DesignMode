#include "IController.h"
#include "IView.h"

#include "XModel.h"

IController::IController()
{
}


IController::~IController()
{
}


IController* IController::Create(IControllerFactory* f)
{
	if (!f)
		return 0;
	IController *c = f->CreateC();
	c->f = f;
	//c->m = f->CreateM();
	c->v = f->CreateV();
	return c;


}


void IController::Init(void *device)
{
	AddModel(XIMAGE);
	v->InitDevice(device);
}

void IController::Paint()
{
	v->Paint();
}

bool IController::InitBack(const char*url)
{
	bool re = v->InitBack(url);
	//添加背景图
	AddModel(XIMAGE);
	return re;
}


void IController::AddModel(int s)
{
	if (s < 0)
		s = status;
	//创建模型，添加观察者
	m = f->CreateM();
	m->Attach(v);
	m->type = s;
	tasks.push_back(m);
}

void IController::Add(int x, int y)
{
	if (!m)
		return;
	m->Add(XPos(x, y));
	NotfyAll();

}

void IController::NotfyAll()
{
	int size = tasks.size();
	for (int i = 0; i < size; i++)
	{
		tasks[i]->Notify();
	}
}

void IController::Undo()
{
	int last = tasks.size() -1;
	if (last < 1)
		return;
	retasks.push_back(tasks[last]);
	tasks.pop_back();
	NotfyAll();
}

void IController::Redo()
{
	if (retasks.empty())
		return;
	int rLast = retasks.size() - 1;
	tasks.push_back(retasks[rLast]);
	retasks.pop_back();
	NotfyAll();
}

void IController::setPara(std::string key, int val)
{
	if (!m)
		return;
	m->setPara(key, val);
}
