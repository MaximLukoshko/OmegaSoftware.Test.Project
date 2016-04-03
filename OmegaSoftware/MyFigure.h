#pragma once
#include "IMyButtonAction.h"
#include "OmegaSoftwareView.h"

class IMyButtonAction;
class COmegaSoftwareView;

class MyFigure : 
	public IMyButtonAction
{
	friend bool MyData::moveFigure(CPoint ActionStartPoint, CPoint ActionStopPoint);
public:
	MyFigure();
	MyFigure(COmegaSoftwareView* v);
	// Запуск обновления данных
	virtual void Execute();
	void OnMouseMoveReaction();
	virtual ~MyFigure();

protected:
	CRect* rectangle;
public:
	//Получить координаты центра
	CPoint getCenterPoint();
	// Проверить, лежит ли точка внутри прямоугольника
	bool isInside(CPoint point);
};

