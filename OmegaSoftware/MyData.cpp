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
	delete figures;
	delete relation;
}


// Добавление фигуры в список
bool MyData::addFigure(MyFigure* figure)
{
	figures->push_back(figure);
	return true;
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
bool MyData::addRelation(MyRelation* rel)
{
	rel->figure_1 = NULL;
	rel->figure_2 = NULL;
	for each (MyFigure* figure in *figures)
	{
		if (!rel->figure_1 && figure->isInside(rel->ActionStartPoint))
		{
			rel->figure_1 = figure;
		}

		if (!rel->figure_2 && figure->isInside(rel->ActionStopPoint))
		{
			rel->figure_2 = figure;
		}
		if (rel->figure_1 && rel->figure_2)
		{
			break;
		}
	}
	for each (MyRelation* relat in *relation)
	{
		if (relat->figure_1 == rel->figure_1 && relat->figure_2 == rel->figure_2)
		{
			return false;
		}
	}

	if (rel->figure_1 && rel->figure_2)
	{
		rel->ActionStartPoint = rel->figure_1->getCenterPoint();
		rel->ActionStopPoint = rel->figure_2->getCenterPoint();
		relation->push_back(rel);
		return true;
	}
}
