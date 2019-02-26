#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Light {
public:
	void on() {
		cout << "灯亮了" << endl;
	}
	void off() {
		cout << "灯灭了" << endl;
	}
};

//turn on the light
//turn off the light
//抽象出一个类，专门记录这个动作

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
protected:
	Command(){}
};

//具体的命令对象 就是用来开灯的
//持有一个Receiver的实例，让这个Receiver自己去处理自己的运行
class LightOnCommand : public Command {
	//突出一个特点 问题聚焦的是如何规划 “请求这个动作”
	//而这个动作的真正执行，是通过将真实设备组合进入这个ConcreteCommand里面的（LightOnCommand)
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

//增加一个空的命令状态
class NoCommand :public Command {
public:
	void execute() {

	}
	void undo() {

	}

};

//invoker可以出发任意的命令对象，invoker可以发任何命令
class SimpleRemoteControl {
public:
	void setCommand(Command* pCommand) {
		m_pCommand = pCommand;
		//增加Undo的能力
		m_pUndoCommand = new NoCommand;

	}
	//当前的命令对象 既可以关闭，也可以打开 进一步细化buttonPress
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
	//增加Undo撤销的能力
	Command* m_pUndoCommand;
};

//添加一个undo的命令
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


//宏命令
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
		cout << "声音设备打开了" << endl;
	}
	void off() {
		cout << "声音设备关闭了" << endl;
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

//能够批量执行命令的loader
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
	//首先将设备组合进入命令对象
	LightOnCommand* plo = new LightOnCommand(pl);
	//通过invoker触发 “请求”动作
	p->setCommand(plo);
	p->onButtonWasPushed();//按下开启
	p->undoButtonWasPushed();//实现Undo
	//加载关灯命令
	LightOffCommand *pLightOff = new LightOffCommand(pl);
	p->setCommand(pLightOff);
	p->offButtonWasPushed();
	p->undoButtonWasPushed();

	//宏命令的演示
	cout << "*****************" << endl;
	vector<Command*> myCommands;
	Sound* pSound = new Sound;
	SoundOnCommand* pSoundOn = new SoundOnCommand(pSound);
	myCommands.push_back(plo);
	myCommands.push_back(pSoundOn);
	MacroCommands *pMacroCommands = new MacroCommands(myCommands);
	//p->setCommand(pMacroCommands);  现在需要批量执行宏命令，新增一个remoteInvoker的宏命令执行方法
	SimpleRemoteControlLoader *pRemoteCommands = new SimpleRemoteControlLoader;
	pRemoteCommands->setCommand(pMacroCommands);
	pRemoteCommands->onCommandsStart();

	//p->buttonPressed();
	//灯亮了被invoker :Simpleremote隐藏了（封装了设备）
	//接下来 只要关注invoker，并且对invoker进行控制，就可以吧一系列“动作”记录下来
	
	
	
	
	
	system("pause");
	return 0;
}