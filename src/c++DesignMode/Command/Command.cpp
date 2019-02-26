#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Light {
public:
	void on() {
		cout << "������" << endl;
	}
	void off() {
		cout << "������" << endl;
	}
};

//turn on the light
//turn off the light
//�����һ���࣬ר�ż�¼�������

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
protected:
	Command(){}
};

//������������ �����������Ƶ�
//����һ��Receiver��ʵ���������Receiver�Լ�ȥ�����Լ�������
class LightOnCommand : public Command {
	//ͻ��һ���ص� ����۽�������ι滮 ���������������
	//���������������ִ�У���ͨ������ʵ�豸��Ͻ������ConcreteCommand����ģ�LightOnCommand)
public:
	LightOnCommand(Light* pLight) :m_pLight(pLight) {

	}

	void execute() {
		m_pLight->on();
	}
	void undo() {
		m_pLight->off();
	}
private:
	Light* m_pLight;
};

//����һ���յ�����״̬
class NoCommand :public Command {
public:
	void execute() {

	}
	void undo() {

	}

};

//invoker���Գ���������������invoker���Է��κ�����
class SimpleRemoteControl {
public:
	void setCommand(Command* pCommand) {
		m_pCommand = pCommand;
		//����Undo������
		m_pUndoCommand = new NoCommand;

	}
	//��ǰ��������� �ȿ��Թرգ�Ҳ���Դ� ��һ��ϸ��buttonPress
	/*void buttonPressed() {
		m_pCommand->execute();
	}*/
	void onButtonWasPushed() {
		m_pCommand->execute();
		m_pUndoCommand = m_pCommand;
	}
	void offButtonWasPushed() {
		m_pCommand->execute();
		m_pUndoCommand = m_pCommand;
	}
	void undoButtonWasPushed(){
		m_pUndoCommand->undo();
	}
private:
	Command* m_pCommand;
	//����Undo����������
	Command* m_pUndoCommand;
};

//���һ��undo������
class LightOffCommand :public Command {
public:
	LightOffCommand(Light* pLight) :m_pLight(pLight) {

	}
	void execute() {
		m_pLight->off();
	}
	void undo() {
		m_pLight->on();
	}
private:
	Light *m_pLight;
};


//������
class MacroCommands :public Command {
public:
	MacroCommands(vector<Command*> commands) :m_Commands(commands) {

	}
	void execute() {
		for (vector<Command*>::iterator iter = m_Commands.begin();
			iter != m_Commands.end(); iter++) {
			(*iter)->execute();
		}
	}
	void undo() {
		for (vector<Command*>::iterator iter = m_Commands.begin();
			iter != m_Commands.end(); iter++) {
			(*iter)->undo();
		}
	}
private:
	vector<Command*> m_Commands;
};

class Sound {
public:
	void on() {
		cout << "�����豸����" << endl;
	}
	void off() {
		cout << "�����豸�ر���" << endl;
	}
};

class SoundOnCommand : public Command {
public:
	SoundOnCommand(Sound* pSound) :m_pSound(pSound) {

	}
	void execute() {
		m_pSound->on();
	}
	void undo() {
		m_pSound->off();
	}

private:
	Sound* m_pSound;
};

//�ܹ�����ִ�������loader
class SimpleRemoteControlLoader {
public:
	void setCommand(Command* pCommand) {
		m_pCommand = pCommand;
	}
	void onCommandsStart() {
		m_pCommand->execute();
	}
	
private:
	Command* m_pCommand;
};


int main() {
	SimpleRemoteControl* p = new SimpleRemoteControl;
	Light *pl = new Light;
	//���Ƚ��豸��Ͻ����������
	LightOnCommand* plo = new LightOnCommand(pl);
	//ͨ��invoker���� �����󡱶���
	p->setCommand(plo);
	p->onButtonWasPushed();//���¿���
	p->undoButtonWasPushed();//ʵ��Undo
	//���عص�����
	LightOffCommand *pLightOff = new LightOffCommand(pl);
	p->setCommand(pLightOff);
	p->offButtonWasPushed();
	p->undoButtonWasPushed();

	//���������ʾ
	cout << "*****************" << endl;
	vector<Command*> myCommands;
	Sound* pSound = new Sound;
	SoundOnCommand* pSoundOn = new SoundOnCommand(pSound);
	myCommands.push_back(plo);
	myCommands.push_back(pSoundOn);
	MacroCommands *pMacroCommands = new MacroCommands(myCommands);
	//p->setCommand(pMacroCommands);  ������Ҫ����ִ�к��������һ��remoteInvoker�ĺ�����ִ�з���
	SimpleRemoteControlLoader *pRemoteCommands = new SimpleRemoteControlLoader;
	pRemoteCommands->setCommand(pMacroCommands);
	pRemoteCommands->onCommandsStart();

	//p->buttonPressed();
	//�����˱�invoker :Simpleremote�����ˣ���װ���豸��
	//������ ֻҪ��עinvoker�����Ҷ�invoker���п��ƣ��Ϳ��԰�һϵ�С���������¼����
	
	
	
	
	
	system("pause");
	return 0;
}