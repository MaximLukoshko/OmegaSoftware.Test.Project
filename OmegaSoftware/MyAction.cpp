#include "stdafx.h"
#include "MyAction.h"
#include "IMyButtonAction.h"
#include "OmegaSoftwareView.h"


MyAction::MyAction()
/*: ActionStartPoint(0), ActionStopPoint(0)*/
{
}

MyAction::MyAction(COmegaSoftwareView* v):IMyButtonAction(v)
{
	/*ActionStartPoint = new CPoint();
	ActionStopPoint = new CPoint();*/
}

MyAction::~MyAction()
{
}

void MyAction::OnMouseMoveReaction()
{
	ActionStartPoint = view->getMouseLeftButtonDOWN();
	ActionStopPoint = view->getMouseLeftButtonUP();
}