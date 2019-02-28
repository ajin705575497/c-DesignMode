#include <iostream>
#include <string>

using namespace std;
//
//class OriginalWord {
//public:
//	//setmsg�����ĳ��ԣ�Ϊ��������Ϣ������
//	void setMsg(string msg) {
//		this->m_strWord = msg;
//	}
//
//	//������Ϣ:msg������ʲô����Ӧ���ǵ�ǰOrigianlWord��һ��ʵ��
//	//�����ʵ�������msgȥ����Ŀ��OrgianlWordʵ����msg
//	void  retreatMsg(string msg) {
//		this->m_strWord = msg;
//	}
//private:
//	string m_strWord;
//};

class OriginalWord;
class Memento {
public:
	Memento(string strWord):m_strWord(strWord){}

private:
	friend class OriginalWord;
	string getWords() {
		return m_strWord;
	}
	string m_strWord;
};

class OriginalWord {
public:
	OriginalWord(string myWord) :m_strWord(myWord) {

	}
	//�浵
	Memento* saveWords() {
		return new Memento(m_strWord);
	}

	//�ָ��浵
	void recycleWords(Memento *pMemento) {
		m_strWord = pMemento->getWords();
		cout << "�浵�ָ��ɹ�" << endl;
	}

	//�������
	void showWords() {
		cout << m_strWord << endl;
	}
private:
	string m_strWord;

};

//�������ÿ��� ��ÿ���
class Caretake {
public:
	void setMemento(Memento* pMem)  {
		m_pMemento = pMem;

	}

	Memento* getMemento() {
		return m_pMemento;
	}
private:
	Memento* m_pMemento;
};

int main() {

	OriginalWord *pWordFst = new OriginalWord("1111");
	//��һ����Ϣ
	cout << "��һ��msg" << endl;
	pWordFst->showWords();

	Caretake *pCt = new Caretake;
	pCt->setMemento(pWordFst->saveWords());
	cout << "�����˵�ǰFst�Ŀ���" << endl;
	OriginalWord *pWordSec = new OriginalWord("2222");
	cout << "�ڶ���msg" << endl;
	pWordSec->showWords();
	OriginalWord* pWordThd = new OriginalWord("333");
	cout << "������msg" << endl;
	pWordThd->showWords();
	cout << "aaaaaa" << endl;
	//����Ҫ���ݵ�ĳһ��״̬��ʱ����Ҫ��CareTake�����õ��Ŀ���
	pWordFst->recycleWords(pCt->getMemento());
	pWordFst->showWords();
	system("pause");
	

	return 0;
}