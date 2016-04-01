
// OmegaSoftware.Test.ProjectView.cpp : ���������� ������ COmegaSoftwareTestProjectView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "OmegaSoftware.Test.Project.h"
#endif

#include "OmegaSoftware.Test.ProjectDoc.h"
#include "OmegaSoftware.Test.ProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COmegaSoftwareTestProjectView

IMPLEMENT_DYNCREATE(COmegaSoftwareTestProjectView, CView)

BEGIN_MESSAGE_MAP(COmegaSoftwareTestProjectView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COmegaSoftwareTestProjectView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ��������/����������� COmegaSoftwareTestProjectView

COmegaSoftwareTestProjectView::COmegaSoftwareTestProjectView()
{
	// TODO: �������� ��� ��������

}

COmegaSoftwareTestProjectView::~COmegaSoftwareTestProjectView()
{
}

BOOL COmegaSoftwareTestProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� COmegaSoftwareTestProjectView

void COmegaSoftwareTestProjectView::OnDraw(CDC* /*pDC*/)
{
	COmegaSoftwareTestProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ COmegaSoftwareTestProjectView


void COmegaSoftwareTestProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL COmegaSoftwareTestProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void COmegaSoftwareTestProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void COmegaSoftwareTestProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}

void COmegaSoftwareTestProjectView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COmegaSoftwareTestProjectView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� COmegaSoftwareTestProjectView

#ifdef _DEBUG
void COmegaSoftwareTestProjectView::AssertValid() const
{
	CView::AssertValid();
}

void COmegaSoftwareTestProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COmegaSoftwareTestProjectDoc* COmegaSoftwareTestProjectView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COmegaSoftwareTestProjectDoc)));
	return (COmegaSoftwareTestProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� COmegaSoftwareTestProjectView
