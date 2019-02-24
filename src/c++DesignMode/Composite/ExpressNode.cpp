#include "ExpressNode.h"

ExpressNode::~ExpressNode() {

}

int ExpressNode::getUse() const {
	return use;
}

void ExpressNode::setUse(int usel) {
	use = usel;
}