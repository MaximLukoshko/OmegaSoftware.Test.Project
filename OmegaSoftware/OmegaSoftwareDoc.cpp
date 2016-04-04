
// OmegaSoftwareDoc.cpp : ���������� ������ COmegaSoftwareDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
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


// ��������/����������� COmegaSoftwareDoc

COmegaSoftwareDoc::COmegaSoftwareDoc()
: activeView(NULL)
{
	// TODO: �������� ��� ��� ������������ ������ ������������

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
	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)

	return TRUE;
}




// ������������ COmegaSoftwareDoc

void COmegaSoftwareDoc::Serialize(CArchive& ar)
{
	figuresData->Serialize(ar);
	UpdateAllViews(0);
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void COmegaSoftwareDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
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

// ��������� ������������ ������
void COmegaSoftwareDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
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

// ����������� COmegaSoftwareDoc

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


// ������� COmegaSoftwareDoc


// �������� ������ � �������
MyData* COmegaSoftwareDoc::getFigureData()
{
	return figuresData;
}


//void COmegaSoftwareDoc::setView(COmegaSoftwareView* v)
//{
//	activeView = v;
//}
