
// BigCharPrinterView.h : CBigCharPrinterView 类的接口
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
protected: // 仅从序列化创建
	CBigCharPrinterView();
	DECLARE_DYNCREATE(CBigCharPrinterView)

public:
	enum{ IDD = IDD_BIGCHARPRINTER_FORM };

// 特性
public:
	CBigCharPrinterDoc* GetDocument() const;
	void InitCommMsg();
	void GetDataStr(CString strTree,CString strFileName,CString strParam,CString &strContent);

// 操作
public:
	CIOVsd m_vsd[1];//使用三个串口
	CWinThread* m_pThreadSend;//数据处理和发送线程
	CWinThread*  m_pThreadRecv;//数据处理和发送线
	int    m_nCycleLen;//周期长度	单位是ms
	HANDLE m_hTime;
	HANDLE m_hEvent;
	HANDLE m_hRevTime;//接收数据时间事件句柄


// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CBigCharPrinterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	HANDLE			m_hCompPort;					//完成端口句柄
	SOCKET			m_sListen;						//监听套接字 
	HANDLE			m_hThread[20];	                //子线程=监听线程+服务线程
	int				m_nThreadNum;					//实际线程数量
	HANDLE			m_hEvent2;						//监听事件句柄



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

// 生成的消息映射函数
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

#ifndef _DEBUG  // BigCharPrinterView.cpp 中的调试版本
inline CBigCharPrinterDoc* CBigCharPrinterView::GetDocument() const
   { return reinterpret_cast<CBigCharPrinterDoc*>(m_pDocument); }
#endif

