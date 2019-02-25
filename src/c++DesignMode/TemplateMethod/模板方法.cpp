#include <iostream>
#include <string>

using namespace std;

class MakeOrder {
public:
	//virtual void startOrder() = 0;  //��һ��
	// �Ľ� ���Ӻ�����ģ�巽��
	virtual void startOrder() {
		cout << "�¶�����" << endl;
	}
	virtual void replyStart() = 0;

	virtual void finishOrder() = 0;
	virtual void replyFinish() = 0;
	//ģ��ģʽ
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
		cout << "Fanuc ��ʼ���ܶ���" << endl;
	}
	void replyStart() {
		cout << "Fanuc ����Ԥ�����뽫��̶��������Ŷ�" << endl;
	}
	void finishOrder() {
		cout << "Fanuc ��ǰ�������" << endl;
	}
	void replyFinish() {
		cout << "Fanuc �����ź��Ѿ��ʹＴ���ƽ��¸�������������" << endl;
	}
};



class Sims : public MakeOrder {
public:
	void startOrder() {
		cout << "Sims ��ʼ���ܶ���" << endl;
	}
	void replyStart() {
		cout << "Sims ����Ԥ�����뽫��̶��������Ŷ�" << endl;
	}
	void finishOrder() {
		cout << "Sims ��ǰ�������" << endl;
	}
	void replyFinish() {
		cout << "Sims �����ź��Ѿ��ʹＴ���ƽ��¸�������������" << endl;
	}
};


class Mits : public MakeOrder {
public:
	//void startOrder() {
	//	cout << "Mits ��ʼ���ܶ���" << endl;
	//}
	void replyStart() {
		cout << "Mits ����Ԥ�����뽫��̶��������Ŷ�" << endl;
	}
	void finishOrder() {
		cout << "Mits ��ǰ�������" << endl;
	}
	void replyFinish() {
		cout << "Mits �����ź��Ѿ��ʹＴ���ƽ��¸�������������" << endl;
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