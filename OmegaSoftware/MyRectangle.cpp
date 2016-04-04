#include "stdafx.h"
#include "MyRectangle.h"

MyRectangle::MyRectangle() :MyFigure()
{
	//rectangle = new CRect();
	classCode = MY_RECTANGLE;
}

MyRectangle::~MyRectangle()
{
}

// Прорисовка самой фигуры	
void MyRectangle::Draw(CDC* pDC){
	pDC->Rectangle(rectangle);
}
