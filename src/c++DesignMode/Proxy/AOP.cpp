///*
//AOP：面向方面（切面）编程
//在我们的日常开发中，经常会遇到这样的一类与业务逻辑无关的开发，称作正交化开发
//比如：打log，将log行为织入业务场景
//
//*/
//
//#include <iostream>
//#include <string>
//#include <memory>
//using namespace std;
//
//class IHello {
//public:
//	IHello() {
//
//	}
//	~IHello(){
//	
//	}
//	virtual void OutPut(const string& str) {
//
//	}
//};
//
//class Hello :public IHello {
//public:
//
//
//	void OutPut(const string& str) override {
//		cout << str << endl;
//	}
//};
//
//class HelloProxy : public IHello {
//public:
//	HelloProxy(IHello*p) :m_ptr(p) {
//
//	}
//	~HelloProxy() {
//		delete m_ptr;
//		m_ptr = nullptr;
//	}
//
//	void OutPut(const string& str) final {
//		cout << "在真正的对象执行之前，进行拦截" << endl;
//		m_ptr->OutPut(str);
//		cout << "在真正的对象执行之后，进行拦截" << endl;
//	}
//private:
//	IHello* m_ptr;
//};
//
//
//int main() {
//	std::shared_ptr<IHello> hello = std::make_shared<HelloProxy>(new Hello());
//	hello->OutPut("AOP 测试");
//
//
//	system("pause");
//	return 0;
//}