///*
//AOP�������棨���棩���
//�����ǵ��ճ������У�����������������һ����ҵ���߼��޹صĿ�������������������
//���磺��log����log��Ϊ֯��ҵ�񳡾�
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
//		cout << "�������Ķ���ִ��֮ǰ����������" << endl;
//		m_ptr->OutPut(str);
//		cout << "�������Ķ���ִ��֮�󣬽�������" << endl;
//	}
//private:
//	IHello* m_ptr;
//};
//
//
//int main() {
//	std::shared_ptr<IHello> hello = std::make_shared<HelloProxy>(new Hello());
//	hello->OutPut("AOP ����");
//
//
//	system("pause");
//	return 0;
//}