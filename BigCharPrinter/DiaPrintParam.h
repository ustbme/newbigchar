#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "afxdtctl.h"


// CDiaPrintParam 对话框

class CDiaPrintParam : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrintParam)
public:
	CDiaPrintParam(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaPrintParam();

// 对话框数据
	enum { IDD = IDD_DIA_PRINT_PARAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit m_bide;
	CSpinButtonCtrl m_bidechange;
	CEdit m_size;
	CSpinButtonCtrl m_sizechange;
	CEdit m_delay;
	CSpinButtonCtrl m_delaychange;
	CEdit m_space;
	CSpinButtonCtrl m_spacechangr;
	CEdit m_plusenum;
	CSpinButtonCtrl m_plusenumchange;
	CEdit m_printnum;
	CSpinButtonCtrl m_printnumchange;
	CEdit m_printtime;
	CSpinButtonCtrl m_printtimechange;
	CEdit m_effect;
	CSpinButtonCtrl m_effectchange;
	afx_msg void OnBnClickedRadio2();
	CDateTimeCtrl m_datechoose;
	afx_msg void OnDtnDatetimechangeDateDatechosse(NMHDR *pNMHDR, LRESULT *pResult);
	CDateTimeCtrl m_datetime;
	afx_msg void OnDtnDatetimechangeDateTime(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDateEffectdate(NMHDR *pNMHDR, LRESULT *pResult);
	CButton m_writeparam;
	afx_msg void OnBnClickedButwriteparam();
//	CButton m_readparam;
	CButton m_Readparam;
	afx_msg void OnBnClickedButreadparam();
	CButton m_writedate;
	afx_msg void OnBnClickedButWritedate();
	CButton m_readdate;
	afx_msg void OnBnClickedButReaddate();
	CButton m_writeeffectdate;
	CButton m_readeffectdate;
	afx_msg void OnBnClickedButWriteeffectdate();
	afx_msg void OnBnClickedButReadeffectdate();
};
