#pragma once
class IMyButtonAction
{
protected:
	// Указатель на CView, на котором действие будет отображаться
	CView* view;

public:
	IMyButtonAction(CView* view);
	virtual ~IMyButtonAction();

	// Запуск обновления данных
	virtual void Execute() = 0;
	// Прорисовка самой фигуры	
	virtual void Draw(CDC* pDC) = 0;
};

