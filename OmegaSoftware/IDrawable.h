#pragma once
class IDrawable
{
public:
	IDrawable();
	virtual ~IDrawable();
	// Интерфейс для рисования
	virtual void Draw(CDC* pDC) = 0;
};

