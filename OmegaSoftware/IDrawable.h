#pragma once
class IDrawable : public CObject
{
protected:
	//������������ ���� ��������� �������
	enum
	{
		//Actions
		MY_RELATION,
		MY_HAND,
		MY_TRIANGLE,

		//Figures
		MY_RECTANGLE,
		MY_ELLIPSE
	};

public:
	IDrawable();
	virtual ~IDrawable();

	// ��������� ��� ���������
	virtual void Draw(CDC* pDC) = 0;
};

