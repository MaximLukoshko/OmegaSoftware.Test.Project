#pragma once
#include "MyFigure.h"
class MyTriangle :
	public MyFigure
{
public:
	MyTriangle();
	virtual ~MyTriangle();

	void Draw(CDC* pDC);
};

