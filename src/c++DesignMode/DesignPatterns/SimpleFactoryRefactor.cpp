#include <iostream>
#include <string>
#include "DynOBJ.h"
using namespace std;

class Api {
public:
	virtual void test(string s) = 0;
protected:
	Api() {};
};

class ImpleOne : public Api {
public:
	void test(string s)
	{
		cout << "现在是One再执行" << s << endl;
	}
};

class ImpleTwo : public Api {
public:
	void test(string s)
	{
		cout << "现在是Two再执行" << s << endl;
	}
};

class Factory {
public:
	static Api* createApi(int type)
	{
		Api* pApi = nullptr;
		if (type == 1)
		{
			pApi = new ImpleOne();
		}
		if (type == 2)
		{
			pApi = new ImpleTwo();
		}
		return pApi;

	}
	static Api* createApi()
	{
		return new ImpleOne();
	}
};

/*
传入参数1 可以实现从数据库读入的功能
传入参数2 可以实现从文件读入的功能
*/
int main1()
{
	Api* pApi = Factory::createApi(2);//客户端还是知道工厂的细节
	pApi->test("现在是使用简单工厂方法重构");


	Api* pApiEx = Factory::createApi();

	system("pause");
	return 0;
}

//实现了客户端调用和implOne,implTwo的解耦
//factory类实现了变化隔离


//问题的需求：

/*
static Api* createApi()
{
	return new ImpleOne();//ImplOne, ImplTwo?
}

动态创建
*/

//class ImpleTwoHelper
//{
//public:
//
//	ImpleTwoHelper()
//	{
//		CObjectFactory::registerClass("ImpleTwo", ImpleTwoHelper::createObjFunc);
//	}
//
//	static void* createObjFunc()
//	{
//		return new ImpleTwo;
//	}
//};

REG_CLASS(ImpleTwo)
//class ImpleTwoHelper { public: ImpleTwoHelper() { CObjectFactory::registerClass("ImpleTwo", ImpleTwoHelper::createObjFunc); } static void* createObjFunc() { return new ImpleTwo; } }; ImpleTwoHelper ImpleTwohelper;
int main2()
{
	//ImpleTwo* pTwo = static_cast<ImpleTwo*>(ImpleTwoHelper::createObjFunc());
	//pTwo->test("测试动态创建");


	ImpleTwo* pTwo = static_cast<ImpleTwo*>(CObjectFactory::createObject("ImpleTwo"));
	pTwo->test("RegClass");

	system("pause");
	return 0;
}


class AutoFactory
{
public:
	static Api* createApi()
	{
		Api* pApi = nullptr;
		pApi = static_cast<Api*>(CObjectFactory::createObject("ImpleTwo"));
		return pApi;
	}
};

int main()
{
	Api* pApi = AutoFactory::createApi();
	pApi->test("不知道里面的东西");

	system("pause");
	return 0;
}