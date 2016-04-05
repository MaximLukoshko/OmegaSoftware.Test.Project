#pragma once
#include "IDrawable.h"
#include <list>

class MyFigure;
class MyAction;
class MyRelation;
class COmegaSoftwareView;

using namespace std;

class MyData : public IDrawable
{
protected:
	list<MyFigure*>* figures;
	list<MyRelation*>* relation;

public:

	MyFigure* getFigureByClassCode(int classCode);
	MyAction* getActionByClassCode(int classCode);

	MyData();
	~MyData();
	
	void Draw(CDC* pDC);

	// ���������� ������ � ������
	bool addFigure(MyFigure* figure);

	// ���������� ����� � ������
	bool addRelation(MyRelation* rel);

	//����������� ������
	bool moveFigure(CPoint ActionStartPoint, CPoint ActionStopPoint);

	virtual void Serialize(CArchive& archive);
};

