#pragma once
#include "OmegaSoftwareView.h"

class COmegaSoftwareView;

class IMyButtonAction
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
	// ���������� ����� ������	
	virtual void Draw(CDC* pDC) = 0;
};

