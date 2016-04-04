
// OmegaSoftwareView.cpp : ���������� ������ COmegaSoftwareView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "OmegaSoftware.h"
#endif

#include "OmegaSoftwareDoc.h"
#include "OmegaSoftwareView.h"

#include "MyRectangle.h"
#include "MyEllipse.h"
#include "MyRelation.h"
#include "MyHand.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COmegaSoftwareView

IMPLEMENT_DYNCREATE(COmegaSoftwareView, CView)

BEGIN_MESSAGE_MAP(COmegaSoftwareView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_RECTANGLE_BUTTON, &COmegaSoftwareView::OnRectangleButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_ELLIPSE_BUTTON, &COmegaSoftwareView::OnEllipseButton)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_RELATION_BUTTON, &COmegaSoftwareView::OnRelationButton)
	ON_COMMAND(ID_HAND_BUTTON, &COmegaSoftwareView::OnHandButton)

END_MESSAGE_MAP()

// ��������/����������� COmegaSoftwareView

COmegaSoftwareView::COmegaSoftwareView()
{
	
	action = NULL;
}

COmegaSoftwareView::~COmegaSoftwareView()
{
	if (action)
	{
		delete action;
	}
}

BOOL COmegaSoftwareView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

// ��������� COmegaSoftwareView

void COmegaSoftwareView::OnDraw(CDC* pDC)
{
	COmegaSoftwareDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (action){
		pDC->SelectStockObject(NULL_BRUSH);
		pDoc->getFigureData()->Draw(pDC);
		action->Draw(pDC);
	}
}


// ������ COmegaSoftwareView

BOOL COmegaSoftwareView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void COmegaSoftwareView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void COmegaSoftwareView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� COmegaSoftwareView

#ifdef _DEBUG
void COmegaSoftwareView::AssertValid() const
{
	CView::AssertValid();
}

void COmegaSoftwareView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COmegaSoftwareDoc* COmegaSoftwareView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COmegaSoftwareDoc)));
	return (COmegaSoftwareDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� COmegaSoftwareView


// ������� ���������� ������� ����
CPoint COmegaSoftwareView::getMouseLeftButtonDOWN()
{
	return MouseLeftButtonDOWN;
}

// ������� ���������� ������� ����
CPoint COmegaSoftwareView::getMouseLeftButtonUP()
{
	return MouseLeftButtonUP;
}


void COmegaSoftwareView::OnRectangleButton()
{
	if (action)
	{
		delete action;
	}
	action = new MyRectangle();
}


void COmegaSoftwareView::OnLButtonDown(UINT nFlags, CPoint point)
{
	MouseLeftButtonDOWN = point;
}


void COmegaSoftwareView::OnLButtonUp(UINT nFlags, CPoint point)
{
	MouseLeftButtonUP = point;
	COmegaSoftwareDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (action)
	{
		action = action->Execute(pDoc->getFigureData());
	}
	Invalidate();
}


void COmegaSoftwareView::OnEllipseButton()
{
	if (action)
	{
		delete action;
	}
	action = new MyEllipse();
}


void COmegaSoftwareView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (((nFlags & MK_LBUTTON) == MK_LBUTTON) && action){
		MouseLeftButtonUP = point;
		action->OnMouseMoveReaction(this->getMouseLeftButtonDOWN(), this->getMouseLeftButtonUP());
		Invalidate();
	}
}


void COmegaSoftwareView::OnRelationButton()
{
	if (action)
	{
		delete action;
	}
	action = new MyRelation();
}

void COmegaSoftwareView::OnHandButton()
{
	if (action)
	{
		delete action;
	}
	action = new MyHand();
}

void COmegaSoftwareView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CView::OnUpdate(pSender, lHint, pHint);
	Invalidate();
}
