// DiaPrinterManage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaPrinterManage.h"
#include "afxdialogex.h"


// CDiaPrinterManage �Ի���

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


// CDiaPrinterManage ��Ϣ�������
