
// OmegaSoftwareView.h : ��������� ������ COmegaSoftwareView
//

#pragma once


class COmegaSoftwareView : public CView
{
protected: // ������� ������ �� ������������
	COmegaSoftwareView();
	DECLARE_DYNCREATE(COmegaSoftwareView)

// ��������
public:
	COmegaSoftwareDoc* GetDocument() const;

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
	virtual ~COmegaSoftwareView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � OmegaSoftwareView.cpp
inline COmegaSoftwareDoc* COmegaSoftwareView::GetDocument() const
   { return reinterpret_cast<COmegaSoftwareDoc*>(m_pDocument); }
#endif

