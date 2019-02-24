/*场景：操作系统的组装*/
#include <iostream>

using namespace std;

//class Computer {
//public:
//	void run();
//};
//
//class HpWindows7 : public Computer {
//
//};
//
//class HpWindows8 :public Computer {
//
//};
//
//class HpWindowsX :public Computer {
//
//};


class IOS {
public:
	IOS(){}
	virtual ~IOS(){}
	virtual void run() = 0;
};

class CWindows :public IOS {
public:
	virtual void run() {
		cout << "Windows 正在运行" << endl;
	}
};

class CLinux : public IOS {
public:
	virtual void run() {
		cout << "Linux 正在运行" << endl;
	}
};


class IComputer {
public:
	virtual void Install(IOS *pOS) = 0;
};

class CLenvo :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Lenvo正在安装操作系统" << endl;
		pOS->run();
	}
};

class CDell :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Dell正在安装操作系统" << endl;
		pOS->run();
	}
};

class CAcer :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Acer正在安装操作系统" << endl;
		pOS->run();
	}
};

int main() {

	IOS* pWindows = new CWindows();
	IOS* pLinux = new CLinux();

	IComputer * pLenvo = new CLenvo;
	pLenvo->Install(pWindows);



	system("pause");
	return 0;
}