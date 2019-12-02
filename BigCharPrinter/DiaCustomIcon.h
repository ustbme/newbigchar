#pragma once
#include "afxwin.h"


// CDiaCustomIcon �Ի���

class CDiaCustomIcon : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaCustomIcon)

public:
	CDiaCustomIcon(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaCustomIcon();

// �Ի�������
	enum { IDD = IDD_DIA_CUSTOM_ICON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
