#pragma once
#include "MyAction.h"

class COmegaSoftwareView;
class MyData;

class MyHand :
	public MyAction
{
public:
	MyHand();
	~MyHand();

	// ������ ���������� ������
	IMyButtonAction* Execute(MyData* figureData);

	// ���������� �����
	void Draw(CDC* pDC);
};

