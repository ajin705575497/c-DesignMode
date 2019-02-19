//#include <iostream>
//
//using namespace std;
//
//class ThreePhaseOutlet {
//public:
//	void doThreePhasePlug() {
//		cout << "�����ͷ�ӿ�" << endl;
//	}
//};
//
//class TwoPhaseOutlet {
//public:
//	virtual void doPlug() = 0;
//};
//
////��������
//class OutletConverter : public TwoPhaseOutlet, public ThreePhaseOutlet {
//public:
//	void doPlug() {
//		doConvertor();
//		doThreePhasePlug();
//	}
//
//	void doConvertor() {
//		cout << "�������ڽ������ͷתΪ�����ͷ" << endl;
//	}
//};
//
//
////�������䣬�����Ը������һЩ
//class OutletObjConvert : public TwoPhaseOutlet {
//public:
//
//	OutletObjConvert(ThreePhaseOutlet* pOut) :m_pOut(pOut) {
//
//	}
//	void doPlug() {
//		doConvert();
//		m_pOut->doThreePhasePlug();
//	}
//
//	void doConvert() {
//		cout << "�������ڽ������ͷ�������ת��" << endl;
//	}
//private:
//	ThreePhaseOutlet * m_pOut;
//};
//
//int main() {
//
//	TwoPhaseOutlet* pOutlet = new OutletConverter();
//	pOutlet->doPlug();
//
//	TwoPhaseOutlet* pOutlet2 = new OutletObjConvert(new ThreePhaseOutlet);
//	pOutlet2->doPlug();
//
//	system("pause");
//	return 0;
//}