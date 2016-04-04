#include "stdafx.h"
#include "MyRelation.h"
#include "MyFigure.h"
#include "MyAction.h"
#include "OmegaSoftwareView.h"

MyRelation::MyRelation()
{
	classCode = MY_RELATION;
}

MyRelation::MyRelation(COmegaSoftwareView* v) : MyAction(v)
{
	figure_1 = NULL;
	figure_2 = NULL;
}

MyRelation::~MyRelation()
{
}

bool MyRelation::Execute(MyData* figureData)
{
	/*COmegaSoftwareDoc* pDoc = view->GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;*/
	bool completed =/* pDoc->getFigureData()*/figureData->addRelation(this);
	if (completed)
	{
		//view->setAction(new MyRelation(view));
		return true;
	}
	else
	{
		figure_1 = figure_2 = NULL;
		ActionStartPoint = ActionStopPoint = CPoint();
		return false;
	}
}

// Интерфейс для рисования
void MyRelation::Draw(CDC* pDC)
{
	if (figure_1 && figure_2)
	{
		ActionStartPoint = figure_1->getCenterPoint();
		ActionStopPoint = figure_2->getCenterPoint();
	}
	pDC->MoveTo(ActionStartPoint);
	pDC->LineTo(ActionStopPoint);
}
/*
void MyRelation::OnMouseMoveReaction(CPoint StartPoint, CPoint StopPoint)
{
	MyAction::OnMouseMoveReaction();
}
*/

int MyRelation::getClassCode()
{
	return MY_RELATION;
}