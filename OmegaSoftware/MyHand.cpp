#include "stdafx.h"
#include "MyHand.h"


MyHand::MyHand()
{
}

MyHand::MyHand(COmegaSoftwareView* v) :MyAction(v)
{
}

MyHand::~MyHand()
{
}


// Запуск обновления данных
bool MyHand::Execute(MyData* figureData)
{
	/*COmegaSoftwareDoc* pDoc = view->GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;*/
	bool completed = /*pDoc->getFigureData()*/figureData->moveFigure(ActionStartPoint, ActionStopPoint);
	ActionStartPoint = ActionStopPoint = CPoint(-10,-10);
	return completed;
}

// Прорисовка линии
void MyHand::Draw(CDC* pDC)
{
	pDC->Rectangle(ActionStartPoint.x - 6, ActionStartPoint.y - 6, ActionStartPoint.x + 6, ActionStartPoint.y + 6);
	pDC->MoveTo(ActionStartPoint);
	pDC->LineTo(ActionStopPoint);
	pDC->Ellipse(ActionStopPoint.x - 3, ActionStopPoint.y - 3, ActionStopPoint.x + 3, ActionStopPoint.y + 3);
}
/*
void MyHand::OnMouseMoveReaction()
{
	MyAction::OnMouseMoveReaction();
}
*/

int MyHand::getClassCode()
{
	return MY_HAND;
}