#pragma once
#include <vector>
class IObserver;

//���۲��ߵĻ���
class XSubject
{
public:
	int type = 0;
	//֪ͨ�۲���
	virtual void Notify();

	//��ӹ۲���
	virtual void Attach(IObserver* ob);

protected:
	//�۲��߶���
	std::vector<IObserver*> obs;
};

