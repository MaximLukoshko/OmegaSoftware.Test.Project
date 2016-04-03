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

void MyAction::Serialize(CArchive& archive)
{
	IMyButtonAction::Serialize(archive);
	archive << ActionStartPoint.x << ActionStartPoint.y << ActionStopPoint.x << ActionStopPoint.y;
}