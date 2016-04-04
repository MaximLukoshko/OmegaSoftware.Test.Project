#include "stdafx.h"
#include "MyEllipse.h"

MyEllipse::MyEllipse() :MyFigure()
{
	classCode = MY_ELLIPSE;
}

MyEllipse::MyEllipse(COmegaSoftwareView* v) :MyFigure(v)
{
	rectangle= new CRect();
}


MyEllipse::~MyEllipse()
{
}


// Прорисовка самой фигуры	
void MyEllipse::Draw(CDC* pDC){
	pDC->Ellipse(rectangle);
}
/*
void MyEllipse::OnMouseMoveReaction()
{
	MyFigure::OnMouseMoveReaction();
}
*/
/* 
void MyEllipse::Execute(MyData* figureData)
{
	MyFigure::Execute(figureData);
	view->setAction(new MyEllipse(view));
}
*/
/*
int MyEllipse::getClassCode()
{
	return MY_ELLIPSE;
}
*/