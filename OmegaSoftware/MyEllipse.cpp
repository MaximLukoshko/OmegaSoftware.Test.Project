#include "stdafx.h"
#include "MyEllipse.h"

MyEllipse::MyEllipse()
{
}

MyEllipse::MyEllipse(COmegaSoftwareView* v) :MyFigure(v)
{
	rectangle= new CRect();
}


MyEllipse::~MyEllipse()
{
}


// ���������� ����� ������	
void MyEllipse::Draw(CDC* pDC){
	rectangle->SetRect(view->getMouseLeftButtonDOWN(), view->getMouseLeftButtonUP());
	pDC->Ellipse(rectangle);
}