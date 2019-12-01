
// BigCharPrinterView.cpp : CBigCharPrinterView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "BigCharPrinter.h"
#endif

#include "BigCharPrinterDoc.h"
#include "BigCharPrinterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBigCharPrinterView

IMPLEMENT_DYNCREATE(CBigCharPrinterView, CFormView)

BEGIN_MESSAGE_MAP(CBigCharPrinterView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUT_PRINT_EDIT, &CBigCharPrinterView::OnBnClickedButPrintEdit)
	ON_BN_CLICKED(IDC_BUT_PRINT_PARAM, &CBigCharPrinterView::OnBnClickedButPrintParam)
	ON_BN_CLICKED(IDC_BUT_ICON, &CBigCharPrinterView::OnBnClickedButIcon)
	ON_BN_CLICKED(IDC_BUT_SYSTEM, &CBigCharPrinterView::OnBnClickedButSystem)
	ON_BN_CLICKED(IDC_BUT_CLEAN, &CBigCharPrinterView::OnBnClickedButClean)
	ON_BN_CLICKED(IDC_BUT_PRINT_CONTROL, &CBigCharPrinterView::OnBnClickedButPrintControl)
	ON_BN_CLICKED(IDC_BUT_COUNTER, &CBigCharPrinterView::OnBnClickedButCounter)
	ON_BN_CLICKED(IDC_BUT_CLASS_SETTING, &CBigCharPrinterView::OnBnClickedButClassSetting)
END_MESSAGE_MAP()

// CBigCharPrinterView ����/����

CBigCharPrinterView::CBigCharPrinterView()
	: CFormView(CBigCharPrinterView::IDD)
{
	// TODO: �ڴ˴���ӹ������

}

CBigCharPrinterView::~CBigCharPrinterView()
{
}

void CBigCharPrinterView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CBigCharPrinterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CBigCharPrinterView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CRect rc;
	GetClientRect(rc);
	/*if (!m_tab.Create(CMFCTabCtrl::STYLE_3D_ONENOTE, rc, this, 3000, CMFCTabCtrl::LOCATION_TOP,0))
	{
		return ;     
	}
*/
	m_dlgPrintEdit = new CDiaPrintEdit;
	m_dlgPrintControl = new CDiaPrintControl;
	m_dlgMouthClean = new CDiaMouthClean;
	m_dlgPrintParam = new CDiaPrintParam;
	m_dlgCustomIcon = new CDiaCustomIcon;
	m_dlgSystemSetting = new CDiaSystemSetting;
	m_dlgCounter = new CDiaCounter;
	m_dlgClassSetting = new CDiaClassSetting;


	/*pDlg1 = new CDiatest1(this);

	pDlg1->Create(IDD_DIALOG1,this);
	pDlg2 = new CDiaTest2(this);

	pDlg2->Create(IDD_DIALOG2,this);*/

	int nX = 100;
	int nY = 100;
	int nWidth = 900;
	int nHeight = 600;

	m_dlgPrintEdit->Create(IDD_DIA_PRINT_EDIT,this);
	m_dlgPrintEdit->SetFont(&afxGlobalData.fontRegular);	 
	m_dlgPrintEdit->MoveWindow(nX,nY,nWidth,nHeight);

	m_dlgPrintControl->Create(IDD_DIA_PRINT_CONTROL,this);
	m_dlgPrintControl->SetFont(&afxGlobalData.fontBold);
	m_dlgPrintControl->MoveWindow(nX,nY,nWidth,nHeight);
 
	m_dlgMouthClean->Create(IDD_DIA_MOUTH_CLEAN,this);
	m_dlgMouthClean->SetFont(&afxGlobalData.fontDefaultGUIBold);
	m_dlgMouthClean->MoveWindow(nX,nY,nWidth,nHeight);

	m_dlgPrintParam->Create(IDD_DIA_PRINT_PARAM,this);
	m_dlgPrintParam->SetFont(&afxGlobalData.fontRegular);
	m_dlgPrintParam->MoveWindow(nX,nY,nWidth,nHeight);

	m_dlgCustomIcon->Create(IDD_DIA_CUSTOM_ICON,this);
	m_dlgCustomIcon->SetFont(&afxGlobalData.fontBold);
	m_dlgCustomIcon->MoveWindow(nX,nY,nWidth,nHeight);

	m_dlgSystemSetting->Create(IDD_DIA_SYSTEM_SETTING,this);
	m_dlgSystemSetting->SetFont(&afxGlobalData.fontDefaultGUIBold);
	m_dlgSystemSetting->MoveWindow(nX,nY,nWidth,nHeight);

	m_dlgCounter->Create(IDD_DIA_COUNTER,this);
	m_dlgCounter->SetFont(&afxGlobalData.fontDefaultGUIBold);
	m_dlgCounter->MoveWindow(nX,nY,nWidth,nHeight);

	m_dlgClassSetting->Create(IDD_DIA_CLASS_SETTING,this);
	m_dlgClassSetting->SetFont(&afxGlobalData.fontDefaultGUIBold);
	m_dlgClassSetting->MoveWindow(nX,nY,nWidth,nHeight);


	//m_tab.AddTab(m_dlgPrintEdit,L"��ӡ�༭");
	//m_tab.AddTab(m_dlgPrintControl,L"��ӡ����");
	//m_tab.AddTab(m_dlgMouthClean,L"��ͷ��ϴ");
	//m_tab.AddTab(m_dlgPrintParam,L"��ӡ����");
	//m_tab.AddTab(m_dlgCustomIcon,L"ͼ���༭");
	//m_tab.AddTab(m_dlgSystemSetting,L"ϵͳ����");


	//m_tab.EnableActiveTabCloseButton();//�Ƿ���ӹر�ѡ���ť
