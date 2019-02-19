#include <iostream>

using namespace std;

class Carmera {
public:
	void turnOn() {
		cout << "相机启动" << endl;
	}
	void turnOff() {
		cout << "相机关闭" << endl;
	}
};

class Light {
public:
	void turnOn() {
		cout << "照明灯开启" << endl;
	}
	void turnOff() {
		cout << "照明灯关闭" << endl;
	}
};

class Sensor {
public:
	void active() {
		cout << "传感器启动" << endl;

	}

	void deactive() {
		cout << "传感器关闭" << endl;
	}
};

class Alarm {
public:
	void active() {
		cout << "报警器启动" << endl;
	}
	void deactive() {
		cout << "报警器关闭" << endl;

	}
};

class SecuritFacade {
public:
	SecuritFacade() {
		m_pCarmera = new Carmera;
		m_pLight = new Light;
		m_pSensor = new Sensor;
		m_pAlarm = new Alarm;
	}
	void active() {
		m_pCarmera->turnOn();
		m_pLight->turnOn();
		m_pSensor->active();
		m_pAlarm->active();
	}

	void deactive() {
		m_pAlarm->deactive();
		m_pSensor->deactive();
		m_pLight->turnOff();
		m_pCarmera->turnOff();
	}
private:
	Carmera* m_pCarmera;
	Light* m_pLight;
	Sensor* m_pSensor;
	Alarm* m_pAlarm;
};


int main() {

	/*
	Carmera* pCarmera = new Carmera;
	Light* pLight = new Light;
	Sensor* pSensor = new Sensor;
	Alarm* pAlarm = new Alarm;

	cout << "启动系统" << endl;
	pCarmera->turnOn();
	pLight->turnOn();
	pSensor->active();
	pAlarm->active();


	cout << "关闭系统" << endl;
	pAlarm->deactive();
	pSensor->deactive();
	pLight->turnOff();
	pCarmera->turnOff();

	*/

	SecuritFacade facade;
	facade.active();
	facade.deactive();

	system("pause");
	return 0;
}