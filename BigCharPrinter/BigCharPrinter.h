
// BigCharPrinter.h : BigCharPrinter Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CBigCharPrinterApp:
// �йش����ʵ�֣������ BigCharPrinter.cpp
//

class CBigCharPrinterApp : public CWinAppEx
{
public:
	CBigCharPrinterApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBigCharPrinterApp theApp;
