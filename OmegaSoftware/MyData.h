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
	/*list<list<MyFigure*> > figures;*/
public:
	list<MyFigure*>* figures;
	list<MyRelation*>* relation;
	void Draw(CDC* pDC);
	// ���������� ������ � ������
	bool addFigure(MyFigure* figure);
	// ���������� ����� � ������
	bool addRelation(MyRelation* rel);
};

