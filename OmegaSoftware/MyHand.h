#pragma once
#include "MyAction.h"

class COmegaSoftwareView;
class MyHand :
	public MyAction
{
public:
	MyHand();
	MyHand(COmegaSoftwareView*);
	~MyHand();
	// ������ ���������� ������
	void Execute();
	// ���������� �����
	void Draw(CDC* pDC);
	void OnMouseMoveReaction();
	int getClassCode();
};

