#include <iostream>
#include <string>
#include <vector>
using namespace std;

//观察者
class Observer {
public:
	virtual void update(string strTemp, string strhumi) = 0;
protected:
	Observer() {}
};

//抽象一个Subject主题

class Subject {
public:
	virtual void registerObserver(Observer * pObj)=0;
	virtual void removeObserver(Observer *pObj)=0;
	virtual void noitfyObserver() = 0;
protected:
	Subject(){}
};


class WeatherData :public Subject {
public:
	WeatherData(string strTemp, string strHumi):m_temp(strTemp),m_humi(strHumi) {
		
	}
	void registerObserver(Observer* pObj) {
		m_observers.push_back(pObj);
	}
	void removeObserver(Observer* pObj) {
		auto iter = find(m_observers.begin(), m_observers.end(), pObj);
		if ( iter != m_observers.end()) {
			m_observers.erase(iter);
		}
	}

	void noitfyObserver() {
		//逐个遍历调用Observer的update方法
		for (vector<Observer*>::iterator iter = m_observers.begin(); iter != m_observers.end(); iter++) {
			(*iter)->update(m_temp,m_humi);
		}
	}

	void setData(string strtemp, string strhumi) {
		m_temp = strtemp;
		m_humi = strhumi;
		noitfyObserver();
	}
private:
	vector<Observer*> m_observers;
	string m_temp;
	string m_humi;

};


class PCDisplay :public Observer {
public:
	void update(string strTemp, string strHumi) {
		cout << "pc显示当前的温度为" << strTemp << "湿度为" << strHumi << endl;
	}

	PCDisplay(WeatherData* pWeatherData) {
		m_pWeatherData = pWeatherData;
		m_pWeatherData->registerObserver(this);
	}
private:
	WeatherData* m_pWeatherData;
};

class MobileDisplay :public Observer {
public:
	void update(string strTemp, string strHumi) {
		cout << "mobile显示当前的温度为" << strTemp << "湿度为" << strHumi << endl;
	}

	MobileDisplay(WeatherData* pWeatherData) {
		m_pWeatherData = pWeatherData;
		m_pWeatherData->registerObserver(this);
	}
private:
	WeatherData* m_pWeatherData;
};


int main() {
	WeatherData* pwd = new WeatherData("22C", "65%");
	PCDisplay* pPCDisplay = new PCDisplay(pwd);
	MobileDisplay* pMobile = new MobileDisplay(pwd);
	pwd->setData("38C", "55%");

	pwd->removeObserver(pMobile);
	pwd->setData("23C", "23%");
	system("pause");
	return 0;
}