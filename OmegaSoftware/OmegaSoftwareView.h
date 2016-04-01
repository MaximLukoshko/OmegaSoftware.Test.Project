
// OmegaSoftwareView.h : интерфейс класса COmegaSoftwareView
//

#pragma once


class COmegaSoftwareView : public CView
{
protected: // создать только из сериализации
	COmegaSoftwareView();
	DECLARE_DYNCREATE(COmegaSoftwareView)

// Атрибуты
public:
	COmegaSoftwareDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~COmegaSoftwareView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в OmegaSoftwareView.cpp
inline COmegaSoftwareDoc* COmegaSoftwareView::GetDocument() const
   { return reinterpret_cast<COmegaSoftwareDoc*>(m_pDocument); }
#endif

