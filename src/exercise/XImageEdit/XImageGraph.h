#pragma once
#include "IGraph.h"
class XModel;
class XImageGraph :
	public IGraph
{
public:
	virtual void Draw(XModel* m);
};

