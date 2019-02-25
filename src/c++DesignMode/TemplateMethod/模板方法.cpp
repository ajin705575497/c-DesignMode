#include <iostream>
#include <string>

using namespace std;

class MakeOrder {
public:
	//virtual void startOrder() = 0;  //第一版
	// 改进 钩子函数的模板方法
	virtual void startOrder() {
		cout << "下订单了" << endl;
	}
	virtual void replyStart() = 0;

	virtual void finishOrder() = 0;
	virtual void replyFinish() = 0;
	//模板模式
	void make() {
		startOrder();
		replyStart();
		finishOrder();
		replyFinish();
	}
protected:
	MakeOrder(){}
};

class Fanuc : public MakeOrder {
public:
	void startOrder() {
		cout << "Fanuc 开始接受订单" << endl;
	}
	void replyStart() {
		cout << "Fanuc 做好预备，请将后继订单进入排队" << endl;
	}
	void finishOrder() {
		cout << "Fanuc 当前订单完成" << endl;
	}
	void replyFinish() {
		cout << "Fanuc 订单信号已经送达即将推进下个订单进入生产" << endl;
	}
};



class Sims : public MakeOrder {
public:
	void startOrder() {
		cout << "Sims 开始接受订单" << endl;
	}
	void replyStart() {
		cout << "Sims 做好预备，请将后继订单进入排队" << endl;
	}
	void finishOrder() {
		cout << "Sims 当前订单完成" << endl;
	}
	void replyFinish() {
		cout << "Sims 订单信号已经送达即将推进下个订单进入生产" << endl;
	}
};


class Mits : public MakeOrder {
public:
	//void startOrder() {
	//	cout << "Mits 开始接受订单" << endl;
	//}
	void replyStart() {
		cout << "Mits 做好预备，请将后继订单进入排队" << endl;
	}
	void finishOrder() {
		cout << "Mits 当前订单完成" << endl;
	}
	void replyFinish() {
		cout << "Mits 订单信号已经送达即将推进下个订单进入生产" << endl;
	}
};

int main() {
	//MakeOrder *pMakeOrder = new Fanuc;
	//pMakeOrder->make();

	MakeOrder * pMakeOrder = new Mits;
	pMakeOrder->make();

	system("pause");
	return 0;
}