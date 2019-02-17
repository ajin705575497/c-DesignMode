#include <iostream>

using namespace std;

class FrameApi {
public:
	virtual void draw() = 0;
protected:
	FrameApi() {}
};

class LayoutApi {
public:
	virtual void installFrame() = 0;
protected:
	LayoutApi() {}
};

//pc上的Frame
class ComputerFrame : public FrameApi {
public:
	ComputerFrame(int pins) :m_pins(pins) {

	}
	void draw() {
		cout << "pc Frame 分辨率是" << m_pins << endl;
	}
private:
	int m_pins;

};

class MobileFrame : public FrameApi {
public:
	MobileFrame(int pins) : m_pins(pins) {

	}
	void draw() {
		cout << "mobile Frame 分辨率是" << m_pins << endl;
	}
private:
	int m_pins;
};

//高分辨率的布局
class HighLayout : public LayoutApi {
public:
	HighLayout(int frameAdpaterPins) :m_FrameAdpaterPins(frameAdpaterPins) {

	}
	void installFrame() {
		cout << "现在是在pc环境下，我们使用的高分辨率布局" << m_FrameAdpaterPins << endl;

	}
private:
	int m_FrameAdpaterPins;
};

//低分辨率的布局
class LowLayout : public LayoutApi {
public:
	LowLayout(int frameAdpaterPins) :m_FrameAdpaterPins(frameAdpaterPins) {

	}
	void installFrame() {
		cout << "现在是在mobile环境下，我们使用的低分辨率布局" << m_FrameAdpaterPins << endl;

	}
private:
	int m_FrameAdpaterPins;
};

////创建产品的简单工厂
//class FrameFactory {
//public:
//	static FrameApi* createFrame(int type) {
//		if (type == 1)
//			return new ComputerFrame(1024);
//		else if (type == 2)
//			return new MobileFrame(800);
//
//		return nullptr;
//	}
//};
//
//class LayoutFactory {
//public:
//	static LayoutApi* createLayout(int type) {
//		if (type == 1)
//			return new HighLayout(1024);
//		else if (type == 2)
//			return new LowLayout(800);
//		return nullptr;
//	}
//};
//
//class GUIEngineer {
//public:
//	//frameType 是用来表述选择Frame控件的类型
//	//layoutType 是用来表述选择布局管理器的类型
//	void prepareDraw(int frameType, int LayoutType) {
//		m_pFrame = FrameFactory::createFrame(frameType);
//		m_pLayout = LayoutFactory::createLayout(LayoutType);
//		m_pFrame->draw();
//		m_pLayout->installFrame();
//	}
//private:
//	FrameApi* m_pFrame;
//	LayoutApi* m_pLayout;
//};

//抽象工厂用来定义产品簇
class AbstractFactory {
public:
	virtual FrameApi* createFrameApi() = 0;
	virtual LayoutApi* createLayoutApi() = 0;
protected:
	AbstractFactory() {}
};

class Schemal1 : public AbstractFactory {
public:
	FrameApi* createFrameApi() {
		return new ComputerFrame(1024);
	}
	LayoutApi* createLayoutApi() {
		return new HighLayout(1024);
	}
};

class Schemal2 : public AbstractFactory {
public :
	FrameApi* createFrameApi() {
		return new MobileFrame(800);
	}
	LayoutApi* createLayoutApi() {
		return new LowLayout(800);
	}
};

class AdvancedGuiEngineer {
public:
	void prepareMaterials(AbstractFactory* pSchema) {
		m_pFrame = pSchema->createFrameApi();
		m_pLayout = pSchema->createLayoutApi();
		m_pFrame->draw();
		m_pLayout->installFrame();
	}
private:
	FrameApi* m_pFrame;
	LayoutApi* m_pLayout;
};

int main(void) {

	//GUIEngineer* pEng = new GUIEngineer;
	//pEng->prepareDraw(1, 1);

	AdvancedGuiEngineer* pEng = new AdvancedGuiEngineer();
	pEng->prepareMaterials(new Schemal1());

	system("pause");
	return 0;
}