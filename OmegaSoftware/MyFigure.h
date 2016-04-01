#pragma once
#include "IMyButtonAction.h"
class MyFigure :
	public IMyButtonAction
{
public:
	MyFigure();
	MyFigure(COmegaSoftwareView* v);
	virtual ~MyFigure();
protected:
	CRect* rectangle;
};

