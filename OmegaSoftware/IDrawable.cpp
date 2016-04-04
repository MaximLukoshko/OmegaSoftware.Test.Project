#include "stdafx.h"
#include "IDrawable.h"
#include "MyRectangle.h"

IDrawable::IDrawable()
{
}


IDrawable::~IDrawable()
{
}

/*
MyFigure* IDrawable::getFigureByClassCode(int classCode)
{
	switch (classCode)
	{
	case MY_RECTANGLE:
		return new MyRectangle();
	case MY_ELLIPSE:
		return new MyEllipse();
	default:
		return NULL;
		break;
	}
}
*/