//
//#include <afxwin.h>
//#include <iostream>
//#include <stdio.h>
//
//using namespace std;
//CRITICAL_SECTION g_cs;
//
//class Singleton {
//public:
//	static Singleton* getInstance() {//懒汉式
//		if (m_singer == NULL) {
//			::EnterCriticalSection(&g_cs);
//			if(m_singer == NULL)
//				m_singer = new Singleton;
//			::LeaveCriticalSection(&g_cs);
//		}
//		return m_singer;
//	}
//
//private:
//	Singleton() {
//		m_singer = NULL;
//		cout << "构造了一个Singleton对象" << endl;
//	}
//private:
//	static Singleton* m_singer;
//};
//
//UNIT Func(LPVOID) {
//	printf("%x\n", Singleton::getInstance());
//	return 0;
//}
//
//Singleton * Singleton::m_singer = NULL; //懒汉氏 延迟加载
////Singleton * Singleton::m_singer = new Singleton; //C++中构造函数不是线程安全的  
//int main() {
//	//Singleton* p1 = Singleton::getInstance();
//	//Singleton* p2 = Singleton::getInstance();
//	//printf("p1=%x,p2=%x", p1, p2);
//	::InitializeCriticalSection(&g_cs);
//	for (int i = 0; i < 10; i++) {
//		AfxBeginThread(Func, NULL);
//	}
//	::DeleteCriticalSection(&g_cs);
//	system("pause");
//	return 0;
//}