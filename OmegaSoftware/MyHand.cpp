#include "stdafx.h"
#include "MyHand.h"


MyHand::MyHand()
{
	classCode = MY_HAND;
}

MyHand::~MyHand()
{
}


// Запуск обновления данных
IMyButtonAction* MyHand::Execute(MyData* figureData)
{
	bool completed = figureData->moveFigure(ActionStartPoint, ActionStopPoint);
	ActionStartPoint = ActionStopPoint = CPoint(-10,-10);
	return this;
}

// Прорисовка линии
void MyHand::Draw(CDC* pDC)
{
	pDC->Rectangle(ActionStartPoint.x - 6, ActionStartPoint.y - 6, ActionStartPoint.x + 6, ActionStartPoint.y + 6);
	pDC->MoveTo(ActionStartPoint);
	pDC->LineTo(ActionStopPoint);
	pDC->Ellipse(ActionStopPoint.x - 3, ActionStopPoint.y - 3, ActionStopPoint.x + 3, ActionStopPoint.y + 3);
}