//#include <iostream>
//#include <string>
//#include <map> //用户名 用户的下载
//using namespace std;
//
//
//class DownloadManager {
//public:
//	void Down(string user, string DownItem) {
//		int oldDownCount = 0;
//		if (m_mapDownCount.count(user) > 0) {
//			oldDownCount = m_mapDownCount[user];
//
//		}
//		else {
//			m_mapDownCount[user] = 0;
//		}
//		oldDownCount++;
//		m_mapDownCount[user] = oldDownCount;
//		//判断行为是否合法
//		if (oldDownCount == 1) {
//			cout << "正常下载" << DownItem << endl;
//			m_mapDown[user] = DownItem;
//
//		}
//		else if (oldDownCount > 1 && oldDownCount < 3) {
//			cout << "重复下载" << DownItem << endl;
//		}
//		else if (oldDownCount >= 3 && oldDownCount < 5) {
//			cout << "恶意下载" << DownItem << endl;
//		}
//		else {
//			cout << "黑名单" << endl;
//		}
//		
//	}
//private:
//	map<string, string> m_mapDown;//<用户名,用户下载选项>
//	map<string, int> m_mapDownCount;//<用户名，下载次数>
//};
//
//
//int main() {
//
//	DownloadManager* pDM = new DownloadManager;
//	for (int i = 0; i < 5; i++) {
//		pDM->Down("jjj","aaa");
//	}
//	system("pause");
//	return 0;
//}