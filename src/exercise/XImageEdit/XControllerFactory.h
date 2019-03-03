#pragma once
#include "IControllerFactory.h"

class XControllerFactory : public IControllerFactory
{
public:
	static XControllerFactory *Get() {
		static XControllerFactory f;
		return &f;
	}
	
	~XControllerFactory();
	virtual XModel *CreateM();
	virtual IView *CreateV();
	virtual IController* CreateC();

protected:
	XControllerFactory();
};

