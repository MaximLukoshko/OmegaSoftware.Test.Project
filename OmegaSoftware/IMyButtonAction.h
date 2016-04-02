#pragma once
#include "IDrawable.h"

class COmegaSoftwareView;

class IMyButtonAction : public IDrawable
{
protected:
	// Указатель на CView, на котором действие будет отображаться
	COmegaSoftwareView* view;


public:
	IMyButtonAction();
	IMyButtonAction(COmegaSoftwareView* view);
	virtual ~IMyButtonAction();

	// Запуск обновления данных
	virtual void Execute() = 0;
	// Прорисовка самой фигуры	
	//virtual void Draw(CDC* pDC) = 0;
	// Реакция действия на движение мыши
	virtual void OnMouseMoveReaction() = 0;
};

