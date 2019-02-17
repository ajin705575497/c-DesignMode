///*
//ģ����˵�����
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
//	string m_strDepId;//���˵��Ĳ���id
//	string m_strExportDate;//���˵��ĵ�������
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
//	string m_strTransId;//����id
//	double m_Quantity;//���
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
////���ǵ���һ���������ڣ������ж�ʶ��˼�¼,ʹ��vector��¼
//
//class ExportToTxtHelper {
//public:
//	void doExport(ExportHeaderModel& ehm, vector<ExportDataModel*>& edmCollection, ExporFooterModel& efm) {
//		//��һ���ַ���ƴ��
//		string strTemp = "";
//		//��һ����д�ļ�ͷ
//		strTemp += ehm.getDepId() + "," + ehm.getExportDate() + "\n";
//		//�ڶ�����д�ļ�������
//		for (vector<ExportDataModel*>::iterator iter = edmCollection.begin(); iter != edmCollection.end(); iter++) {
//			strTemp += (*iter)->getTransId() + ":" + ConverToString((*iter)->getQuantity()) + "\n";
//
//				
//		}
//		//��������ƴ���ļ�β
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
//		//��һ���ַ���ƴ��
//		string strTemp = "";
//		//��һ����д�ļ�ͷ
//		strTemp.append("<?xml version='1.0' encoding='utf-8'>\n");
//		strTemp.append("<Receipt>\n");
//		strTemp.append("    <Header>\n");
//		strTemp.append("        <DepId>");
//		strTemp.append(ehm.getDepId() + "</DepId>\n");
//		strTemp.append("        <ExportDate>").append(ehm.getExportDate()).append("</ExportDate>\n");
//		strTemp.append("    </Header>\n");
//		//�ڶ�����д�ļ�������
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
//		//��������ƴ���ļ�β
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
//	ExportHeaderModel *pEhm = new ExportHeaderModel("�й�����", "6��1��");
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