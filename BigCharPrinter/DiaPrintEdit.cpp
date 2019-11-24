// DiaPrintEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaPrintEdit.h"
#include "afxdialogex.h"


// CDiaPrintEdit 对话框

IMPLEMENT_DYNAMIC(CDiaPrintEdit, CDialogEx)

CDiaPrintEdit::CDiaPrintEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaPrintEdit::IDD, pParent)
{

}

CDiaPrintEdit::~CDiaPrintEdit()
{
}

void CDiaPrintEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaPrintEdit, CDialogEx)
END_MESSAGE_MAP()


// CDiaPrintEdit 消息处理程序
