#include <iostream>
#include <Windows.h>

using namespace std;

class CView {
public:
	virtual void Draw(void){}
};

//����װ����
class CDecorate : public CView {
public:
	CDecorate(CView* pView):m_pView(pView){}
	virtual void Draw(void) {
		m_pView->Draw();
	}
private:
	CView *m_pView;
};

class CScrollBars :public CDecorate {
public:
	CScrollBars(CView* pView):CDecorate(pView){}
protected:
	//���ƹ�����
	void DrawScrollBars() {
		cout << ">�����˹�����" << endl;
	}
public:
	virtual void Draw() {
		CDecorate::Draw();
		DrawScrollBars();

	}
};


class CBorder :public CDecorate {
public:
	CBorder(CView* pView) :CDecorate(pView) {}
protected:
	//���ƹ�����
	void DrawBorder() {
		cout << ">�����˱߿�" << endl;
	}
public:
	virtual void Draw() {
		CDecorate::Draw();
		DrawBorder();

	}
};

//context ��Ҫ�ı�װ�ζ���
class CTextView :public CView {
public:
	CTextView(char*s) {
		SetWindowText(s);
	}
protected:
	virtual void DrawTextView() {
		cout << ">������һ���ı���ͼ���ı�������Ϊ:" << m_Text << endl;
	}
protected:
	char m_Text[MAX_PATH];
public:
	virtual void Draw() {
		CView::Draw();
		DrawTextView();
	}
	void SetWindowText(char* s) {
		strcpy_s(m_Text, _countof(m_Text), s);
	}
	char* GetWindowText() {
		return m_Text;
	}
};

class CWindows {
public:
	CWindows(){
		ZeroMemory(m_arrWindow, sizeof(CView*) * 10);
	}
	void Draw() {
		for (int i = 0; i < 10; i++) {
			if (m_arrWindow[i] != NULL)
				m_arrWindow[i]->Draw();
		}
	}
	void AddControl(CView* pView) {
		for (int i = 0; i < 10; i++) {
			if (m_arrWindow[i] == NULL) {
				m_arrWindow[i] = pView;
				break;
			}
		}
	}

	void RemoveControl(CView* pView) {
		for (int i = 0; i < 10; i++) {
			if (m_arrWindow[i] == pView) {
				m_arrWindow[i] = NULL;
				break;
			}
		}
	}
protected:
	CView* m_arrWindow[10];

};

int main() {
	//����һ�����ڶ���

	CWindows windowsObj;
	//����һ����ͨ���ı���ͼ
	CTextView textView((char*)("aaaa"));

	windowsObj.AddControl(&textView);
	windowsObj.Draw();
	cout << "****************" << endl;
	windowsObj.RemoveControl(&textView);

	CScrollBars* pScroll = new CScrollBars(&textView);
	windowsObj.AddControl(pScroll);
	windowsObj.Draw();
	cout << "*************" << endl;
	windowsObj.RemoveControl(pScroll);
	CBorder* pBorder = new CBorder(&textView);
	windowsObj.AddControl(pBorder);
	windowsObj.Draw();
	system("pause");
	return 0;
}