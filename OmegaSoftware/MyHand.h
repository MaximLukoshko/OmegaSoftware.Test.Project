#pragma once
#include "MyAction.h"

class COmegaSoftwareView;
class MyData;

class MyHand :
	public MyAction
{
public:
	MyHand();
	MyHand(COmegaSoftwareView*);
	~MyHand();
	// Запуск обновления данных
	IMyButtonAction* Execute(MyData* figureData);
	// Прорисовка линии
	void Draw(CDC* pDC);
	//void OnMouseMoveReaction(CPoint StartPoint, CPoint StopPoint);
	int getClassCode();
};

