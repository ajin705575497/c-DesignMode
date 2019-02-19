//#include <iostream>
//
//using namespace std;
//
//class ThreePhaseOutlet {
//public:
//	void doThreePhasePlug() {
//		cout << "三项插头接口" << endl;
//	}
//};
//
//class TwoPhaseOutlet {
//public:
//	virtual void doPlug() = 0;
//};
//
////类适配器
//class OutletConverter : public TwoPhaseOutlet, public ThreePhaseOutlet {
//public:
//	void doPlug() {
//		doConvertor();
//		doThreePhasePlug();
//	}
//
//	void doConvertor() {
//		cout << "我们正在将二项插头转为三项插头" << endl;
//	}
//};
//
//
////对象适配，他可以更加灵活一些
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
//		cout << "我们正在将二项插头本身进行转化" << endl;
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