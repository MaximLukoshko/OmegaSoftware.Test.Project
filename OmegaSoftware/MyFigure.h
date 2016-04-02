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
	virtual void Execute();
	void OnMouseMoveReaction();
	virtual ~MyFigure();

protected:
	CRect* rectangle;
public:
	//�������� ���������� ������
	CPoint getCenterPoint();
	// ���������, ����� �� ����� ������ ��������������
	bool isInside(CPoint point);
};

