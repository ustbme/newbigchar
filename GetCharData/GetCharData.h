// GetCharData.h : GetCharData DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGetCharDataApp
// �йش���ʵ�ֵ���Ϣ������� GetCharData.cpp
//

class CGetCharDataApp : public CWinApp
{
public:
	CGetCharDataApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
