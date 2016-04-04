#pragma once
#include "IDrawable.h"
#include <list>

class MyFigure;
class MyRelation;
class COmegaSoftwareView;

using namespace std;

class MyData : public IDrawable
{
private:
	COmegaSoftwareView* view;
	MyFigure* getFigureByClassCode(int classCode);
public:
	void setView(COmegaSoftwareView* v);
	MyData();
	~MyData();
	
protected:
	list<MyFigure*>* figures;
	list<MyRelation*>* relation;
public:
	void Draw(CDC* pDC);
	// ���������� ������ � ������
	bool addFigure(MyFigure* figure);
	// ���������� ����� � ������
	bool addRelation(MyRelation* rel);
	//����������� ������
	bool moveFigure(CPoint ActionStartPoint, CPoint ActionStopPoint);

	virtual void Serialize(CArchive& archive);

};

