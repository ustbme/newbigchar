
// BigCharPrinterView.cpp : CBigCharPrinterView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	ON_BN_CLICKED(IDC_BUT_PRINTER_MANAGE, &CBigCharPrinterView::OnBnClickedButPrinterManage)
END_MESSAGE_MAP()

// CBigCharPrinterView 构造/析构

CBigCharPrinterView::CBigCharPrinterView()
	: CFormView(CBigCharPrinterView::IDD)
{
	// TODO: 在此处添加构造代码
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式


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

	m_dlgPrinterManage = new CDiaPrinterManage;
	
	int nX = 50;
	int nY = 140;
	int nWidth = 1000;
	int nHeight = 450;



	/*pDlg1 = new CDiatest1(this);

	pDlg1->Create(IDD_DIALOG1,this);
	pDlg2 = new CDiaTest2(this);

	pDlg2->Create(IDD_DIALOG2,this);*/



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

	m_dlgPrinterManage->Create(IDD_DIA_PRINTER_MANAGE,this);
	m_dlgPrinterManage->SetFont(&afxGlobalData.fontDefaultGUIBold);
	m_dlgPrinterManage->MoveWindow(nX,nY,nWidth,nHeight);

	//彩色图标设置
	m_ButPrintEdit.SubclassDlgItem(IDC_BUT_PRINT_EDIT,this);
 	m_ButPrintEdit.SetBitmaps(IDB_BITMAP4,RGB(255,255,255));
	m_ButPrintEdit.DrawTransparent(true);
	m_ButPrintEdit.SetFlat(0);
	m_ButPrintEdit.SetTooltipText(L"打印编辑");
	m_ButPrintEdit.SetAlign(CButtonST::ST_ALIGN_VERT);

	m_ButPrintParam.SubclassDlgItem(IDC_BUT_PRINT_PARAM,this);
	/*m_ButPrintParam.SetBitmaps(IDB_BITMAP3,RGB(255,255,255));
	m_ButPrintParam.DrawTransparent(true);
	m_ButPrintParam.SetFlat(0);
	m_ButPrintParam.SetAlign(CButtonST::ST_ALIGN_VERT);
	*/
	m_ButPrintParam.SetTooltipText(L"打印参数");
	m_ButPrintParam.SetBitmaps(IDB_BITMAP5,RGB(255,255,255));
	m_ButPrintParam.DrawBorder(FALSE);
	m_ButPrintParam.SetFlat(1);
//	m_ButPrintParam.SetColor(CButtonST::BTNST_COLOR_BK_OUT, RGB(255,0,0));
//	m_ButPrintParam.SetColor(CButtonST::BTNST_COLOR_BK_IN, RGB(0,208,0));
//	m_ButPrintParam.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, RGB(0,0,208));



	m_ButPrintClean.SubclassDlgItem(IDC_BUT_CLEAN,this);
	m_ButPrintClean.SetBitmaps(IDB_BITMAP1,RGB(255,255,255));
	m_ButPrintClean.DrawTransparent(true);
	m_ButPrintClean.SetFlat(0);
	m_ButPrintClean.SetTooltipText(L"喷头清洗");
	m_ButPrintClean.SetAlign(CButtonST::ST_ALIGN_VERT);

	m_ButPrintControl.SubclassDlgItem(IDC_BUT_PRINT_CONTROL,this);
	m_ButPrintControl.SetBitmaps(IDB_BITMAP1,RGB(255,255,255));
	m_ButPrintControl.DrawTransparent(true);
	m_ButPrintControl.SetFlat(0);
	m_ButPrintControl.SetTooltipText(L"打印控制");
	m_ButPrintControl.SetAlign(CButtonST::ST_ALIGN_VERT);

	m_ButPrintCounter.SubclassDlgItem(IDC_BUT_COUNTER,this);
	m_ButPrintCounter.SetBitmaps(IDB_BITMAP1,RGB(255,255,255));
	m_ButPrintCounter.DrawTransparent(true);
	m_ButPrintCounter.SetFlat(0);
	m_ButPrintCounter.SetTooltipText(L"打印计数");
	m_ButPrintCounter.SetAlign(CButtonST::ST_ALIGN_VERT);

	m_ButPrintIcon.SubclassDlgItem(IDC_BUT_ICON,this);
	m_ButPrintIcon.SetBitmaps(IDB_BITMAP1,RGB(255,255,255));
	m_ButPrintIcon.DrawTransparent(true);
	m_ButPrintIcon.SetFlat(0);
	m_ButPrintIcon.SetTooltipText(L"打印图标");
	m_ButPrintIcon.SetAlign(CButtonST::ST_ALIGN_VERT);

	m_ButPrintClass.SubclassDlgItem(IDC_BUT_CLASS_SETTING,this);
	m_ButPrintClass.SetBitmaps(IDB_BITMAP1,RGB(255,255,255));
	m_ButPrintClass.DrawTransparent(true);
	m_ButPrintClass.SetFlat(0);
	m_ButPrintClass.SetTooltipText(L"班次设定");
	m_ButPrintClass.SetAlign(CButtonST::ST_ALIGN_VERT);

	m_ButPrintSystem.SubclassDlgItem(IDC_BUT_SYSTEM,this);
	m_ButPrintSystem.SetBitmaps(IDB_BITMAP1,RGB(255,255,255));
	m_ButPrintSystem.DrawTransparent(true);
	m_ButPrintSystem.SetFlat(0);
	m_ButPrintSystem.SetTooltipText(L"系统设置");
	m_ButPrintSystem.SetAlign(CButtonST::ST_ALIGN_VERT);

	m_ButPrinterManage.SubclassDlgItem(IDC_BUT_PRINTER_MANAGE,this);
	m_ButPrinterManage.SetBitmaps(IDB_BITMAP1,RGB(255,255,255));
	m_ButPrinterManage.DrawTransparent(true);
	m_ButPrinterManage.SetFlat(0);
	m_ButPrinterManage.SetTooltipText(L"设备管理");
	m_ButPrinterManage.SetAlign(CButtonST::ST_ALIGN_VERT);

	//m_dlgPrinterManage->ShowWindow(SW_SHOW);
	m_dlgPrintEdit->ShowWindow(SW_SHOW);


	InitCommMsg();//初始化串口
}

