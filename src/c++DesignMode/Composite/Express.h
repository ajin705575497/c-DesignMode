#pragma once

#include "ExpressNode.h"
#include <iostream>

using namespace std;

class Express {
public:
	Express(int);
	Express(char, const Express);//UnaryNode(char,int) Express('+',t,12)
	Express(char, const Express, const Express);//BinararyNode(char,int,int) ('+',3,4);
	Express(const Express&);
	Express& operator=(const Express&);
	~Express();
	friend ostream&operator<<(ostream& os, const Express&e) {
		os << *(e.p);
		return os;
	}
	int eval() const;
private:
	class ExpressNode* p;//具体的功能由这个类实现，这个类派生了各种各样的表达式
};