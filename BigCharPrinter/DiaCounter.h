#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDiaCounter 对话框

class CDiaCounter : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaCounter)

public:
	CDiaCounter(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaCounter();

// 对话框数据
	enum { IDD = IDD_DIA_COUNTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit m_countnum1;
	CEdit m_countnum2;
	CEdit m_countnum3;
	CSpinButtonCtrl m_countnumchange1;
	CSpinButtonCtrl m_countnumchange2;
	CSpinButtonCtrl m_countnumchange3;
	CEdit m_goalnum1;
	CEdit m_goalnum2;
	CEdit m_goalnum3;
	CSpinButtonCtrl m_goalnumchange1;
	CSpinButtonCtrl m_goalnumchange2;
	CSpinButtonCtrl m_goalnumchange3;
	CEdit m_startnum1;
	CEdit m_startnum2;
	CEdit m_startnum3;
	CSpinButtonCtrl m_startnumchange1;
	CSpinButtonCtrl m_startnumchange2;
	CSpinButtonCtrl m_startnumchange3;
	CEdit m_currentnum1;
	CEdit m_currentnum2;
	CEdit m_currentnum3;
	CSpinButtonCtrl m_currentnumchange1;
	CSpinButtonCtrl m_currentnumchange2;
	CSpinButtonCtrl m_currentnumchange3;
	CEdit m_countnum33;
	CSpinButtonCtrl m_countnumchange33;
	CButton m_write1;
	CButton m_write2;
	afx_msg void OnBnClickedButWrite3();
//	CButton m_write3;
	CButton m_read1;
	CButton m_read2;
	CButton m_m_read3;
	afx_msg void OnBnClickedButWrite1();
	afx_msg void OnBnClickedButWrite2();
	CButton m_write3;
	afx_msg void OnBnClickedButRead1();
	afx_msg void OnBnClickedButRead2();
	afx_msg void OnBnClickedButRead3();

//CButton m_plus1;
//CButton m_plus2;
//CButton m_plus1;
//int m_plus2;
//CButton m_plus2;
//CButton m_plus3;
//int m_devide1;
//int m_devide2;
//int m_devide3;
//int m_devide3;
//int m_devide4;
//CButton m_plus4;
};
