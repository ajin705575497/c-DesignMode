///*
//模拟对账单导出
//*/
//
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <sstream>
//using namespace std;
//
//template<class T>
//string ConverToString(T value) {
//	stringstream ss;
//	ss << value;
//	return ss.str();
//}
//
//
//class ExportHeaderModel {
//public:
//	ExportHeaderModel(string strDepId, string strExportDate):m_strDepId(strDepId),m_strExportDate(strExportDate) {}
//	string getDepId() {
//		return m_strDepId;
//	}
//	string getExportDate() {
//		return m_strExportDate;
//	}
//private:
//	string m_strDepId;//对账单的部门id
//	string m_strExportDate;//对账单的导出日期
//};
//
//class ExportDataModel {
//public:
//	ExportDataModel(string strTransId, double quantity) :m_strTransId(strTransId), m_Quantity(quantity) {
//
//	}
//	string getTransId() {
//		return m_strTransId;
//	}
//	double getQuantity() {
//		return m_Quantity;
//	}
//private:
//	string m_strTransId;//交易id
//	double m_Quantity;//金额
//
//};
//
//class ExporFooterModel {
//public:
//	ExporFooterModel(string exportUser) :m_exportUser(exportUser) {
//
//	}
//	string getExportUser() {
//		return m_exportUser;
//	}
//private:
//	string m_exportUser;
//};
//
////考虑到在一个对账周期，可能有多笔对账记录,使用vector记录
//
//class ExportToTxtHelper {
//public:
//	void doExport(ExportHeaderModel& ehm, vector<ExportDataModel*>& edmCollection, ExporFooterModel& efm) {
//		//用一个字符串拼接
//		string strTemp = "";
//		//第一步：写文件头
//		strTemp += ehm.getDepId() + "," + ehm.getExportDate() + "\n";
//		//第二步：写文件体数据
//		for (vector<ExportDataModel*>::iterator iter = edmCollection.begin(); iter != edmCollection.end(); iter++) {
//			strTemp += (*iter)->getTransId() + ":" + ConverToString((*iter)->getQuantity()) + "\n";
//
//				
//		}
//		//第三步：拼接文件尾
//		strTemp += efm.getExportUser() + "\n";
//		cout << strTemp;
//
//
//	}
//};
//
//class ExportToXMLHelper {
//public:
//	void doExport(ExportHeaderModel& ehm, vector<ExportDataModel*>& edmCollection, ExporFooterModel& efm) {
//		//用一个字符串拼接
//		string strTemp = "";
//		//第一步：写文件头
//		strTemp.append("<?xml version='1.0' encoding='utf-8'>\n");
//		strTemp.append("<Receipt>\n");
//		strTemp.append("    <Header>\n");
//		strTemp.append("        <DepId>");
//		strTemp.append(ehm.getDepId() + "</DepId>\n");
//		strTemp.append("        <ExportDate>").append(ehm.getExportDate()).append("</ExportDate>\n");
//		strTemp.append("    </Header>\n");
//		//第二步：写文件体数据
//		strTemp.append("    <Body>\n");
//		
//		for (vector<ExportDataModel*>::iterator iter = edmCollection.begin(); iter != edmCollection.end(); iter++) {
//			strTemp.append("        <id>").append((*iter)->getTransId()).append("</id>\n");
//			strTemp.append("        <amount>").append(ConverToString((*iter)->getQuantity())).append("</amount>\n");
//
//			
//			
//	
//
//		}
//
//		strTemp.append("    </Body>\n");
//
//		
//		//第三步：拼接文件尾
//		strTemp.append("    <Footer>\n");
//		strTemp.append("        <ExportUser>").append(efm.getExportUser()).append("</ExportUser>\n");
//		strTemp.append("    </Footer>\n");
//
//		strTemp.append("</Receipt>\n");
//
//		cout << strTemp;
//
//
//	}
//};
//
//
//int main() {
//
//	ExportHeaderModel *pEhm = new ExportHeaderModel("中国银行", "6月1日");
//	ExportDataModel *pEdm = new ExportDataModel("1", 1000.00f);
//	ExportDataModel *pEdm2 = new ExportDataModel("2", 2000.00f);
//	vector<ExportDataModel*> myVec;
//	myVec.push_back(pEdm);
//	myVec.push_back(pEdm2);
//
//	ExporFooterModel *efm = new ExporFooterModel("jjj");
//
//	//ExportToTxtHelper helper;
//	ExportToXMLHelper helper;
//	helper.doExport(*pEhm, myVec, *efm);
//	system("pause");
//	return 0;
//}