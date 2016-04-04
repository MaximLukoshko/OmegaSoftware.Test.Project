#pragma once
#include "IMyButtonAction.h"
#include "OmegaSoftwareView.h"

class IMyButtonAction;
class COmegaSoftwareView;

class MyFigure : 
	public IMyButtonAction
{
	friend bool MyData::moveFigure(CPoint ActionStartPoint, CPoint ActionStopPoint);

protected:
	CRect rectangle;

public:
	MyFigure();
	virtual ~MyFigure();

	// ������ ���������� ������
	virtual IMyButtonAction* Execute(MyData* figureData);

	void OnMouseMoveReaction(CPoint StartPoint, CPoint StopPoint);

	//�������� ���������� ������
	CPoint getCenterPoint();

	// ���������, ����� �� ����� ������ ��������������
	bool isInside(CPoint point);

	virtual void Serialize(CArchive& archive);
};

