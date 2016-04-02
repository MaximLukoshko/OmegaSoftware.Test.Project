#pragma once
#include "MyAction.h"
#include "OmegaSoftwareView.h"
#include "MyData.h"

class MyFigure;

class MyRelation :
	public MyAction
{
	friend void MyData::addRelation(MyRelation* rel);

protected:
	MyFigure* figure_1;
	MyFigure* figure_2;

public:
	MyRelation();
	MyRelation(COmegaSoftwareView* v);
	~MyRelation();
	// Запуск обновления данных
	void Execute();
	// Прорисовка линии
	void Draw(CDC* pDC);

	void OnMouseMoveReaction();
};

