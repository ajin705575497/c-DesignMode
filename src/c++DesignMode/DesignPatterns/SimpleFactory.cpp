//#include <iostream>
//#include <string>
//using namespace std;
//
//
//class Api {
//public:
//	virtual void test(string s) = 0;
//protected:
//	Api() {};//屏蔽构造函数，体现接口
//};
//
//class Impl : public Api
//{
//public:
//	void test(string s)
//	{
//		cout << "现在是impl类，正在执行功能方法" << s << endl;
//	}
//};
//
////测试用客户端
//int main()
//{
//	Api* pApi = new Impl();
//	pApi->test("测试运行");
//	system("pause");
//	return 0;
//}
