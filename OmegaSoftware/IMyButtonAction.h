#pragma once
#include "IDrawable.h"

class COmegaSoftwareView;

class IMyButtonAction : public IDrawable
{
protected:
	// ��������� �� CView, �� ������� �������� ����� ������������
	COmegaSoftwareView* view;


public:
	IMyButtonAction();
	IMyButtonAction(COmegaSoftwareView* view);
	virtual ~IMyButtonAction();

	// ������ ���������� ������
	virtual void Execute() = 0;
	// ������� �������� �� �������� ����
	virtual void OnMouseMoveReaction() = 0;
	virtual void Serialize(CArchive& archive);
	//��� ������ ��� ������������
	virtual int getClassCode() = 0;
};

