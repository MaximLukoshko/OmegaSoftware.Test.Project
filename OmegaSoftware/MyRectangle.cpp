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

// ���������� ����� ������	
void MyRectangle::Draw(CDC* pDC){
	/*rectangle->SetRect(view->getMouseLeftButtonDOWN(), view->getMouseLeftButtonUP());*/
	pDC->Rectangle(rectangle);
}

void MyRectangle::OnMouseMoveReaction()
{
	MyFigure::OnMouseMoveReaction();
}

void MyRectangle::Execute()
{
	MyFigure::Execute();
	view->setAction(new MyRectangle(view));
}


int MyRectangle::getClassCode()
{
	return MY_RECTANGLE;
}