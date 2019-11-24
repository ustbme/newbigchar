// DiaSystemSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaSystemSetting.h"
#include "afxdialogex.h"


// CDiaSystemSetting 对话框

IMPLEMENT_DYNAMIC(CDiaSystemSetting, CDialogEx)

CDiaSystemSetting::CDiaSystemSetting(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaSystemSetting::IDD, pParent)
{

}

CDiaSystemSetting::~CDiaSystemSetting()
{
}

void CDiaSystemSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaSystemSetting, CDialogEx)
END_MESSAGE_MAP()


// CDiaSystemSetting 消息处理程序
