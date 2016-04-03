#pragma once
#include "MyAction.h"

class COmegaSoftwareView;
class MyHand :
	public MyAction
{
public:
	MyHand();
	MyHand(COmegaSoftwareView*);
	~MyHand();
	// Запуск обновления данных
	void Execute();
	// Прорисовка линии
	void Draw(CDC* pDC);
	void OnMouseMoveReaction();
	int getClassCode();
};

