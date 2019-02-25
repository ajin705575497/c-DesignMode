#include <iostream>

using namespace std;


//���˼�룺���Ǹ�����������һ����չ�Ĺ�ϵ���ǲ��Ǻ���
//���ϴ���ԭ����������Ӧ������ȫ����������Ϊ
//���ڼ̳���������ƣ��ر�С�ģ�   ��ϴ��ڼ̳�
//��quack��fly�����Ϊһ��������ô�������Ϳ��Խ����


//����˽� ���� ����� ����
class QuackBehavior {
public:
	virtual void quack() = 0;
protected:
	QuackBehavior(){}
};

class FlyBehavior {
public:
	virtual void fly() = 0;
protected:
	FlyBehavior(){}
};

class FlyWithRocket :public FlyBehavior {
public:
	void fly() {
		cout << "���Ż����" << endl;

	}
};

class FlyWithWings :public FlyBehavior {
public:
	void fly() {
		cout << "�ó���" << endl;

	}
};

class FlyWithNoWay :public FlyBehavior {
public:
	void fly() {
		cout << "�����" << endl;
	}
};

class ZhiZhiQuack :public QuackBehavior {
public:
	void quack() {
		cout << "֨֨��" << endl;
	}
};

class PersonQuack :public QuackBehavior {
public:
	void quack() {
		cout << "��������Ѽ" << endl;
	}
};

class WingeonQuack :public QuackBehavior {
public:
	void quack() {
		cout << "��СѼ�����" << endl;
	}
};

//Duck has a Quack
//and  has a Fly
class Duck {
public :
	virtual void Display() = 0;
	void setFlyBehavor(FlyBehavior* fb) {
		m_pFly = fb;
	}
	void setQuackBehavior(QuackBehavior* qb) {
		m_pQuack = qb;
	}

	void performFly() {
		m_pFly->fly();
	}

	void performQuack() {
		m_pQuack->quack();
	}
protected:
	QuackBehavior *m_pQuack;
	FlyBehavior *m_pFly;
};


//DonaladDuck is Duck
class DonaladDuck :public Duck {
public:

	DonaladDuck() {
		m_pFly = new FlyWithRocket;//ĳһ��FlyBehavior��ʵ��
		m_pQuack = new PersonQuack;
	}
	
	virtual void Display() {
		performFly();
		performQuack();
	}

	
private:
};

//��һ�������������ƺ���̫��ô����
class RuberDuck :public Duck {
public:

	RuberDuck() {
		m_pFly = new FlyWithNoWay;
		m_pQuack = new ZhiZhiQuack;
	}
	virtual void Display() {
		performFly();
		performQuack();
	}
	
};

class WigeonDuck :public Duck {
public:
	WigeonDuck() {
		m_pFly = new FlyWithWings;
		m_pQuack = new WingeonQuack;
	}
	virtual void Display() {
		performFly();
		performQuack();
	}
	
};



int main() {
	DonaladDuck *pDuck = new DonaladDuck;
	pDuck->Display();

	system("pause");
	return 0;
}