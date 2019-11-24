
// BigCharPrinterView.h : CBigCharPrinterView ��Ľӿ�
//

#pragma once

#include "resource.h"

#include "DiaPrintEdit.h"
#include "DiaPrintControl.h"
#include "DiaMouthClean.h"
#include "DiaPrintParam.h"
#include "DiaCustomIcon.h"
#include "DiaSystemSetting.h"
#include "DiaCounter.h"
#include "DiaClassSetting.h"


class CBigCharPrinterView : public CFormView
{
protected: // �������л�����
	CBigCharPrinterView();
	DECLARE_DYNCREATE(CBigCharPrinterView)

public:
	enum{ IDD = IDD_BIGCHARPRINTER_FORM };

// ����
public:
	CBigCharPrinterDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CBigCharPrinterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


public:
	CMFCTabCtrl m_tab;
	CDiaPrintEdit *m_dlgPrintEdit;
	CDiaPrintControl *m_dlgPrintControl;
	CDiaMouthClean *m_dlgMouthClean;
	CDiaPrintParam *m_dlgPrintParam;
	CDiaCustomIcon *m_dlgCustomIcon;
	CDiaSystemSetting *m_dlgSystemSetting;
	CDiaCounter *m_dlgCounter;
	CDiaClassSetting *m_dlgClassSetting;

public:
	void ShowDialogByID(int ID);


protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButPrintEdit();
	afx_msg void OnBnClickedButPrintParam();
	afx_msg void OnBnClickedButIcon();
	afx_msg void OnBnClickedButSystem();
	afx_msg void OnBnClickedButClean();
	afx_msg void OnBnClickedButPrintControl();
	afx_msg void OnBnClickedButCounter();
	afx_msg void OnBnClickedButClassSetting();
};

#ifndef _DEBUG  // BigCharPrinterView.cpp �еĵ��԰汾
inline CBigCharPrinterDoc* CBigCharPrinterView::GetDocument() const
   { return reinterpret_cast<CBigCharPrinterDoc*>(m_pDocument); }
#endif