void CBigCharPrinterView::GetDataStr(CString strTree,CString strFileName,CString strParam,CString &strContent)
{
	//先获取文件大小,在确定需要多少空间来存放数据库连接信息
	CFileStatus status;
	long lFileSize = 0;
	if (CFile::GetStatus(strFileName,status))
	{
		lFileSize = status.m_size;
	}
	USES_CONVERSION; 

	if (lFileSize > 0)
	{
		WCHAR* pDataSource = new WCHAR[lFileSize+1];
		memset(pDataSource,0,lFileSize+1);
		DWORD dwReadSize = GetPrivateProfileString(strTree,strParam, L"",pDataSource, lFileSize, strFileName);
		if (dwReadSize != 0)
		{
			strContent.Format(_T("%s"),pDataSource);
		}

		delete[] pDataSource;
	}
}

void CBigCharPrinterView::InitCommMsg()
{
	CString strContent = _T("");
	CString strTree = _T("");//树干
	CString	strLeaf = _T("");//树叶名称
	MyDcb   tempDcb;
	int     nComNum = 0;
	int     i=0;
	char *p = NULL;
	char szLocalInfoConfigFileName[512] = {0};
	CString strConfigFile;
	/* 获得文件路径 */
	USES_CONVERSION; 

	//if(0 == GetModuleFileName(NULL, A2W(szLocalInfoConfigFileName), 512))
	//{
	//	return;//获取路径失败
	//}
//	p = strrchr(szLocalInfoConfigFileName, '\\');
//	*p = 0;
	strConfigFile.Format(_T("%s"),_T("..\\bin\\SerialPortSet.ini"));

	strTree = _T("本地串口数配置");
	strLeaf = _T("本地串口数");
	GetDataStr(strTree,strConfigFile,strLeaf,strContent);
	nComNum = atoi(W2A(strContent.GetBuffer(0)));//串口个数(修改成1)
	for (i=0; i<nComNum; i++)
	{
		memset(&tempDcb,0,sizeof(MyDcb));
		//目前树干为：  主机配置信息
		strTree.Format(_T("串口配置%d"),i+1);
		//树叶为:端口 
		strLeaf = "端口";
		GetDataStr(strTree,strConfigFile,strLeaf,strContent);
		tempDcb.nComPort = atoi(W2A(strContent));

		strLeaf = "波特率";
		GetDataStr(strTree,strConfigFile,strLeaf,strContent);
		tempDcb.BaudRate = atol(W2A(strContent));

		strLeaf = "校验位";
		GetDataStr(strTree,strConfigFile,strLeaf,strContent);
		tempDcb.Parity = (BYTE)atoi(W2A(strContent));

		strLeaf = "数据位";
		GetDataStr(strTree,strConfigFile,strLeaf,strContent);
		tempDcb.ByteSize = (BYTE)atoi(W2A(strContent));

		strLeaf = "停止位";
		GetDataStr(strTree,strConfigFile,strLeaf,strContent);
		tempDcb.StopBits = (BYTE)atoi(W2A(strContent));

		strLeaf = "是否存储";
		GetDataStr(strTree,strConfigFile,strLeaf,strContent);
		tempDcb.bIsSave = (BOOL)atoi(W2A(strContent));

		// 		m_vsd.SetParentPoint(this);
		m_vsd[i].SetComIndx(tempDcb.nComPort);
		if (!m_vsd[i].OpenComm(tempDcb))
		{
			CString csMsg = _T("");
			csMsg.Format(_T("串口%d打开失败!"),tempDcb.nComPort);
			AfxMessageBox(csMsg);
		}
	}

	//m_pThreadSend = AfxBeginThread(
	//	ThreadProc_SendAndDataProc,
	//	(LPVOID)this,
	//	THREAD_PRIORITY_NORMAL,
	//	0,
	//	CREATE_SUSPENDED
	//	);
	//ASSERT(m_pThreadSend);
	//m_pThreadSend->m_bAutoDelete = FALSE;
	//m_pThreadSend->ResumeThread();

	/*m_pThreadRecv = AfxBeginThread(
	ThreadProc_RecvData,
	(LPVOID)this,
	THREAD_PRIORITY_NORMAL,
	0,
	CREATE_SUSPENDED
	);
	ASSERT(m_pThreadRecv);
	m_pThreadRecv->m_bAutoDelete = FALSE;
	m_pThreadRecv->ResumeThread();*/
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


// CBigCharPrinterView 诊断

#ifdef _DEBUG
void CBigCharPrinterView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBigCharPrinterView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CBigCharPrinterDoc* CBigCharPrinterView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBigCharPrinterDoc)));
	return (CBigCharPrinterDoc*)m_pDocument;
}
#endif //_DEBUG


