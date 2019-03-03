#include "XControllerFactory.h"
#include "XModel.h"
#include "IController.h"
#include "XEditView.h"
#include "XPenGraph.h"
#include "XErasGraph.h"
#include "XRectGraph.h"
#include "XImageGraph.h"
XControllerFactory::XControllerFactory()
{
}


XControllerFactory::~XControllerFactory()
{
}


XModel *XControllerFactory::CreateM()
{
	return new XModel();
}
IView *XControllerFactory::CreateV()
{
	XEditView::Get()->RegView<XPenGraph>(XPEN);
	XEditView::Get()->RegView<XErasGraph>(XERASER);
	XEditView::Get()->RegView<XRectGraph>(XRECT);
	XEditView::Get()->RegView<XImageGraph>(XIMAGE);
	return XEditView::Get();
}
IController* XControllerFactory::CreateC()
{
	return new IController();
}