
// OmegaSoftware.h : ������� ���� ��������� ��� ���������� OmegaSoftware
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// COmegaSoftwareApp:
// � ���������� ������� ������ ��. OmegaSoftware.cpp
//

class COmegaSoftwareApp : public CWinApp
{
public:
	COmegaSoftwareApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COmegaSoftwareApp theApp;
