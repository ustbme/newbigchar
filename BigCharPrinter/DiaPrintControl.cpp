// DiaPrintControl.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaPrintControl.h"
#include "afxdialogex.h"


// CDiaPrintControl 对话框

IMPLEMENT_DYNAMIC(CDiaPrintControl, CDialogEx)

CDiaPrintControl::CDiaPrintControl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaPrintControl::IDD, pParent)
{

}

CDiaPrintControl::~CDiaPrintControl()
{
}

void CDiaPrintControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUT_OPEN_FILE, m_ButOpenFile);
}


BEGIN_MESSAGE_MAP(CDiaPrintControl, CDialogEx)
	ON_BN_CLICKED(IDC_BUT_OPEN_FILE, &CDiaPrintControl::OnBnClickedButOpenFile)
END_MESSAGE_MAP()


// CDiaPrintControl 消息处理程序


void CDiaPrintControl::OnBnClickedButOpenFile()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CDiaPrintControl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_ButOpenFile.SetBitmaps(IDB_BITMAP1,RGB(255,255,255),IDB_BITMAP1,RGB(255,255,255));
	m_ButOpenFile.DrawTransparent(true);
	m_ButOpenFile.SetFlat(1);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
