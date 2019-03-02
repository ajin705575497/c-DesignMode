//#include <iostream>
//#include <map>
//#include <stdio.h>
//
//using namespace std;
//
//class Singleton;
//static std::map<string, Singleton*> myMap = std::map<string, Singleton*>();
//
////懒汉式 - 延迟加载
//class Singleton {
//private:
//	Singleton() {
//		m_singer = NULL;
//		cout << "单例正在创建" << endl;
//	}
//public:
//	static Singleton* getInstance() {
//		//std::map<string, Singleton*>::iterator it = myMap.find("xxx");
//		if (myMap.find(DEFAULT_KEY) != myMap.end()){
//			return myMap.find(DEFAULT_KEY)->second;
//
//		}
//		if (m_singer == NULL) {
//			m_singer = new Singleton;
//			myMap[DEFAULT_KEY] = m_singer;
//		}
//		return m_singer;
//	}
//private:
//	static Singleton* m_singer;
//	static string DEFAULT_KEY;
//};
//
//Singleton* Singleton::m_singer = NULL;
//string Singleton::DEFAULT_KEY = "one";
//
//
//int main() {
//	Singleton* p1 = Singleton::getInstance();
//	Singleton* p2 = Singleton::getInstance();
//	printf("p1=%x,p2=%x", p1, p2);
//	system("pause");
//	return 0;
//}