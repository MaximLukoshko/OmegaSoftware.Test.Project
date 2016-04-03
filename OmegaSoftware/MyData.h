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
	// Добавление фигуры в список
	bool addFigure(MyFigure* figure);
	// Добавление связи в список
	bool addRelation(MyRelation* rel);
	//Перемещение фигуры
	bool moveFigure(CPoint ActionStartPoint, CPoint ActionStopPoint);

};

