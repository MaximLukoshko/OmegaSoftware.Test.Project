#pragma once
#include "MyAction.h"
#include "OmegaSoftwareView.h"

class MyRelation :
	public MyAction
{
public:
	MyRelation();
	MyRelation(COmegaSoftwareView* v);
	~MyRelation();
	// ������ ���������� ������
	void Execute();
	// ���������� �����
	void Draw(CDC* pDC);

	void OnMouseMoveReaction();
};

