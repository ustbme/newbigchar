#pragma once
#include "afxwin.h"
#include "BtnST.h"


// CDiaPrintControl �Ի���

class CDiaPrintControl : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrintControl)

public:
	CDiaPrintControl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaPrintControl();

// �Ի�������
	enum { IDD = IDD_DIA_PRINT_CONTROL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButOpenFile();
	CButtonST m_ButOpenFile;
	virtual BOOL OnInitDialog();
};
