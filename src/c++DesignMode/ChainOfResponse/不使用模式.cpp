//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//
//template <class T>
//string myConvertToString(T value) {
//	stringstream ss;
//	ss << value;
//	return ss.str();
//}
//
//class FeeRequest {
//public:
//	string requestToPrjManager(double fee){
//		string strTemp = "";
//		if (fee < 500) {
//			strTemp = prjHandle(fee);
//		}
//		else if (fee < 1000) {
//			strTemp = depHandle(fee);
//		}
//		else {
//			strTemp = CEOHandle(fee);
//		}
//		return strTemp;
//	}
//
//	
//private:
//	//��Ŀ����
//	string prjHandle(double fee) {
//		if (fee >= 0 && fee < 500) {
//			return "��Ŀ����ͬ��" + myConvertToString(fee) + "���";
//		}
//		else {
//			return "��Ŀ����ͬ��" + myConvertToString(fee) + "���";
//		}
//	}
//	//���ž���
//	string depHandle(double fee) {
//		if (fee >= 500 && fee < 1000) {
//			return "���ž���ͬ��" + myConvertToString(fee) + "���";
//		}
//		else {
//			return "���ž���ͬ��" + myConvertToString(fee) + "���";
//		}
//	}
//	//��Ŀ����
//	string CEOHandle(double fee) {
//		if (fee >= 1000 ) {
//			return "ceoͬ��" + myConvertToString(fee) + "���";
//		}
//		else{
//			return "ceo��ͬ��" + myConvertToString(fee) + "���";
//		}
//		
//	}
//};
//
//
//
//int main() {
//
//	FeeRequest* pRequest = new FeeRequest;
//	cout << pRequest->requestToPrjManager(300) << endl;
//	cout << pRequest->requestToPrjManager(800) << endl;
//	cout << pRequest->requestToPrjManager(3000) << endl;
//	system("pause");
//	return 0;
//}