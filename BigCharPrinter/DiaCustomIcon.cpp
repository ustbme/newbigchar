// DiaCustomIcon.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaCustomIcon.h"
#include "afxdialogex.h"


// CDiaCustomIcon 对话框

IMPLEMENT_DYNAMIC(CDiaCustomIcon, CDialogEx)

CDiaCustomIcon::CDiaCustomIcon(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaCustomIcon::IDD, pParent)
{

}

CDiaCustomIcon::~CDiaCustomIcon()
{
}

void CDiaCustomIcon::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaCustomIcon, CDialogEx)
END_MESSAGE_MAP()


// CDiaCustomIcon 消息处理程序
