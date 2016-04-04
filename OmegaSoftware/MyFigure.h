#pragma once
#include "IMyButtonAction.h"
#include "OmegaSoftwareView.h"

class IMyButtonAction;
class COmegaSoftwareView;

class MyFigure : 
	public IMyButtonAction
{
	friend bool MyData::moveFigure(CPoint ActionStartPoint, CPoint ActionStopPoint);

protected:
	CRect rectangle;

public:
	MyFigure();
	virtual ~MyFigure();

	// Запуск обновления данных
	virtual IMyButtonAction* Execute(MyData* figureData);

	void OnMouseMoveReaction(CPoint StartPoint, CPoint StopPoint);

	//Получить координаты центра
	CPoint getCenterPoint();

	// Проверить, лежит ли точка внутри прямоугольника
	bool isInside(CPoint point);

	virtual void Serialize(CArchive& archive);
};

