#pragma once
#include "MyFigure.h"
#include "OmegaSoftwareView.h"

class MyRectangle :
	public MyFigure
{
public:
	MyRectangle();
	MyRectangle(COmegaSoftwareView* v);
	~MyRectangle();
	// Запуск обновления данных
	void Execute();
	// Прорисовка самой фигуры	
	void Draw(CDC* pDC);
};


