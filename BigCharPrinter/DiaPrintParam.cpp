// DiaPrintParam.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaPrintParam.h"
#include "afxdialogex.h"


// CDiaPrintParam 对话框

IMPLEMENT_DYNAMIC(CDiaPrintParam, CDialogEx)

CDiaPrintParam::CDiaPrintParam(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaPrintParam::IDD, pParent)
{

}

CDiaPrintParam::~CDiaPrintParam()
{
}

void CDiaPrintParam::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaPrintParam, CDialogEx)
END_MESSAGE_MAP()


// CDiaPrintParam 消息处理程序
