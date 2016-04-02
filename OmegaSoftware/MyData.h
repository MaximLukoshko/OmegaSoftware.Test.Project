#pragma once

class MyFigure;

class MyData
{
public:
	MyData();
	~MyData();
	
protected:
	/*list<list<MyFigure*> > figures;*/
public:
	CList<CList<MyFigure*> >* figures;
};

