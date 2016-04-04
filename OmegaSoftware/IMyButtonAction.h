#pragma once
#include "IDrawable.h"

class COmegaSoftwareView;
class MyData;

class IMyButtonAction : public IDrawable
{
protected:
	// ��������� �� CView, �� ������� �������� ����� ������������
	//COmegaSoftwareView* view;
	CPoint ActionStartPoint;
	CPoint ActionStopPoint;
	int classCode;

public:
	IMyButtonAction();
	IMyButtonAction(COmegaSoftwareView* view);
	virtual ~IMyButtonAction();

	// ������ ���������� ������
	virtual IMyButtonAction* Execute(MyData* figureData) = 0;
	// ������� �������� �� �������� ����
	virtual void OnMouseMoveReaction(CPoint ActionStartPoint, CPoint ActionStopPoint);
	virtual void Serialize(CArchive& archive);
	//��� ������ ��� ������������
	virtual int getClassCode();
};

