#pragma once
#include "MyFigure.h"
#include "OmegaSoftwareView.h"

class MyRectangle :
	public MyFigure
{
public:
	MyRectangle();
	~MyRectangle();
	// ���������� ����� ������	
	void Draw(CDC* pDC);
};


