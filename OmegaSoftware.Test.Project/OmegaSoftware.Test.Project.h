
// OmegaSoftware.Test.Project.h : ������� ���� ��������� ��� ���������� OmegaSoftware.Test.Project
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// COmegaSoftwareTestProjectApp:
// � ���������� ������� ������ ��. OmegaSoftware.Test.Project.cpp
//

class COmegaSoftwareTestProjectApp : public CWinAppEx
{
public:
	COmegaSoftwareTestProjectApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COmegaSoftwareTestProjectApp theApp;
