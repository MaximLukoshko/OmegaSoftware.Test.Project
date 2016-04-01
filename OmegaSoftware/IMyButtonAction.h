#pragma once
class IMyButtonAction
{
protected:
	// ��������� �� CView, �� ������� �������� ����� ������������
	CView* view;

public:
	IMyButtonAction(CView* view);
	virtual ~IMyButtonAction();

	// ������ ���������� ������
	virtual void Execute() = 0;
	// ���������� ����� ������	
	virtual void Draw(CDC* pDC) = 0;
};

