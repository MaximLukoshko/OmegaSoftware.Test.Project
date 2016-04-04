
// OmegaSoftwareDoc.h : ��������� ������ COmegaSoftwareDoc
//


#pragma once
#include "MyData.h"

class MyData;

class COmegaSoftwareDoc : public CDocument
{
protected: // ������� ������ �� ������������
	COmegaSoftwareDoc();
	DECLARE_DYNCREATE(COmegaSoftwareDoc)

// ��������
public:

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~COmegaSoftwareDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	// �������� �����
	MyData* figuresData;
public:
	// �������� ������ � �������
	MyData* getFigureData();
protected:
	COmegaSoftwareView* activeView;
public:
	void setView(COmegaSoftwareView* v);
};
