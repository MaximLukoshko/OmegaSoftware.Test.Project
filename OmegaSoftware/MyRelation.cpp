#include "stdafx.h"
#include "MyRelation.h"
#include "MyAction.h"
#include "OmegaSoftwareView.h"

MyRelation::MyRelation()
{
}

MyRelation::MyRelation(COmegaSoftwareView* v) : MyAction(v)
{

}

MyRelation::~MyRelation()
{
}

void MyRelation::Execute()
{

}

void MyRelation::Draw(CDC* pDC)
{
	pDC->MoveTo(view->getMouseLeftButtonDOWN());
	pDC->LineTo(view->getMouseLeftButtonUP());
}