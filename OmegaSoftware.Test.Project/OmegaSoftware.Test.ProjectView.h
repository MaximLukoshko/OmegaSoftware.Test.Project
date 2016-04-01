
// OmegaSoftware.Test.ProjectView.h : ��������� ������ COmegaSoftwareTestProjectView
//

#pragma once


class COmegaSoftwareTestProjectView : public CView
{
protected: // ������� ������ �� ������������
	COmegaSoftwareTestProjectView();
	DECLARE_DYNCREATE(COmegaSoftwareTestProjectView)

// ��������
public:
	COmegaSoftwareTestProjectDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~COmegaSoftwareTestProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � OmegaSoftware.Test.ProjectView.cpp
inline COmegaSoftwareTestProjectDoc* COmegaSoftwareTestProjectView::GetDocument() const
   { return reinterpret_cast<COmegaSoftwareTestProjectDoc*>(m_pDocument); }
#endif

