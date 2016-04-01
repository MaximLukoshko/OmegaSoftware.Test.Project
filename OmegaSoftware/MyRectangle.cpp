#include "stdafx.h"
#include "MyRectangle.h"

MyRectangle::MyRectangle()
{
}

MyRectangle::MyRectangle(COmegaSoftwareView* v) :MyFigure(v)
{
	rectangle = new CRect();
}


MyRectangle::~MyRectangle()
{
}

// Прорисовка самой фигуры	
void MyRectangle::Draw(CDC* pDC){
	rectangle->SetRect(view->getMouseLeftButtonDOWN(), view->getMouseLeftButtonUP());
	pDC->Rectangle(rectangle);
}