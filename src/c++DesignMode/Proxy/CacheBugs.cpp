///*���� ��ȡ��־*/
//
//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//#include <fstream>
//#include <sstream>
//using namespace std;
////log��ʽ
////   ������|����ʱ��|��������
//// map<int,vector<string> >  int ���ϵ���ţ�Ȼ�󽫣�������,����ʱ��,�����������洢����
//
//map<int, vector<string> > Cache;
//
//class BugManager {
//public:
//	virtual void getBug() = 0;
//};
//
//
//
//class RealBugModel {
//public :
//	void getBugs() {
//		//���ļ���ȡ�����ҽ�������Ϣ��װ����Cache������
//		ifstream in("c:\\jjj\\test\\test.txt");
//		if (!in) {
//			cerr << "�ļ��򿪴���" << endl;
//			system("pause");
//		}
//
//		string line;
//		int i = 0;
//		while (getline(in, line)) {
//			Cache[i] = getCache(line);
//			i++;
//		}
//		
//		in.close();
//	}
//
//private:
//	vector<string> getCache(string words) {
//		vector<string> results;
//		istringstream ss(words);
//		while (!ss.eof()) {
//			string word;
//			getline(ss, word, '|');
//			results.push_back(word);
//		}
//
//		return results;
//	}
//};
//
//class ProxyBugModel {
//public:
//	ProxyBugModel() :m_reload(false) {
//
//	}
//	void getBugs() {
//		if (m_reload) {
//			cout << "���Ǵӻ��������ȡ��" << endl;
//			showBugs();
//		}
//		else{
//			cout << "������ʵ������" << endl;
//			(new RealBugModel())->getBugs();
//			m_reload = true;
//			showBugs();
//			
//		}
//	}
//	void showBugs() {
//		for (int i = 0; i < Cache.size(); i++) {
//			cout << "��" << i << "����";
//			for (vector<string>::iterator iter = Cache[i].begin(); iter != Cache[i].end(); iter++) {
//				cout << (*iter) << " ";
//
//			}
//			cout << endl;
//		}
//	}
//private:
//	bool m_reload;//���true ��ʾ�ӻ�������ȡ ��������������realbug����
//};
//
//int main() {
//	ProxyBugModel*p = new ProxyBugModel();
//	for (int i = 0; i < 5; i++) {
//		cout << "��" << i << "������" << endl;
//		p->getBugs();
//	}
//
//	system("pause");
//	return 0;
//}
