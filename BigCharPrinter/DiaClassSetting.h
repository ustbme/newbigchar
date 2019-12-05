#pragma once
#include "afxwin.h"


// CDiaClassSetting 对话框

class CDiaClassSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaClassSetting)

public:
	CDiaClassSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaClassSetting();

// 对话框数据
	enum { IDD = IDD_DIA_CLASS_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChange1037();
	CEdit m_classsetting1;
	CEdit m_classsetting2;
	afx_msg void OnBnClickedClasssettingbutton1();
	afx_msg void OnBnClickedClasssettingbutton2();
	afx_msg void OnBnClickedClasssettingbutton0();
	CEdit m_classsetting3;
	CEdit m_classsetting4;
	CEdit m_classsetting5;
	CEdit m_classsetting6;
	CEdit m_classsetting7;
	CEdit m_classsetting8;
	CEdit m_classsetting9;
	CEdit m_classsetting10;
	CEdit m_classsetting11;
	CEdit m_classsetting12;
	CEdit m_classsetting13;
	CEdit m_classsetting14;
	CEdit m_classsetting15;
	CEdit m_classsetting16;
	CEdit m_classsetting17;
	CEdit m_classsetting18;
	CEdit m_classsetting19;
	CEdit m_classsetting20;
	CEdit m_classsetting21;
	CEdit m_classsetting22;
	CEdit m_classsetting23;
	CEdit m_classsetting24;
};
