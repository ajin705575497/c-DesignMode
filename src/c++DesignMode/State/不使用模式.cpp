//#include <iostream>
//#include <string>
//#include <map> //�û��� �û�������
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
//		//�ж���Ϊ�Ƿ�Ϸ�
//		if (oldDownCount == 1) {
//			cout << "��������" << DownItem << endl;
//			m_mapDown[user] = DownItem;
//
//		}
//		else if (oldDownCount > 1 && oldDownCount < 3) {
//			cout << "�ظ�����" << DownItem << endl;
//		}
//		else if (oldDownCount >= 3 && oldDownCount < 5) {
//			cout << "��������" << DownItem << endl;
//		}
//		else {
//			cout << "������" << endl;
//		}
//		
//	}
//private:
//	map<string, string> m_mapDown;//<�û���,�û�����ѡ��>
//	map<string, int> m_mapDownCount;//<�û��������ش���>
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