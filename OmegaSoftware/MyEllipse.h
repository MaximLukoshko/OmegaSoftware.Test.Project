#pragma once
#include "MyFigure.h"
#include "OmegaSoftwareView.h"

class MyEllipse :
	public MyFigure
{
public:
	MyEllipse();
	MyEllipse(COmegaSoftwareView* v);
	~MyEllipse();
	// Запуск обновления данных
	void Execute();
	// Прорисовка самой фигуры	
	void Draw(CDC* pDC);
};

