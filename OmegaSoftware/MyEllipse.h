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
	// ������ ���������� ������
	void Execute();
	// ���������� ����� ������	
	void Draw(CDC* pDC);
};

