
// OmegaSoftware.Test.ProjectView.cpp : реализаци€ класса COmegaSoftwareTestProjectView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
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
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COmegaSoftwareTestProjectView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// создание/уничтожение COmegaSoftwareTestProjectView

COmegaSoftwareTestProjectView::COmegaSoftwareTestProjectView()
{
	// TODO: добавьте код создани€

}

COmegaSoftwareTestProjectView::~COmegaSoftwareTestProjectView()
{
}

BOOL COmegaSoftwareTestProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование COmegaSoftwareTestProjectView

void COmegaSoftwareTestProjectView::OnDraw(CDC* /*pDC*/)
{
	COmegaSoftwareTestProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
}


// печать COmegaSoftwareTestProjectView


void COmegaSoftwareTestProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL COmegaSoftwareTestProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void COmegaSoftwareTestProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void COmegaSoftwareTestProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
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


// диагностика COmegaSoftwareTestProjectView

#ifdef _DEBUG
void COmegaSoftwareTestProjectView::AssertValid() const
{
	CView::AssertValid();
}

void COmegaSoftwareTestProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COmegaSoftwareTestProjectDoc* COmegaSoftwareTestProjectView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COmegaSoftwareTestProjectDoc)));
	return (COmegaSoftwareTestProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений COmegaSoftwareTestProjectView
