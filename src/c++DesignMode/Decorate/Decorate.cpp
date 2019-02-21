//#include <iostream>
//#include <sstream>
//#include <string>
//
//using namespace std;
//
//template <class T>
//string MyConvertToStr(T obj) {
//	stringstream ss;
//	ss << obj;
//	return ss.str();
//}
//
//class Beverage {
//public:
//	virtual string getDescription() = 0;
//	virtual double cost() = 0;
//
//protected:
//	string m_Description;
//};
//
//
//class CondimentDecorate :public Beverage {
//public:
//	virtual string getDescription() = 0;
//protected:
//	CondimentDecorate(){}
//};
//
////װ����1
//class Soy : public CondimentDecorate {
//public:
//	Soy(Beverage*pBeverage) :m_pBeverage(pBeverage) {
//		
//	}
//	string getDescription() {
//		return m_pBeverage->getDescription() + ",���˽�����";
//	}
//	double cost() {
//		return 0.1 + m_pBeverage->cost();
//	}
//private:
//	//���б�װ�εĶ���
//	Beverage*m_pBeverage;
//};
//
//
////װ����2
//class Milk : public CondimentDecorate {
//public:
//	Milk(Beverage*pBeverage) :m_pBeverage(pBeverage) {
//
//	}
//	string getDescription() {
//		return m_pBeverage->getDescription() + ",����ţ����";
//	}
//	double cost() {
//		return 2 + m_pBeverage->cost();
//	}
//private:
//	//���б�װ�εĶ���
//	Beverage*m_pBeverage;
//};
//
//class Lattee :public Beverage {
//public:
//	Lattee() {
//		m_Description = "����";
//	}
//	string getDescription() {
//		return m_Description;
//	}
//	double cost() {
//		return 13;
//	}
//private:
//};
//
//class Expresso :public Beverage {
//public:
//	Expresso() {
//		m_Description = "Ũ������";
//	}
//	string getDescription() {
//		return m_Description;
//	}
//	double cost() {
//		return 12;
//	}
//private:
//};
//
//class Mocha :public Beverage {
//public:
//	Mocha() {
//		m_Description = "Ħ������";
//	}
//	string getDescription() {
//		return m_Description;
//	}
//	double cost() {
//		return 11;
//	}
//private:
//};
//
//
//int main() {
//
//	Beverage* pBeverage = new Expresso();
//	cout << pBeverage->getDescription() << "�۸���" << MyConvertToStr(pBeverage->cost())<<endl;
//
//	Beverage* pBeverage2 = new Mocha();
//	pBeverage2 = new Soy(pBeverage2);
//	pBeverage2 = new Soy(pBeverage2);
//	cout << pBeverage2->getDescription() << "�۸���" << MyConvertToStr(pBeverage2->cost()) << endl;
//
//	system("pause");
//	return 0;
//}