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
		return "本次订单的客户是" + m_strCustomerName
			+ "订单的数量是" + iToStr(m_orderProductNum) + "订单的id" + m_strProductId;

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

	//重构
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
		return "本次订单的客户是" + m_strCustomerName
			+ "订单的数量是" + iToStr(m_orderProductNum) + "订单的id" + m_strProductId;

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

	//重构
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
		//判断当前攻坚的数量有没有超过200
		while (pOrder->getOrderProductNum() > 200) {
			//新建一个订单
			/*OrderApi* pNewOrder = nullptr;
			//DRY dont repeat yourself
			if (dynamic_cast<HomeOrder*>(pOrder) != nullptr) {
				//创建一个新对象，，暂存我们的目标
				HomeOrder* p2 = new HomeOrder;
				//赋值对象
				HomeOrder* p1 = static_cast<HomeOrder*>(pOrder);
				p2->setOrderProductNum(200);
				p2->setCustomerName(p1->getCustomerName());
				p2->setProductId(p1->getProductId());
				pNewOrder = p2;

			}
			else if (dynamic_cast<AboardOrder*>(pOrder) != nullptr) {
				//创建一个新对象，，暂存我们的目标
				AboardOrder* p2 = new AboardOrder;
				//赋值对象
				AboardOrder* p1 = static_cast<AboardOrder*>(pOrder);
				p2->setOrderProductNum(200);
				p2->setCustomerName(p1->getCustomerName());
				p2->setProductId(p1->getProductId());
				pNewOrder = p2;

			}*/

			OrderApi* pNewOrder = pOrder->cloneOrder();
			pNewOrder->setOrderProductNum(200);

			//原来的订单 还是保留，只是数量要减少200
			pOrder->setOrderProductNum(pOrder->getOrderProductNum() - 200);
			cout << "新订单是" << pNewOrder->getOrderContent() << endl;
		}
		//不超过200个
		cout << "最终的订单是" << pOrder->getOrderContent() << endl;
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