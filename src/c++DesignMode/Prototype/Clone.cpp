#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
string iToStr(T value) {
	stringstream ss;
	ss << value;
	return ss.str();
}


class OrderApi {
public:
	virtual int getOrderProductNum() = 0;
	virtual void setOrderProductNum(int num) = 0;
	virtual string getOrderContent() = 0;
	virtual OrderApi* cloneOrder() = 0;
protected:
	OrderApi() {}
};

class HomeOrder : public OrderApi {
public:
	int getOrderProductNum() {
		return m_orderProductNum;
	}
	void setOrderProductNum(int num) {
		m_orderProductNum = num;
	}
	string getOrderContent() {
		return "���ζ����Ŀͻ���" + m_strCustomerName
			+ "������������" + iToStr(m_orderProductNum) + "������id" + m_strProductId;

	}

	void setCustomerName(string name) {
		m_strCustomerName = name;
	}

	string getCustomerName() {
		return m_strCustomerName;
	}

	void setProductId(string id) {
		m_strProductId = id;
	}

	string getProductId() {
		return m_strProductId;
	}

	//�ع�
	OrderApi* cloneOrder() {
		HomeOrder *pHomeOrder = new HomeOrder;
		pHomeOrder->setCustomerName(m_strCustomerName);
		pHomeOrder->setProductId(m_strProductId);
		pHomeOrder->setOrderProductNum(m_orderProductNum);
		return pHomeOrder;
	}
private:
	string m_strCustomerName;
	string m_strProductId;
	int m_orderProductNum;
};


class AboardOrder : public OrderApi {
public:
	int getOrderProductNum() {
		return m_orderProductNum;
	}
	void setOrderProductNum(int num) {
		m_orderProductNum = num;
	}
	string getOrderContent() {
		return "���ζ����Ŀͻ���" + m_strCustomerName
			+ "������������" + iToStr(m_orderProductNum) + "������id" + m_strProductId;

	}

	void setCustomerName(string name) {
		m_strCustomerName = name;
	}

	string getCustomerName() {
		return m_strCustomerName;
	}

	void setProductId(string id) {
		m_strProductId = id;
	}

	string getProductId() {
		return m_strProductId;
	}

	//�ع�
	OrderApi* cloneOrder() {
		AboardOrder *pAboardeOrder = new AboardOrder;
		pAboardeOrder->setCustomerName(m_strCustomerName);
		pAboardeOrder->setProductId(m_strProductId);
		pAboardeOrder->setOrderProductNum(m_orderProductNum);
		return pAboardeOrder;
	}
private:
	string m_strCustomerName;
	string m_strProductId;
	int m_orderProductNum;
};


class OrderBusiness {
public:
	void saveOrder(OrderApi* pOrder) {
		//�жϵ�ǰ�����������û�г���200
		while (pOrder->getOrderProductNum() > 200) {
			//�½�һ������
			/*OrderApi* pNewOrder = nullptr;
			//DRY dont repeat yourself
			if (dynamic_cast<HomeOrder*>(pOrder) != nullptr) {
				//����һ���¶��󣬣��ݴ����ǵ�Ŀ��
				HomeOrder* p2 = new HomeOrder;
				//��ֵ����
				HomeOrder* p1 = static_cast<HomeOrder*>(pOrder);
				p2->setOrderProductNum(200);
				p2->setCustomerName(p1->getCustomerName());
				p2->setProductId(p1->getProductId());
				pNewOrder = p2;

			}
			else if (dynamic_cast<AboardOrder*>(pOrder) != nullptr) {
				//����һ���¶��󣬣��ݴ����ǵ�Ŀ��
				AboardOrder* p2 = new AboardOrder;
				//��ֵ����
				AboardOrder* p1 = static_cast<AboardOrder*>(pOrder);
				p2->setOrderProductNum(200);
				p2->setCustomerName(p1->getCustomerName());
				p2->setProductId(p1->getProductId());
				pNewOrder = p2;

			}*/

			OrderApi* pNewOrder = pOrder->cloneOrder();
			pNewOrder->setOrderProductNum(200);

			//ԭ���Ķ��� ���Ǳ�����ֻ������Ҫ����200
			pOrder->setOrderProductNum(pOrder->getOrderProductNum() - 200);
			cout << "�¶�����" << pNewOrder->getOrderContent() << endl;
		}
		//������200��
		cout << "���յĶ�����" << pOrder->getOrderContent() << endl;
	}
};

int main(void) {

	HomeOrder* pHome = new HomeOrder;
	pHome->setOrderProductNum(512);
	pHome->setCustomerName("jjj");
	pHome->setProductId("111111");
	OrderBusiness *pOb = new OrderBusiness;
	pOb->saveOrder(pHome);

	system("pause");
	return 0;
}