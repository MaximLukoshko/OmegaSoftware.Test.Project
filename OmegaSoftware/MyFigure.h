#pragma once
#include "IMyButtonAction.h"
#include "OmegaSoftwareView.h"

class IMyButtonAction;
class COmegaSoftwareView;

class MyFigure : 
	public IMyButtonAction
{
public:
	MyFigure();
	MyFigure(COmegaSoftwareView* v);
	// Запуск обновления данных
	void Execute();
	virtual ~MyFigure();
protected:
	CRect* rectangle;
};

