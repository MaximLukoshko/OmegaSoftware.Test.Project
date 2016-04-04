#include "stdafx.h"
#include "MyEllipse.h"

MyEllipse::MyEllipse() :MyFigure()
{
	classCode = MY_ELLIPSE;
}

MyEllipse::~MyEllipse()
{
}


// Прорисовка самой фигуры	
void MyEllipse::Draw(CDC* pDC){
	pDC->Ellipse(rectangle);
}
