#include "stdafx.h"
#include "MyRectangle.h"

MyRectangle::MyRectangle() :MyFigure()
{
	//rectangle = new CRect();
	classCode = MY_RECTANGLE;
}

MyRectangle::MyRectangle(COmegaSoftwareView* v) :MyFigure(v)
{
	rectangle = new CRect();
}


MyRectangle::~MyRectangle()
{
}

// ���������� ����� ������	
void MyRectangle::Draw(CDC* pDC){
	/*rectangle->SetRect(view->getMouseLeftButtonDOWN(), view->getMouseLeftButtonUP());*/
	pDC->Rectangle(rectangle);
}
/*
void MyRectangle::OnMouseMoveReaction()
{
	MyFigure::OnMouseMoveReaction();
}
*/
/*
void MyRectangle::Execute(MyData* figureData)
{
	MyFigure::Execute(figureData);
	view->setAction(new MyRectangle(view));
}
*/

/*
int MyRectangle::getClassCode()
{
	return MY_RECTANGLE;
}
*/