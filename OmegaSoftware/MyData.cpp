#include "stdafx.h"
#include "MyData.h"
#include "MyFigure.h"
#include "MyRelation.h"
#include "MyRectangle.h"
#include "MyEllipse.h"
#include "MyHand.h"


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
	figures->push_front(figure);
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
		if ((rel->figure_1==NULL) && figure->isInside(rel->ActionStartPoint))
		{
			rel->figure_1 = figure;
		}

		if ((rel->figure_2 == NULL) && figure->isInside(rel->ActionStopPoint))
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
		if ((relat->figure_1 == rel->figure_1) && (relat->figure_2 == rel->figure_2))
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
	else
	{
		return false;
	}
}


bool MyData::moveFigure(CPoint ActionStartPoint, CPoint ActionStopPoint)
{
	MyFigure* movingFigure = NULL;
	for each (MyFigure* figure in *figures)
	{
		if (figure->isInside(ActionStartPoint))
		{
			movingFigure = figure;
			break;
		}
	}

	if (movingFigure)
	{
		movingFigure->rectangle->MoveToXY(movingFigure->rectangle->left - ActionStartPoint.x + ActionStopPoint.x, 
			movingFigure->rectangle->top - ActionStartPoint.y + ActionStopPoint.y);
		return true;
	}
	else
	{
		return false;
	}
}

void MyData::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << static_cast<int>(figures->size());
		for each (MyFigure* figure in *figures)
		{
			figure->Serialize(archive);
		}
		archive << static_cast<int>(relation->size());
		for each (MyRelation* rel in *relation)
		{
			rel->Serialize(archive);
		}
	}
	else
	{
		if (figures)
		{
			delete figures;
		}
		if (relation)
		{
			delete relation;
		}

		figures = new list<MyFigure*>();
		relation = new list<MyRelation*>();
		int numFigures;
		archive >> numFigures;
		while (numFigures > 0)
		{
			int classCode;
			archive >> classCode;
			MyFigure* fig = getFigureByClassCode(classCode);
			figures->push_back(fig);
			numFigures--;
		}
	}
}

MyFigure* MyData::getFigureByClassCode(int classCode)
{
	switch (classCode)
	{
	case MY_RECTANGLE:
		return new MyRectangle();
	case MY_ELLIPSE:
		return new MyEllipse();
	default:
		return NULL;
	}
}

MyAction* MyData::getActionByClassCode(int classCode)
{
	switch (classCode)
	{
	case MY_RELATION:
		return new MyRelation();
	case MY_HAND:
		return new MyHand();
	default:
		return NULL;
	}
}
