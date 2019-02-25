#include <iostream>

using namespace std;


//设计思想：我们父类和子类就是一个扩展的关系？是不是合适
//里氏代换原则：子类对象就应该能完全替代父类的行为
//对于继承这样的设计，特别小心，   组合大于继承
//把quack和fly抽象成为一个对象，那么这个问题就可以解决了


//完成了将 动作 抽象成 对象
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
		cout << "坐着火箭飞" << endl;

	}
};

class FlyWithWings :public FlyBehavior {
public:
	void fly() {
		cout << "用翅膀飞" << endl;

	}
};

class FlyWithNoWay :public FlyBehavior {
public:
	void fly() {
		cout << "不会飞" << endl;
	}
};

class ZhiZhiQuack :public QuackBehavior {
public:
	void quack() {
		cout << "吱吱叫" << endl;
	}
};

class PersonQuack :public QuackBehavior {
public:
	void quack() {
		cout << "我是唐老鸭" << endl;
	}
};

class WingeonQuack :public QuackBehavior {
public:
	void quack() {
		cout << "丑小鸭变天鹅" << endl;
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
		m_pFly = new FlyWithRocket;//某一个FlyBehavior的实例
		m_pQuack = new PersonQuack;
	}
	
	virtual void Display() {
		performFly();
		performQuack();
	}

	
private:
};

//第一个困境：子类似乎不太那么像父类
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