// CBigCharPrinterView 消息处理程序

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
	m_dlgPrinterManage->ShowWindow(SW_HIDE);

	if(ID == IDD_DIA_PRINT_EDIT)
	{
		GetDlgItem(IDC_STATIC_DIA_NAME)->SetWindowText(L"打印编辑");
		m_dlgPrintEdit->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_PRINT_CONTROL)			
	{
		GetDlgItem(IDC_STATIC_DIA_NAME)->SetWindowText(L"打印控制");
		m_dlgPrintControl->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_MOUTH_CLEAN)			
	{
		GetDlgItem(IDC_STATIC_DIA_NAME)->SetWindowText(L"喷头清洗");
		m_dlgMouthClean->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_PRINT_PARAM)			
	{
		GetDlgItem(IDC_STATIC_DIA_NAME)->SetWindowText(L"打印参数");
		m_dlgPrintParam->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_CUSTOM_ICON)			
	{
		GetDlgItem(IDC_STATIC_DIA_NAME)->SetWindowText(L"打印图标");
		m_dlgCustomIcon->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_SYSTEM_SETTING)			
	{
		GetDlgItem(IDC_STATIC_DIA_NAME)->SetWindowText(L"系统设置");
		m_dlgSystemSetting->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_COUNTER)			
	{
		GetDlgItem(IDC_STATIC_DIA_NAME)->SetWindowText(L"打印计数");
		m_dlgCounter->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_CLASS_SETTING)			
	{
		GetDlgItem(IDC_STATIC_DIA_NAME)->SetWindowText(L"班次设定");
		m_dlgClassSetting->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_DIA_PRINTER_MANAGE)			
	{
		GetDlgItem(IDC_STATIC_DIA_NAME)->SetWindowText(L"设备管理");
		m_dlgPrinterManage->ShowWindow(SW_SHOW);
	}	
}

void CBigCharPrinterView::OnBnClickedButPrintEdit()
{
	// TODO: 在此添加控件通知处理程序代码

	ShowDialogByID(IDD_DIA_PRINT_EDIT);
}

void CBigCharPrinterView::OnBnClickedButPrintParam()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowDialogByID(IDD_DIA_PRINT_PARAM);
}

void CBigCharPrinterView::OnBnClickedButIcon()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowDialogByID(IDD_DIA_CUSTOM_ICON);
}

void CBigCharPrinterView::OnBnClickedButSystem()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowDialogByID(IDD_DIA_SYSTEM_SETTING);
}

void CBigCharPrinterView::OnBnClickedButClean()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowDialogByID(IDD_DIA_MOUTH_CLEAN);
}

void CBigCharPrinterView::OnBnClickedButPrintControl()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowDialogByID(IDD_DIA_PRINT_CONTROL);
}

void CBigCharPrinterView::OnBnClickedButCounter()
{
	// TODO: 在此添加控件通知处理程序代码
	 ShowDialogByID(IDD_DIA_COUNTER);
}

void CBigCharPrinterView::OnBnClickedButClassSetting()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowDialogByID(IDD_DIA_CLASS_SETTING);
}

void CBigCharPrinterView::OnBnClickedButPrinterManage()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowDialogByID(IDD_DIA_PRINTER_MANAGE);
}
