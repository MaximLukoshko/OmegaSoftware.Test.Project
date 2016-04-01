#pragma once
#include "OmegaSoftwareView.h"

class COmegaSoftwareView;

class IMyButtonAction
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
	virtual void Draw(CDC* pDC) = 0;
};

