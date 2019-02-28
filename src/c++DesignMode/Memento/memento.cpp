#include <iostream>
#include <string>

using namespace std;
//
//class OriginalWord {
//public:
//	//setmsg方法的初衷：为了设置消息的内容
//	void setMsg(string msg) {
//		this->m_strWord = msg;
//	}
//
//	//撤销消息:msg究竟是什么？它应该是当前OrigianlWord的一个实例
//	//用这个实例里面的msg去设置目标OrgianlWord实例的msg
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
	//存档
	Memento* saveWords() {
		return new Memento(m_strWord);
	}

	//恢复存档
	void recycleWords(Memento *pMemento) {
		m_strWord = pMemento->getWords();
		cout << "存档恢复成功" << endl;
	}

	//输出文字
	void showWords() {
		cout << m_strWord << endl;
	}
private:
	string m_strWord;

};

//用来设置快照 获得快照
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
	//第一条消息
	cout << "第一个msg" << endl;
	pWordFst->showWords();

	Caretake *pCt = new Caretake;
	pCt->setMemento(pWordFst->saveWords());
	cout << "保存了当前Fst的快照" << endl;
	OriginalWord *pWordSec = new OriginalWord("2222");
	cout << "第二条msg" << endl;
	pWordSec->showWords();
	OriginalWord* pWordThd = new OriginalWord("333");
	cout << "第三个msg" << endl;
	pWordThd->showWords();
	cout << "aaaaaa" << endl;
	//当需要回溯到某一个状态的时候，需要问CareTake对象拿到的快照
	pWordFst->recycleWords(pCt->getMemento());
	pWordFst->showWords();
	system("pause");
	

	return 0;
}