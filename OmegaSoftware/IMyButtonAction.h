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
	// Реакция действия на движение мыши
	virtual void OnMouseMoveReaction() = 0;
	virtual void Serialize(CArchive& archive);
	//Код класса для сериализации
	virtual int getClassCode() = 0;
};

