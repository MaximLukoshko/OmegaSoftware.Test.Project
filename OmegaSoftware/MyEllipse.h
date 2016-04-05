#pragma once
#include "MyFigure.h"
#include "OmegaSoftwareView.h"

class MyEllipse :
	public MyFigure
{
public:
	MyEllipse();
	~MyEllipse();
	// Прорисовка самой фигуры	
	void Draw(CDC* pDC);
};

