#pragma once
#include "IObserver.h"
class IView : public IObserver
{
public:
	//��ʾĿ��
	virtual void InitDevice(void* d) = 0;

	//��ʾ����ͼ
	virtual bool InitBack(const char* url) = 0;

	//����out���
	virtual void Paint() = 0;
};

