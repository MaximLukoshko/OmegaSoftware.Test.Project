#include "stdafx.h"
#include "MyRelation.h"
#include "MyFigure.h"
#include "MyAction.h"
#include "OmegaSoftwareView.h"

MyRelation::MyRelation()
{
}

MyRelation::MyRelation(COmegaSoftwareView* v) : MyAction(v)
{
	figure_1 = NULL;
	figure_2 = NULL;
}

MyRelation::~MyRelation()
{
}

void MyRelation::Execute()
{
	COmegaSoftwareDoc* pDoc = view->GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	bool completed = pDoc->getFigureData()->addRelation(this);
	if (completed)
	{
		view->setAction(new MyRelation(view));
	}
	else
	{
		figure_1 = figure_2 = NULL;
		ActionStartPoint = ActionStopPoint = CPoint();
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

void MyRelation::OnMouseMoveReaction()
{
	MyAction::OnMouseMoveReaction();
}