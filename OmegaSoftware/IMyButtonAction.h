#pragma once
#include "IDrawable.h"

class COmegaSoftwareView;
class MyData;

class IMyButtonAction : public IDrawable
{
protected:
	// ��������� �� CView, �� ������� �������� ����� ������������
	CPoint ActionStartPoint;
	CPoint ActionStopPoint;
	int classCode;

public:
	IMyButtonAction();
	virtual ~IMyButtonAction();

	// ������ ���������� ������
	virtual IMyButtonAction* Execute(MyData* figureData) = 0;

	// ������� �������� �� �������� ����
	virtual void OnMouseMoveReaction(CPoint ActionStartPoint, CPoint ActionStopPoint);

	//��� ������ ��� ������������
	virtual int getClassCode();

	virtual void Serialize(CArchive& archive);
};

