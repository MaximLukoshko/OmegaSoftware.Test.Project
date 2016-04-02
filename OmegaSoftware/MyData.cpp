#include "stdafx.h"
#include "MyData.h"
#include "MyFigure.h"
#include "MyRelation.h"


MyData::MyData()
{
	figures = new list<MyFigure*>;
	relation = new list<MyRelation*>;
}


MyData::~MyData()
{
}


// Добавление фигуры в список
void MyData::addFigure(MyFigure* figure)
{
	figures->push_back(figure);
}

void MyData::Draw(CDC* pDC)
{
	for each (MyFigure* figure in *figures)
	{
		figure->Draw(pDC);
	}

	for each (MyRelation* rel in *relation)
	{
		rel->Draw(pDC);
	}
}

// Добавление связи в список
void MyData::addRelation(MyRelation* rel)
{
	relation->push_back(rel);
}
