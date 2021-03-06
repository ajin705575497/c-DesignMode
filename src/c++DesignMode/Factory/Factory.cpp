// Factory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//工厂模式
/*
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class ExportFileApi {
public:
	virtual bool exportData(string data) = 0;
protected:
	ExportFileApi() {}
};

//具体化的子类
class ExportTxtFile : public ExportFileApi {
public:
	bool exportData(string data) {
		cout << "正在导出数据" << data << "到csv文件" << endl;
		return true;
	}
};

class ExportDb :public ExportFileApi {
public:
	bool exportData(string data) {
		cout << "正在导出数据到" << data << "到数据库" << endl;
		return true;
	}
};

//实现一个ExportOperate  这个叫导出数据的业务功能对象
class ExportOperate {//其也是接口
public:
	bool exportData(string data) {
		ExportFileApi* pApi = factoryMethod();
		return pApi->exportData(data);
	}
protected:
	virtual ExportFileApi* factoryMethod() = 0;
};

//具体的实现对象,完成导出工作
class ExportTxtFileOperate : public ExportOperate {
protected:
	ExportFileApi* factoryMethod() {
		return new ExportTxtFile();
	}
};

class ExportTxtDBOperate : public ExportOperate {
protected:
	ExportFileApi* factoryMethod() {
		return new ExportDb();
	}
};


int main()
{
	ExportOperate* pOperate = new ExportTxtFileOperate();
	pOperate->exportData("test");
	system("pause");
    std::cout << "Hello World!\n"; 
	return 0;
}

*/

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

