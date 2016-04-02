#pragma once
#include "IMyButtonAction.h"
#include "OmegaSoftwareView.h"
#include "atltypes.h"
class MyAction :
	public IMyButtonAction
{
public:
	MyAction();
	MyAction(COmegaSoftwareView* view);
	void OnMouseMoveReaction();
	virtual ~MyAction();
protected:
	// Позиция начала действия
	CPoint ActionStartPoint;
	// Позиция завершения действия
	CPoint ActionStopPoint;
};

