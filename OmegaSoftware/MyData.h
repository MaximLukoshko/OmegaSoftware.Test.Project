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
	void addFigure(MyFigure* figure);
	// ���������� ����� � ������
	void addRelation(MyRelation* rel);
};

