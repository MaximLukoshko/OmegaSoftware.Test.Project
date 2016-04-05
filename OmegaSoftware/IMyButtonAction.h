#pragma once
#include "IDrawable.h"

class COmegaSoftwareView;
class MyData;

class IMyButtonAction : public IDrawable
{
protected:
	// Указатель на CView, на котором действие будет отображаться
	CPoint ActionStartPoint;
	CPoint ActionStopPoint;
	int classCode;

public:
	IMyButtonAction();
	virtual ~IMyButtonAction();

	// Запуск обновления данных
	virtual IMyButtonAction* Execute(MyData* figureData) = 0;

	// Реакция действия на движение мыши
	virtual void OnMouseMoveReaction(CPoint ActionStartPoint, CPoint ActionStopPoint);

	//Код класса для сериализации
	virtual int getClassCode();

	virtual void Serialize(CArchive& archive);
};

