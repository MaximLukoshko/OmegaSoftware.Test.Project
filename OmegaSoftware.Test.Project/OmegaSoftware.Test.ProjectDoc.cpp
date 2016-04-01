
// OmegaSoftware.Test.ProjectDoc.cpp : ���������� ������ COmegaSoftwareTestProjectDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "OmegaSoftware.Test.Project.h"
#endif

#include "OmegaSoftware.Test.ProjectDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COmegaSoftwareTestProjectDoc

IMPLEMENT_DYNCREATE(COmegaSoftwareTestProjectDoc, CDocument)

BEGIN_MESSAGE_MAP(COmegaSoftwareTestProjectDoc, CDocument)
END_MESSAGE_MAP()


// ��������/����������� COmegaSoftwareTestProjectDoc

COmegaSoftwareTestProjectDoc::COmegaSoftwareTestProjectDoc()
{
	// TODO: �������� ��� ��� ������������ ������ ������������

}

COmegaSoftwareTestProjectDoc::~COmegaSoftwareTestProjectDoc()
{
}

BOOL COmegaSoftwareTestProjectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)

	return TRUE;
}




// ������������ COmegaSoftwareTestProjectDoc

void COmegaSoftwareTestProjectDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
	}
	else
	{
		// TODO: �������� ��� ��������
	}
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void COmegaSoftwareTestProjectDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void COmegaSoftwareTestProjectDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
	SetSearchContent(strSearchContent);
}

void COmegaSoftwareTestProjectDoc::SetSearchContent(const CString& value)
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

// ����������� COmegaSoftwareTestProjectDoc

#ifdef _DEBUG
void COmegaSoftwareTestProjectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COmegaSoftwareTestProjectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ������� COmegaSoftwareTestProjectDoc
