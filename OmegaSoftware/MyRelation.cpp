#include "stdafx.h"
#include "MyRelation.h"
#include "MyFigure.h"
#include "MyAction.h"
#include "OmegaSoftwareView.h"

MyRelation::MyRelation()
{
	figure_1 = NULL;
	figure_2 = NULL;
	classCode = MY_RELATION;
}

MyRelation::~MyRelation()
{
}

IMyButtonAction* MyRelation::Execute(MyData* figureData)
{

	bool completed = figureData->addRelation(this);
	if (completed)
	{
		return new MyRelation();
	}
	else
	{
		figure_1 = figure_2 = NULL;
		ActionStartPoint = ActionStopPoint = CPoint();
		return this;
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