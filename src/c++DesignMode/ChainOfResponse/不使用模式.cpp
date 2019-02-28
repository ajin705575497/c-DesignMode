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
//	//项目经理
//	string prjHandle(double fee) {
//		if (fee >= 0 && fee < 500) {
//			return "项目经理同意" + myConvertToString(fee) + "金额";
//		}
//		else {
//			return "项目经理不同意" + myConvertToString(fee) + "金额";
//		}
//	}
//	//部门经理
//	string depHandle(double fee) {
//		if (fee >= 500 && fee < 1000) {
//			return "部门经理同意" + myConvertToString(fee) + "金额";
//		}
//		else {
//			return "部门经理不同意" + myConvertToString(fee) + "金额";
//		}
//	}
//	//项目经理
//	string CEOHandle(double fee) {
//		if (fee >= 1000 ) {
//			return "ceo同意" + myConvertToString(fee) + "金额";
//		}
//		else{
//			return "ceo不同意" + myConvertToString(fee) + "金额";
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