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
	// Добавление фигуры в список
	bool addFigure(MyFigure* figure);
	// Добавление связи в список
	bool addRelation(MyRelation* rel);
};

