#include "stdafx.h"
#include "MyRelation.h"
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
		ActionStartPoint = ActionStopPoint = CPoint();
	}
}

// ��������� ��� ���������
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
