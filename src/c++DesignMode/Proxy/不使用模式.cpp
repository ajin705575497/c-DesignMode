///*场景 读取日志*/
//
//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//#include <fstream>
//#include <sstream>
//using namespace std;
////log格式
////   故障名|故障时间|故障描述
//// map<int,vector<string> >  int 故障的序号，然后将（鼓掌名,故障时间,故障描述）存储起来
//
//map<int, vector<string> >Logs;
//
////切分单行的输入，灌到Logs对应的序号中
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
//		cerr << "文件打开错误" << endl;
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
//	getLogs();//获取日志文件
//	for (int i= 0; i < Logs.size(); i++) {
//		cout << "第" << i << "行是";
//		for (vector<string>::iterator iter = Logs[i].begin(); iter != Logs[i].end(); iter++) {
//			cout << (*iter) << " ";
//
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
