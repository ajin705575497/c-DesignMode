// Interpretor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//抽象的表达式对象以及Context对象
//用于保存计算的中间结果以及当前执行的操作符
class Context {
public:
	int m_value;
	char m_operator;
	Context() :m_value(0), m_operator('\0') {

	}
};

//表示所有表达式的抽象接口
class IExpression {
public:
	virtual void Eval(Context* p) = 0;
};

//拆分表达式的元素
class Operator :public IExpression {
public:
	Operator(char op) {
		this->m_op = op;
		
	}
	void Eval(Context* pContext) {
		//cout << "Eval" << m_op;
		pContext->m_operator = m_op;
	}
private:

	char m_op;
};

//拆分操作数
class Operand :public IExpression {
public:
	Operand(int num) {
		this->m_num = num;
	}
	void Eval(Context* pContext) {
		switch (pContext->m_operator) {
		case '\0':
			pContext->m_value = m_num;
			break;
		case '+':
			pContext->m_value += m_num;
			break;
		case '-':
			pContext->m_value -= m_num;
			break;
		default:
			break;
		}
	}

private:
	int m_num;
};

class Calculator {
public:
	int Calc(string expression) {
		Context* pContext = new Context;
		vector<IExpression*> tree;
		for (int i = 0; i < expression.size(); i++) {
			if ((expression[i] == '+') || (expression[i] == '-')) {
				tree.push_back(new Operator(expression[i]));
				printf("第%d次压入的符号是=%c\n", i, (expression[i]));
			}
			else {
				tree.push_back(new Operand((int)(expression[i] - 48)));
				printf("第%d次压入的数字是=%d\n", i, (int)(expression[i] - 48));
			}
		}
		for (vector<IExpression*>::iterator iter = tree.begin(); iter != tree.end(); iter++) {
			(*iter)->Eval(pContext);
			printf("value=%d,oper=%c\n", pContext->m_value, pContext->m_operator);
		}
		return pContext->m_value;
	}
};

int main()
{
	Calculator* pc = new Calculator;
	cout << "1+4-2=" << pc->Calc("1+4-2") << endl;
	system("pause");
	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
