#include <iostream>
#include <string>
#include <map>

using namespace std;

class DownloadManager;

class DownState {
public:
	virtual void Down(string User, string DownItem, DownloadManager* p) = 0;
protected:
	DownState(){}
};

class NormalDownState :public DownState {
public:
	void Down(string User, string DownItem, DownloadManager* p) {
		cout << "欢迎下载文件" << endl;
	}
};

class RepeateDownState :public DownState {
public:
	void Down(string User, string DownItem, DownloadManager* p) {
		cout << "重复下载" << endl;
	}
	
};

class SpiteDownState :public DownState {
public:
	void Down(string User, string DownItem, DownloadManager* p) {
		cout << "恶意下载" << endl;
	}

};

class BlackDownState :public DownState {
public:
	void Down(string User, string DownItem, DownloadManager* p) {
		cout << "黑名单" << endl;
	}

};

class DownloadManager {

public:
	map < string, string > getMapDown() {
		return  m_mapDown;
	}
	void Down(string user, string downItem) {
		int oldDownCount = 0;
		if (m_mapDownCount.count(user) > 0) {
			oldDownCount = m_mapDownCount[user];

		}
		else {
			m_mapDownCount[user] = 0;
		}
		oldDownCount++;
		m_mapDownCount[user] = oldDownCount;
		if (oldDownCount == 1) {
			m_pState = new NormalDownState();
		}
		else if (oldDownCount > 1 && oldDownCount < 3) {
			m_pState = new RepeateDownState();
		}
		else if (oldDownCount >= 3 && oldDownCount < 5) {
			m_pState = new SpiteDownState();
		}
		else {
			m_pState = new BlackDownState();
		}
		m_pState->Down(user, downItem, this);
	}
private:
	DownState* m_pState;//持有状态处理对象
	map<string, string> m_mapDown;
	map<string, int> m_mapDownCount;
};


int main() {
	DownloadManager* pvm = new DownloadManager;
	for (int i = 0; i < 5; i++) {
		pvm->Down("jjj", "aaa");
	}
	system("pause");
	return 0;
}