//	m_tab.SetActiveTab(0); //����ѡ�,�Ե�ǰѡ�Ϊ��һҳ��
}

void CBigCharPrinterView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBigCharPrinterView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBigCharPrinterView ���

#ifdef _DEBUG
void CBigCharPrinterView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBigCharPrinterView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CBigCharPrinterDoc* CBigCharPrinterView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBigCharPrinterDoc)));
	return (CBigCharPrinterDoc*)m_pDocument;
}
#endif //_DEBUG


// CBigCharPrinterView ��Ϣ�������

void CBigCharPrinterView::ShowDialogByID(int ID)
{
	m_dlgPrintEdit->ShowWindow(SW_HIDE);
	m_dlgPrintControl->ShowWindow(SW_HIDE);
	m_dlgMouthClean->ShowWindow(SW_HIDE);
	m_dlgPrintParam->ShowWindow(SW_HIDE);	
	m_dlgCustomIcon->ShowWindow(SW_HIDE);
	m_dlgSystemSetting->ShowWindow(SW_HIDE);
	m_dlgCounter->ShowWindow(SW_HIDE);
	m_dlgClassSetting->ShowWindow(SW_HIDE);

	if(ID == IDD_DIA_PRINT_EDIT)
	{
		m_dlgPrintEdit->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_PRINT_CONTROL)			
	{
		m_dlgPrintControl->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_MOUTH_CLEAN)			
	{
		m_dlgMouthClean->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_PRINT_PARAM)			
	{
		m_dlgPrintParam->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_CUSTOM_ICON)			
	{
		m_dlgCustomIcon->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_SYSTEM_SETTING)			
	{
		m_dlgSystemSetting->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_COUNTER)			
	{
		m_dlgCounter->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_CLASS_SETTING)			
	{
		m_dlgClassSetting->ShowWindow(SW_SHOW);
	}
	
}


void CBigCharPrinterView::OnBnClickedButPrintEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	ShowDialogByID(IDD_DIA_PRINT_EDIT);

}

void CBigCharPrinterView::OnBnClickedButPrintParam()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowDialogByID(IDD_DIA_PRINT_PARAM);
}


void CBigCharPrinterView::OnBnClickedButIcon()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowDialogByID(IDD_DIA_CUSTOM_ICON);
}


void CBigCharPrinterView::OnBnClickedButSystem()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowDialogByID(IDD_DIA_SYSTEM_SETTING);
}


void CBigCharPrinterView::OnBnClickedButClean()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowDialogByID(IDD_DIA_MOUTH_CLEAN);
}


void CBigCharPrinterView::OnBnClickedButPrintControl()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowDialogByID(IDD_DIA_PRINT_CONTROL);
}


void CBigCharPrinterView::OnBnClickedButCounter()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	 ShowDialogByID(IDD_DIA_COUNTER);

}


void CBigCharPrinterView::OnBnClickedButClassSetting()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowDialogByID(IDD_DIA_CLASS_SETTING);

}
