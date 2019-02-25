#include <iostream>

using namespace std;


//设计思想：我们父类和子类就是一个扩展的关系？是不是合适
//里氏代换原则：子类对象就应该能完全替代父类的行为
//对于继承这样的设计，特别小心，   组合大于继承
//把quack和fly抽象成为一个对象，那么这个问题就可以解决了
//class Duck {
//public :
//	virtual void Quack() = 0;
//	virtual void Display() = 0;
//
//};
//
//
//class DonaladDuck :public Duck {
//public:
//	virtual void Quack() {
//		cout << "唐老鸭" << endl;
//	}
//	virtual void Display() {
//		Quack();
//	}
//
//	void fly(int param) {
//		cout << "唐老鸭 坐飞机飞" << endl;
//	}
//};
//
////第一个困境：子类似乎不太那么像父类
//class RuberDuck :public Duck {
//	virtual void Quack() {
//		//小黄鸭不会叫  空方法
//	}
//	virtual void Display() {
//		Quack();
//	}
//	
//};
//
//class WigeonDuck :public Duck {
//	virtual void Quack() {
//		cout << "小野鸭" << endl;
//	}
//	virtual void Display() {
//		Quack();
//	}
//	void fly() {
//		cout << "我在飞" << endl;
//
//	}
//};