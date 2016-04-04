#pragma once
#include "MyAction.h"
#include "OmegaSoftwareView.h"
#include "MyData.h"

class MyFigure;

class MyRelation :
	public MyAction
{
	friend bool MyData::addRelation(MyRelation*);
protected:
	MyFigure* figure_1;
	MyFigure* figure_2;

public:
	MyRelation();
	MyRelation(COmegaSoftwareView* v);
	~MyRelation();
	// Запуск обновления данных
	IMyButtonAction* Execute(MyData* figureData);
	// Прорисовка линии
	void Draw(CDC* pDC);
	friend bool MyData::addRelation(MyRelation* rel);
};

