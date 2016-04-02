#include "stdafx.h"
#include "MyRelation.h"
#include "MyAction.h"
#include "OmegaSoftwareView.h"

MyRelation::MyRelation()
{
}

MyRelation::MyRelation(COmegaSoftwareView* v) : MyAction(v)
{

}

MyRelation::~MyRelation()
{
}

void MyRelation::Execute()
{

}

void MyRelation::Draw(CDC* pDC)
{
	pDC->MoveTo(ActionStartPoint);
	pDC->LineTo(ActionStopPoint);
}

void MyRelation::OnMouseMoveReaction()
{
	ActionStartPoint = view->getMouseLeftButtonDOWN();
	ActionStopPoint = view->getMouseLeftButtonUP();
}