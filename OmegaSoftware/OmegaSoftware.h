
// OmegaSoftware.h : главный файл заголовка для приложения OmegaSoftware
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// COmegaSoftwareApp:
// О реализации данного класса см. OmegaSoftware.cpp
//

class COmegaSoftwareApp : public CWinApp
{
public:
	COmegaSoftwareApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COmegaSoftwareApp theApp;
