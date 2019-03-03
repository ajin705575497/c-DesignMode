#include "XSubject.h"
#include <IObserver.h>





//֪ͨ�۲���
void XSubject::Notify()
{
	for (int i = 0; i < obs.size(); i++)
	{
		//�������������۲���
		obs[i]->Update(this);
	}
}

//��ӹ۲���
void XSubject::Attach(IObserver* ob)
{
	this->obs.push_back(ob);
}