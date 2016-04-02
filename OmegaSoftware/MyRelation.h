#pragma once
#include "MyAction.h"
#include "OmegaSoftwareView.h"

class MyRelation :
	public MyAction
{
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

