#pragma once
#include "IMyButtonAction.h"
#include "OmegaSoftwareView.h"

class IMyButtonAction;
class COmegaSoftwareView;

class MyFigure : 
	public IMyButtonAction
{
public:
	MyFigure();
	MyFigure(COmegaSoftwareView* v);
	// ������ ���������� ������
	void Execute();
	void OnMouseMoveReaction();
	virtual ~MyFigure();

protected:
	CRect* rectangle;
};

