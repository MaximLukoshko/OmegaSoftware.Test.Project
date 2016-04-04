
// OmegaSoftwareDoc.cpp : реализация класса COmegaSoftwareDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "OmegaSoftware.h"
#endif

#include "OmegaSoftwareDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COmegaSoftwareDoc

IMPLEMENT_DYNCREATE(COmegaSoftwareDoc, CDocument)

BEGIN_MESSAGE_MAP(COmegaSoftwareDoc, CDocument)
END_MESSAGE_MAP()


// создание/уничтожение COmegaSoftwareDoc

COmegaSoftwareDoc::COmegaSoftwareDoc()
: activeView(NULL)
{
	// TODO: добавьте код для одноразового вызова конструктора

}

COmegaSoftwareDoc::~COmegaSoftwareDoc()
{
	delete figuresData;
}

BOOL COmegaSoftwareDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	figuresData = new MyData();
//	figuresData->setView(activeView);
	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// сериализация COmegaSoftwareDoc

void COmegaSoftwareDoc::Serialize(CArchive& ar)
{
	figuresData->Serialize(ar);
	UpdateAllViews(0);
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void COmegaSoftwareDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void COmegaSoftwareDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void COmegaSoftwareDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// диагностика COmegaSoftwareDoc

#ifdef _DEBUG
void COmegaSoftwareDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COmegaSoftwareDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды COmegaSoftwareDoc


// Получить данные о фигурах
MyData* COmegaSoftwareDoc::getFigureData()
{
	return figuresData;
}


//void COmegaSoftwareDoc::setView(COmegaSoftwareView* v)
//{
//	activeView = v;
//}
