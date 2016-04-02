#pragma once
#include "MyAction.h"
#include "OmegaSoftwareView.h"
#include "MyData.h"

class MyFigure;

class MyRelation :
	public MyAction
{
	friend bool MyData::addRelation(MyRelation*);
protected:
	MyFigure* figure_1;
	MyFigure* figure_2;

public:
	MyRelation();
	MyRelation(COmegaSoftwareView* v);
	~MyRelation();
	// ������ ���������� ������
	void Execute();
	// ���������� �����
	void Draw(CDC* pDC);
	void OnMouseMoveReaction();

	friend bool MyData::addRelation(MyRelation* rel);
};

