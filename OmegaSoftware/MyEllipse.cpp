#include "stdafx.h"
#include "MyEllipse.h"

MyEllipse::MyEllipse() :MyFigure()
{
	classCode = MY_ELLIPSE;
}

MyEllipse::~MyEllipse()
{
}


// ���������� ����� ������	
void MyEllipse::Draw(CDC* pDC){
	pDC->Ellipse(rectangle);
}
