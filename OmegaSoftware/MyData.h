#pragma once
#include "IDrawable.h"
#include <list>

class MyFigure;
class MyRelation;

using namespace std;

class MyData : IDrawable
{

public:
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

};

