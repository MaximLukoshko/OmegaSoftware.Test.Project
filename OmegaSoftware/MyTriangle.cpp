#include "stdafx.h"
#include "MyTriangle.h"


MyTriangle::MyTriangle()
{
	classCode = MY_TRIANGLE;
}


MyTriangle::~MyTriangle()
{
}

void MyTriangle::Draw(CDC* pDC){
	pDC->MoveTo(rectangle.left, rectangle.bottom);
	pDC->LineTo(rectangle.right, rectangle.bottom);
	pDC->LineTo((rectangle.left + rectangle.right) / 2, rectangle.top);
	pDC->LineTo(rectangle.left, rectangle.bottom);
}
