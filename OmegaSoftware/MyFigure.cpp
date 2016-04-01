#include "stdafx.h"
#include "MyFigure.h"
#include "OmegaSoftwareView.h"

MyFigure::MyFigure()
{
}

MyFigure::MyFigure(COmegaSoftwareView* v) :IMyButtonAction(v)
{
	rectangle = new CRect(0, 0, 100, 100);
}

void MyFigure::Execute(){

};

MyFigure::~MyFigure()
{
}

