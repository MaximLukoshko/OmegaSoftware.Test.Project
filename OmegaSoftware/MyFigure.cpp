#include "stdafx.h"
#include "MyFigure.h"
#include "OmegaSoftwareView.h"
#include "OmegaSoftwareDoc.h"

MyFigure::MyFigure()
{
	rectangle = new CRect();
}

MyFigure::MyFigure(COmegaSoftwareView* v) :IMyButtonAction(v)
{
	rectangle = new CRect(0, 0, 100, 100);
}

IMyButtonAction* MyFigure::Execute(MyData* figureData){
	if (figureData->addFigure(this))
	{
		return figureData->getFigureByClassCode(this->getClassCode());
	}
	return false;
};

MyFigure::~MyFigure()
{
	delete rectangle;
}

void MyFigure::OnMouseMoveReaction(CPoint StartPoint, CPoint StopPoint)
{
	IMyButtonAction::OnMouseMoveReaction(StartPoint, StopPoint);
	rectangle->SetRect(min(ActionStartPoint.x, ActionStopPoint.x),
		min(ActionStartPoint.y, ActionStopPoint.y),
		max(ActionStartPoint.x, ActionStopPoint.x),
		max(ActionStartPoint.y, ActionStopPoint.y));
}


CPoint MyFigure::getCenterPoint()
{
	return rectangle->CenterPoint();
}

// Проверить, лежит ли точка внутри прямоугольника
bool MyFigure::isInside(CPoint point)
{
	return rectangle->PtInRect(point);
}

void MyFigure::Serialize(CArchive& archive)
{
	IMyButtonAction::Serialize(archive);
	if (archive.IsStoring()){
		archive << rectangle->left << rectangle->top << rectangle->right << rectangle->bottom;
	}
	else
	{
		archive >> rectangle->left >> rectangle->top >> rectangle->right >> rectangle->bottom;
	}
}