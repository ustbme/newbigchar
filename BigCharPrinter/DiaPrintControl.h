#pragma once
#include "afxwin.h"
#include "BtnST.h"


// CDiaPrintControl 对话框

class CDiaPrintControl : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrintControl)

public:
	CDiaPrintControl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaPrintControl();

// 对话框数据
	enum { IDD = IDD_DIA_PRINT_CONTROL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButOpenFile();
	CButtonST m_ButOpenFile;
	virtual BOOL OnInitDialog();
};
