#pragma once
 
#include "afxwin.h"
#include "ObjectFileDeal.h"
 
#define m_nRowSum 16
#define m_nColSum 195

// CDiaPrintEdit 对话框

class CDiaPrintEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrintEdit)

public:
	CDiaPrintEdit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaPrintEdit();

// 对话框数据
	enum { IDD = IDD_DIA_PRINT_EDIT };
 
public:
	bool m_bDesign;	 
	int  m_nStepPixels;

	bool m_arrPrintData[m_nRowSum][m_nColSum];
	CObjectFileDeal m_PrintObjectsDeal;
	int m_nSelectObjIndex;
public:
	void DrawOnePoint(CDC* pDC ,int row,int col);

 

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
 
public:
	CComboBox m_ComParam;
	CComboBox m_ComData;
	CStatic m_designArea;
	CComboBox m_comFonts;
	CString m_strInputText;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButDesignView();
	afx_msg void OnBnClickedButPrintView();
	afx_msg void OnBnClickedButDesignClean();
	afx_msg void OnBnClickedButDesignSave();
	afx_msg void OnBnClickedButOpenDesign();
	afx_msg void OnBnClickedButInsertParam();
	afx_msg void OnBnClickedButInsertDada();
	afx_msg void OnBnClickedButAddText();
	afx_msg void OnBnClickedButMoveUp();
	afx_msg void OnBnClickedButMoveDown();
	afx_msg void OnBnClickedButMoveLeft();
	afx_msg void OnBnClickedButMoveRight();
	afx_msg void OnBnClickedButDelText();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

};
