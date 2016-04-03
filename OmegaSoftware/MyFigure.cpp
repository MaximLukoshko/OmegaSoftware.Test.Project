#include "stdafx.h"
#include "MyFigure.h"
#include "OmegaSoftwareView.h"
#include "OmegaSoftwareDoc.h"

MyFigure::MyFigure()
{
}

MyFigure::MyFigure(COmegaSoftwareView* v) :IMyButtonAction(v)
{
	rectangle = new CRect(0, 0, 100, 100);
}

void MyFigure::Execute(){
	COmegaSoftwareDoc* pDoc = view->GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->getFigureData()->addFigure(this);
};

MyFigure::~MyFigure()
{
	delete rectangle;
}

void MyFigure::OnMouseMoveReaction()
{
	rectangle->SetRect(min(view->getMouseLeftButtonDOWN().x, view->getMouseLeftButtonUP().x),
		min(view->getMouseLeftButtonDOWN().y, view->getMouseLeftButtonUP().y),
		max(view->getMouseLeftButtonDOWN().x, view->getMouseLeftButtonUP().x),
		max(view->getMouseLeftButtonDOWN().y, view->getMouseLeftButtonUP().y));
}


CPoint MyFigure::getCenterPoint()
{
	return rectangle->CenterPoint();
}

// Проверить, лежит ли точка внутри прямоугольника
bool MyFigure::isInside(CPoint point)
{
	return rectangle->PtInRect(point);
}

void MyFigure::Serialize(CArchive& archive)
{
	IMyButtonAction::Serialize(archive);
	if (archive.IsStoring()){
		archive << rectangle->left << rectangle->top << rectangle->right << rectangle->bottom;
	}
	else
	{
		archive >> rectangle->left >> rectangle->top >> rectangle->right >> rectangle->bottom;
	}
}