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
//map<int, vector<string> >Logs;
//
////�зֵ��е����룬�ൽLogs��Ӧ�������
//vector<string> getBus(string words) {
//	vector<string> results;
//	istringstream ss(words);
//	while (!ss.eof()) {
//		string word;
//		getline(ss, word, '|');
//		results.push_back(word);
//	}
//
//	return results;
//}
//
//bool getLogs() {
//	ifstream in("c:\\jjj\\test\\test.txt");
//	if (!in) {
//		cerr << "�ļ��򿪴���" << endl;
//		system("pause");
//		return false;
//	}
//
//	string line;
//	int i = 0;
//	while (getline(in, line)) {
//		Logs[i] = getBus(line);
//		i++;
//	}
//	in.close();
//	return true;
//}
//
//int main() {
//	getLogs();//��ȡ��־�ļ�
//	for (int i= 0; i < Logs.size(); i++) {
//		cout << "��" << i << "����";
//		for (vector<string>::iterator iter = Logs[i].begin(); iter != Logs[i].end(); iter++) {
//			cout << (*iter) << " ";
//
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
