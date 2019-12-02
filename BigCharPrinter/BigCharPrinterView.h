
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
#include "DiaPrinterManage.h"
#include "afxwin.h"
#include "BtnST.h"
#include "IOVsd.h"


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
	void InitCommMsg();
	void GetDataStr(CString strTree,CString strFileName,CString strParam,CString &strContent);

// ����
public:
	CIOVsd m_vsd[1];//ʹ����������
	CWinThread* m_pThreadSend;//���ݴ���ͷ����߳�
	CWinThread*  m_pThreadRecv;//���ݴ���ͷ�����
	int    m_nCycleLen;//���ڳ���	��λ��ms
	HANDLE m_hTime;
	HANDLE m_hEvent;
	HANDLE m_hRevTime;//��������ʱ���¼����


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

protected:
	HANDLE			m_hCompPort;					//��ɶ˿ھ��
	SOCKET			m_sListen;						//�����׽��� 
	HANDLE			m_hThread[20];	                //���߳�=�����߳�+�����߳�
	int				m_nThreadNum;					//ʵ���߳�����
	HANDLE			m_hEvent2;						//�����¼����



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
	CDiaPrinterManage *m_dlgPrinterManage;

	CButtonST m_ButPrintEdit;
	CButtonST m_ButPrintParam;
	CButtonST m_ButPrintClean;
	CButtonST m_ButPrintControl;
	CButtonST m_ButPrintCounter;
	CButtonST m_ButPrintIcon;
	CButtonST m_ButPrintClass;
	CButtonST m_ButPrintSystem;
	CButtonST m_ButPrinterManage;
public:
	void ShowDialogByID(int ID);


protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnBnClickedButPrinterManage();
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

