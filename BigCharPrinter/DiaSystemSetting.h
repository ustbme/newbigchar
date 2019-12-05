#pragma once
#include "afxwin.h"


// CDiaSystemSetting 对话框

class CDiaSystemSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaSystemSetting)

public:
	CDiaSystemSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaSystemSetting();

// 对话框数据
	enum { IDD = IDD_DIA_SYSTEM_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CEdit m_system_setting1;
	CEdit m_system_setting2;
	CEdit m_system_setting3;
	CEdit m_system_setting4;
	CEdit m_system_setting5;
	afx_msg void OnBnClickedSystembutton1();
	afx_msg void OnBnClickedSystembutton2();
	afx_msg void OnBnClickedSystembutton3();
};
