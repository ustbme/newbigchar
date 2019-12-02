// DiaPrinterManage.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaPrinterManage.h"
#include "afxdialogex.h"


// CDiaPrinterManage 对话框

IMPLEMENT_DYNAMIC(CDiaPrinterManage, CDialogEx)

CDiaPrinterManage::CDiaPrinterManage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaPrinterManage::IDD, pParent)
{

}

CDiaPrinterManage::~CDiaPrinterManage()
{
}

void CDiaPrinterManage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaPrinterManage, CDialogEx)
END_MESSAGE_MAP()


// CDiaPrinterManage 消息处理程序
