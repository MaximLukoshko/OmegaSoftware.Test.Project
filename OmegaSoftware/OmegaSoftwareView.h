
// OmegaSoftwareView.h : ��������� ������ COmegaSoftwareView
//

#pragma once
#include "IMyButtonAction.h"
#include "OmegaSoftwareDoc.h"

class IMyButtonAction;
class COmegaSoftwareDoc;

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
protected:
	// �������� �� ������� �� ������
	IMyButtonAction* action;
	//���������� ����
	CPoint MouseLeftButtonDOWN;
	CPoint MouseLeftButtonUP;
public:
	// ������� ���������� ����
	CPoint getMouseLeftButtonDOWN();
	CPoint getMouseLeftButtonUP();

	afx_msg void OnRectangleButton();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnEllipseButton();
	afx_msg void OnRelationButton();
	afx_msg void OnHandButton();
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
};

#ifndef _DEBUG  // ���������� ������ � OmegaSoftwareView.cpp
inline COmegaSoftwareDoc* COmegaSoftwareView::GetDocument() const
   { return reinterpret_cast<COmegaSoftwareDoc*>(m_pDocument); }
#endif

