#pragma once
#include "afxwin.h"


// CDiaCustomIcon 对话框

class CDiaCustomIcon : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaCustomIcon)

public:
	CDiaCustomIcon(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaCustomIcon();

// 对话框数据
	enum { IDD = IDD_DIA_CUSTOM_ICON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:	
	 
	CStatic m_drawPic;
	bool m_arrData[16][16];
	int m_nStep;
	void Serialize(CArchive &ar);
	virtual BOOL Save2File();
	virtual BOOL Read2File();

protected:
	CString  m_binFileName;
	CString FileName();

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();

	
	CButton m_OpenPic;
	CButton m_SavePic;
	afx_msg void OnBnClickedOpenpic();
	afx_msg void OnBnClickedSavepic();
};
