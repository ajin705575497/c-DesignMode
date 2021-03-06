// Visitor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

class XiaoMi;
class HuaWei;
class Oppo;
class CellPhoneVisitor {
public:
	virtual void visit(XiaoMi* p) = 0;
	virtual void visit(HuaWei* p) = 0;
	virtual void visit(Oppo* p) = 0;
protected:
	CellPhoneVisitor(){}
};

class CellPhone {
public:
	virtual void dial() = 0;
	virtual void sendMsg() = 0;
	virtual void hang() = 0;
	virtual void recvMsg() = 0;
	virtual void accept(CellPhoneVisitor* p) = 0;
protected:
	CellPhone(){}
};

class XiaoMi : public CellPhone {
public:
	void dial() {
		cout << "小米在拨号" << endl;
	}
	void sendMsg() {
		cout << "小米在发短信" << endl;
	}
	void hang() {
		cout << "小米在挂电话" << endl;
	}
	void recvMsg() {
		cout << "小米在收短信" << endl;
	}
	void accept(CellPhoneVisitor* p) {
		p->visit(this);
	}
};

class HuaWei : public CellPhone {
public:
	void dial() {
		cout << "HuaWei在拨号" << endl;
	}
	void sendMsg() {
		cout << "HuaWei在发短信" << endl;
	}
	void hang() {
		cout << "HuaWei在挂电话" << endl;
	}
	void recvMsg() {
		cout << "HuaWei在收短信" << endl;
	}
	void accept(CellPhoneVisitor* p) {
		p->visit(this);
	}
};

class Oppo : public CellPhone {
public:
	void dial() {
		cout << "Oppo在拨号" << endl;
	}
	void sendMsg() {
		cout << "Oppo在发短信" << endl;
	}
	void hang() {
		cout << "Oppo在挂电话" << endl;
	}
	void recvMsg() {
		cout << "Oppo在收短信" << endl;
	}
	void accept(CellPhoneVisitor* p) {
		p->visit(this);
	}
};


class SolarisConfigure :public CellPhoneVisitor {
public:
	void visit(XiaoMi*p) {
		p->dial();
		p->hang();
		p->sendMsg();
		p->recvMsg();
	}
	void visit(HuaWei*p) {
		p->dial();
		p->hang();
		p->sendMsg();
		p->recvMsg();
	}
	void visit(Oppo*p) {
		p->dial();
		p->hang();
		p->sendMsg();
		p->recvMsg();
	}
};

int main()
{
	CellPhoneVisitor* pVisitor = new SolarisConfigure;
	XiaoMi* pXiaoMi = new XiaoMi;
	HuaWei* pHuaWei = new HuaWei;
	Oppo* pOppo = new Oppo();
	cout << "将Solairs环境配置给XiaoMi" << endl;
	pXiaoMi->accept(pVisitor);
	cout << "将Solairs环境配置给HuaWei" << endl;
	pHuaWei->accept(pVisitor);
	cout << "将Solairs环境配置给Oppo" << endl;
	pOppo->accept(pVisitor);
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
