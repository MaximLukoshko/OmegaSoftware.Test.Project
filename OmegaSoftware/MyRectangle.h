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
	// ������ ���������� ������
	void Execute();
	// ���������� ����� ������	
	void Draw(CDC* pDC);
};


