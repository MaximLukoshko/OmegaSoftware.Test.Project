#pragma once
class IDrawable : public CObject
{
protected:
	//Перечисление всех возможных классов
	enum
	{
		//Actions
		MY_RELATION,
		MY_HAND,

		//Figures
		MY_RECTANGLE,
		MY_ELLIPSE
	};
	/*
protected:
	MyFigure* getFigureByClassCode(int classCode);
	*/
public:
	IDrawable();
	virtual ~IDrawable();
	// Интерфейс для рисования
	virtual void Draw(CDC* pDC) = 0;
};

