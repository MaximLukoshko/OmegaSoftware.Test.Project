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
	//void OnMouseMoveReaction(CPoint StartPoint, CPoint StopPoint);
	virtual void Serialize(CArchive& archive);
	virtual ~MyAction();
	/*
protected:
	// ������� ������ ��������
	CPoint ActionStartPoint;
	// ������� ���������� ��������
	CPoint ActionStopPoint;
	*/
};

