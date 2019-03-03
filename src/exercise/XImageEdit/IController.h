#pragma once
#include "IControllerFactory.h"
#include <vector>

enum XSTATUS {
	XPEN,
	XERASER,
	XRECT,
	XIMAGE
};
class IController
{
public:
	static IController* Create(IControllerFactory* f);
	virtual void Init(void *device);
	virtual void Paint();
	virtual bool InitBack(const char*url);
	//���ģ�Ͷ��� Ĭ��-1 ȡ��ǰ״̬
	virtual void AddModel(int s = -1);
	//����ǰģ���������
	virtual void Add(int x,int y);
	virtual void SetStatus(XSTATUS s) { status = s; }
	virtual void NotfyAll();
	virtual void Undo();
	virtual void Redo();
	virtual void setPara(std::string key,int val );

	IController();
	~IController();
protected:
	IView* v = 0;
	XModel* m = 0;
	IControllerFactory* f = 0;
	//�������
	std::vector<XModel*> tasks;
	std::vector<XModel*> retasks;
	XSTATUS status = XPEN;
};

