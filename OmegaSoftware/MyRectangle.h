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
	// ���������� ����� ������	
	void Draw(CDC* pDC);
};


