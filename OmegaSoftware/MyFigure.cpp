#include "stdafx.h"
#include "MyFigure.h"
#include "OmegaSoftwareView.h"
#include "OmegaSoftwareDoc.h"

MyFigure::MyFigure()
{
}

MyFigure::MyFigure(COmegaSoftwareView* v) :IMyButtonAction(v)
{
	rectangle = new CRect(0, 0, 100, 100);
}

void MyFigure::Execute(){
	COmegaSoftwareDoc* pDoc = view->GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->getFigureData().addFigure(this);
};

MyFigure::~MyFigure()
{
}

void MyFigure::OnMouseMoveReaction()
{
	rectangle->SetRect(view->getMouseLeftButtonDOWN(), view->getMouseLeftButtonUP());
}
